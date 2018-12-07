#include <iostream>
#include <complex>
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


floatvec coherent_sampling(blackbird::Program* program, double hbar=2.0) {
    // Perform the coherent sampling quantum algorithm
    const int modes = 4;
    floatvec means(2*modes, 0.0);
    floatmat cov(2*modes, std::vector<double>(2*modes, 0.0));
    floatvec result(modes, 0.0);

    // initialise the vacuum state
    for (int i=0; i < 2*modes; i++) {
        cov[i][i] = hbar/2.0;
    }

    // go through the queue
    for (auto i : program->operations) {
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
            result[n] = (trace(V) + dot(mu, mu))/(2.0*hbar) - 0.5;
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
    std::cout << " Quantum program  " << std::endl;
    std::cout << "==================" << std::endl;
    program->print_operations();
    std::cout << std::endl;


    std::cout << "Running simulation" << std::endl;
    std::cout << "==================" << std::endl;

    floatvec result;

    // check if the device is Chip0
    if (program->name == blackbird::Device::Chip0) {
        result = coherent_sampling(program);
    }
    else {
        throw std::invalid_argument("This example simulator only works with device Chip0!");
    }

    std::cout << "  Results         " << std::endl;
    std::cout << "==================" << std::endl;
    for (auto i : result) {
        std::cout << i << std::endl;
    }

    return 0;
}
