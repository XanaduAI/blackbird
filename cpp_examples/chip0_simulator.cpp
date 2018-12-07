#include <iostream>
#include <complex>
#include <random>
#include <iomanip>

#include "Blackbird.h"

typedef std::vector<double> floatvec;
typedef std::vector<std::vector<double>> floatmat;


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


floatmat coherent_sampling(blackbird::Program* program, double hbar=2.0) {
    blackbird::Chip0* p = static_cast<blackbird::Chip0*>(program);
    // Perform the coherent sampling quantum algorithm
    const int modes = 4;
    const int shots = p->shots;

    floatvec means(2*modes, 0.0);
    floatmat cov(2*modes, floatvec(2*modes, 0.0));

    floatvec mean_photon(modes, 0.0);
    floatmat result(shots, floatvec(modes, 0.0));

    // initialise the vacuum state
    for (int i=0; i < 2*modes; i++) {
        cov[i][i] = hbar/2.0;
    }

    // go through the queue
    for (auto i : p->operations) {
        if (i->name == "Coherent") {
            std::complex<double> alpha = std::polar(i->f1, i->f2);
            int n = i->modes[0];

            std::cout << "Preparing coherent state with a=" << alpha
                << " in mode " << n << "..." << std::endl;

            means[n] = sqrt(2*hbar)*alpha.real();
            means[n+modes] = sqrt(2*hbar)*alpha.imag();
        }
        else if (i->name == "Interferometer") {
            floatmat S(2*modes, floatvec(2*modes, 0.0));
            for (int j=0; j < i->U1.size(); j++) {
                for (int k=0; k < i->U1[0].size(); k++) {
                    S[j][k] = i->U1[j][k].real();
                    S[j][k+modes] = -i->U1[j][k].imag();
                    S[j+modes][k] = i->U1[j][k].imag();
                    S[j+modes][k+modes] = i->U1[j][k].real();
                }
            }
            std::cout << "Applying interferometer..." << std::endl;
            means = matmult(S, means);
            floatmat ST = transpose(S);
            cov = matmult(cov, ST);
            cov = matmult(S, cov);
        }
        else if (i->name == "MeasureIntensity") {
            int n = i->modes[0];
            std::cout << "Measuring mean photon number of mode " << n << "..." << std::endl;
            // get reduced state
            floatmat V = {{cov[n][n], cov[n][n+modes]}, {cov[n+modes][n], cov[n+modes][n+modes]}};
            floatvec mu = {means[n], means[n+modes]};
            mean_photon[n] = (trace(V) + dot(mu, mu))/(2.0*hbar) - 0.5;
        }
    }

    // sample from normal distribution
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i=0; i < modes; i++) {
        std::normal_distribution<float> d(mean_photon[i], 1.0/mean_photon[i]);
        for (int j=0; j < shots; j++) {
            float sample = d(gen);
            result[j][i] = (sample >= 0.0) ? sample : 0.0;
        }
    }

    std::cout << std::endl;
    return result;
}


int main(int argc, const char* argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);

    blackbird::Program* program = blackbird::parse_blackbird(stream);

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

    floatmat result;

    // check if the device is Chip0
    if (program->name == blackbird::Device::Chip0) {
        result = coherent_sampling(program);
    }
    else {
        throw std::invalid_argument("This example simulator only works with device Chip0!");
    }

    std::cout << "Results         " << std::endl;
    std::cout << "==================" << std::endl;

    std::cout << std::fixed;
    std::cout << std::setprecision(5);

    for (floatmat::iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << "Shot " << it-result.begin() << ": ";
        for (auto j : *it) {
            std::cout << j << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
