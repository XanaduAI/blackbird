#include <random>
#include <iomanip>

#include "GaussianSimulator.h"

namespace gaussian {
    // Matrix operations

    float trace(floatmat &A) {
        // return the trace of a real matrix
        float result = 0.0;

        for (int i=0; i < A.size(); i++) {
            result += A[i][i];
        }
        return result;
    }


    floatmat transpose(floatmat &A) {
        // return the transpose of a real matrix
        floatmat C(A.size(), floatvec(A[0].size(), 0.0));

        for (int i=0; i < A.size(); i++) {
            for (int j=0; j < A[0].size(); j++) {
                C[i][j] = A[j][i];
            }
        }
        return C;
    }

    float dot(floatvec &A, floatvec &B) {
        // return the dot product of two real vectors
        float result = 0.0;

        for (int i=0; i < A.size(); i++) {
            result += A[i]*B[i];
        }
        return result;
    }

    floatvec matmult(floatmat &A, floatvec &B) {
        // matrix multiplication of a matrix and a vector
        floatvec C(B.size(), 0.0);

        for (int i=0; i < A.size(); i++) {
            for (int j=0; j < A[0].size(); j++) {
                C[i] += A[i][j]*B[j];
            }
        }
        return C;
    }

    floatmat matmult(floatmat &A, floatmat &B) {
        // matrix multiplication two real matrices
        floatmat C(A.size(), floatvec(B[0].size(), 0.0));

        for (int i=0; i < A.size(); i++) {
            for (int j=0; j < A[0].size(); j++) {
                for (int k=0; k < B[0].size(); k++) {
                    C[i][k] += A[i][j]*B[j][k];
                }
            }
        }
        return C;
    }

    floatmat GaussianSimulator::expand(floatmat &A, int &n) {
        floatmat S(2*modes, floatvec(2*modes, 0.0));
        for (int i=0; i < 2*modes; i++) {
            S[i][i] = 1.0;
        }

        S[n][n] = A[0][0];
        S[n][n+modes] = A[0][1];
        S[n+modes][n] = A[1][0];
        S[n+modes][n+modes] = A[1][1];

        return S;
    }

    floatmat GaussianSimulator::expand(floatmat &A, intvec &n) {
        floatmat S(2*modes, floatvec(2*modes, 0.0));
        for (int i=0; i < 2*modes; i++) {
            S[i][i] = 1.0;
        }

        int local_modes = n.size();

        for (int i=0; i < local_modes; i++) {
            S[n[i]][n[i]] = A[i][i];
            S[n[i]][n[i]+modes] = A[i][i+local_modes];
            S[n[i]+modes][n[i]] = A[i+local_modes][i];
            S[n[i]+modes][n[i]+modes] = A[i+local_modes][i+local_modes];
        }

        return S;
    }

    void GaussianSimulator::init(blackbird::Program* program) {
        if (program->name != blackbird::Device::Gaussian) {
            throw std::invalid_argument("Only supports the Gaussian simulator!");
        }
        blackbird::GaussianSimulator* p = static_cast<blackbird::GaussianSimulator*>(program);

        modes = p->ns;
        shots = p->shots;
        hbar = p->hb;
        queue = p->operations;

        floatvec m(2*modes, 0.0);
        means = m;

        floatmat c(2*modes, floatvec(2*modes, 0.0));
        cov = c;

        reset();
    }

    void GaussianSimulator::reset(int &n) {
        // initialise the vacuum state
        means[n] = 0.0;
        means[n+modes] = 0.0;

        cov[n][n] = hbar/2.0;
        cov[n][n+modes] = hbar/2.0;
        cov[n+modes][n] = hbar/2.0;
        cov[n+modes][n+modes] = hbar/2.0;
    }

    void GaussianSimulator::reset() {
        // initialise the vacuum state
        for (int i=0; i < modes; i++) {
            reset(i);
        }
    }

    void GaussianSimulator::reset(intvec &n) {
        // initialise the vacuum state
        for (auto m : n) {
            reset(m);
        }
    }

    void GaussianSimulator::symplectic(floatmat &S) {
        means = matmult(S, means);
        floatmat ST = transpose(S);
        cov = matmult(cov, ST);
        cov = matmult(S, cov);
    }

    void GaussianSimulator::thermal(double &nbar, int &n) {
        // initialise the vacuum state
        means[n] = 0.0;
        means[n+modes] = 0.0;

        cov[n][n] = (2.0*nbar+1.0)*hbar/2.0;
        cov[n][n+modes] = (2.0*nbar+1.0)*hbar/2.0;
        cov[n+modes][n] = (2.0*nbar+1.0)*hbar/2.0;
        cov[n+modes][n+modes] = (2.0*nbar+1.0)*hbar/2.0;
    }

    void GaussianSimulator::displacement(std::complex<double> &alpha, int &n) {
        means[n] = sqrt(2*hbar)*alpha.real();
        means[n+modes] = sqrt(2*hbar)*alpha.imag();
    }

    void GaussianSimulator::rotation(double &phi, int &n) {
        floatmat S1 = {{cos(phi), -sin(phi)}, {sin(phi), cos(phi)}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::squeezing(double &r, double &phi, int &n) {
        double cp = cos(phi);
        double sp = sin(phi);
        double ch = cosh(r);
        double sh = sinh(r);

        floatmat S1 = {{ch-cp*sh, -sp*sh}, {-sp*sh, ch+cp*sh}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::quadratic_phase(double &s, int &n) {
        floatmat S1 = {{1.0, 0.0}, {s, 1.0}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::beamsplitter(double &theta, double &phi, intvec &n) {
        double cp = cos(phi);
        double sp = sin(phi);
        double ct = cos(theta);
        double st = sin(theta);

        floatmat S1 ={{ct, -cp*st, 0.0, -st*sp},
                      {cp*st, ct, -st*sp, 0.0},
                      {0.0, st*sp, ct, -cp*st},
                      {st*sp, 0.0, cp*st, ct}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::two_mode_squeezing(double &r, double &phi, intvec &n) {
        double cp = cos(phi);
        double sp = sin(phi);
        double ch = cosh(r);
        double sh = sinh(r);

        floatmat S1 = {{ch, cp*sh, 0, sp*sh},
                      {cp*sh, ch, sp*sh, 0},
                      {0, sp*sh, ch, -cp*sh},
                      {sp*sh, 0, -cp*sh, ch}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::controlled_addition(double &s, intvec &n) {
        floatmat S1 = {{1.0, 0.0, 0.0, 0.0},
                       {s, 1.0, 0.0, 0.0},
                       {0.0, 0.0, 1.0, -s},
                       {0.0, 0.0, 0.0, 1.0}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::controlled_phase(double &s, intvec &n) {
        floatmat S1 = {{1.0, 0.0, 0.0, 0.0},
                       {0.0, 1.0, 0.0, 0.0},
                       {0.0,   s, 1.0, 0.0},
                       {  s, 0.0, 0.0, 1.0}};
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    void GaussianSimulator::interferometer(complexmat &U, intvec &n) {
        floatmat S1(2*n.size(), floatvec(2*n.size(), 0.0));

        for (int j=0; j < U.size(); j++) {
            for (int k=0; k < U.size(); k++) {
                S1[j][k] = U[j][k].real();
                S1[j][k+modes] = U[j][k].imag();
                S1[j+modes][k] = U[j][k].imag();
                S1[j+modes][k+modes] = U[j][k].real();
            }
        }
        floatmat S = expand(S1, n);
        symplectic(S);
    }

    float GaussianSimulator::mean_photon(int &n) {
        floatmat V = {{cov[n][n], cov[n][n+modes]}, {cov[n+modes][n], cov[n+modes][n+modes]}};
        floatvec mu = {means[n], means[n+modes]};
        return (trace(V) + dot(mu, mu))/(2.0*hbar) - 0.5;
    }

    floatvec GaussianSimulator::apply() {
        floatvec result;

        for (auto i : queue) {
            if (i->name == "Coherent") {
                std::complex<double> alpha = std::polar(i->f1, i->f2);
                int n = i->modes[0];
                reset(n);
                displacement(alpha, n);
            }
            else if (i->name == "Squeezed") {
                int n = i->modes[0];
                reset(n);
                squeezing(i->f1, i->f2, n);
            }
            else if (i->name == "Vacuum") {
                int n = i->modes[0];
                reset(n);
            }
            else if (i->name == "Thermal") {
                int n = i->modes[0];
                reset(n);
                thermal(i->f1, n);
            }
            else if (i->name == "Dgate") {
                std::complex<double> alpha = std::polar(i->f1, i->f2);
                displacement(alpha, i->modes[0]);
            }
            else if (i->name == "Xgate") {
                std::complex<double> alpha = (i->f1, 0.0)/sqrt(2*hbar);
                displacement(alpha, i->modes[0]);
            }
            else if (i->name == "Zgate") {
                std::complex<double> alpha = (0.0, i->f1)/sqrt(2*hbar);
                displacement(alpha, i->modes[0]);
            }
            else if (i->name == "Rgate") {
                rotation(i->f1, i->modes[0]);
            }
            else if (i->name == "Sgate") {
                squeezing(i->f1, i->f2, i->modes[0]);
            }
            else if (i->name == "Pgate") {
                quadratic_phase(i->f1, i->modes[0]);
            }
            else if (i->name == "BSgate") {
                beamsplitter(i->f1, i->f2, i->modes);
            }
            else if (i->name == "S2gate") {
                two_mode_squeezing(i->f1, i->f2, i->modes);
            }
            else if (i->name == "CXgate") {
                controlled_addition(i->f1, i->modes);
            }
            else if (i->name == "CZgate") {
                controlled_phase(i->f1, i->modes);
            }
            else if (i->name == "Interferometer") {
                interferometer(i->U1, i->modes);
            }
            else if (i->name == "GaussianTransform") {
                floatmat S = expand(i->S1, i->modes);
                symplectic(S);
            }
            else if (i->name == "Gaussian") {
                means = i->S2[0];
                cov = i->S1;
            }
            else if (i->name == "MeasureIntensity") {
                result.push_back(mean_photon(i->modes[0]));
            }
        }
        return result;
    }

}


int main(int argc, const char* argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);

    blackbird::Program* program = blackbird::parse(stream);

    // print device info
    std::cout << "Device information" << std::endl;
    std::cout << "==================" << std::endl;
    program->print_device_info();
    std::cout << std::endl;

    // print operations
    std::cout << "Quantum program  " << std::endl;
    std::cout << "==================" << std::endl;
    program->print_operations();
    std::cout << std::endl;


    std::cout << "Running simulation" << std::endl;
    std::cout << "==================" << std::endl;

    gaussian::GaussianSimulator sim;
    sim.init(program);
    floatvec result = sim.apply();

    std::cout << "Results         " << std::endl;
    std::cout << "==================" << std::endl;

    std::cout << std::fixed;
    std::cout << std::setprecision(5);

    for (auto i : result) {
        std::cout << i << std::endl;
    }

    return 0;
}