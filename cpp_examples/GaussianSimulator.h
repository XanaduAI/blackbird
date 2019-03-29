#include <iostream>
#include <complex>

#include "Blackbird.h"

namespace gaussian {
    typedef std::vector<int> intvec;

    typedef std::vector<double> floatvec;
    typedef std::vector<std::vector<double>> floatmat;

    typedef std::vector<std::vector<std::complex<double>>> complexmat;

    // Matrix operations
    float trace(floatmat &A);
    floatmat transpose(floatmat &A);
    float dot(floatvec &A, floatvec &B);
    floatvec matmult(floatmat &A, floatvec &B);
    floatmat matmult(floatmat &A, floatmat &B);


    class GaussianSimulator {
    private:
        floatmat expand(floatmat &A, int &n);
        floatmat expand(floatmat &A, intvec &n);
    public:
        int modes;
        int shots;
        float hbar;
        std::vector<blackbird::Operation*> queue;

        floatvec means;
        floatmat cov;
        void init(blackbird::Program* program);

        void reset();
        void reset(intvec &n);
        void reset(int &n);

        void symplectic(floatmat &S);

        void thermal(double &nbar, int &n);
        void rotation(double &phi, int &n);
        void displacement(std::complex<double> &alpha, int &n);
        void squeezing(double &r, double &phi, int &n);
        void quadratic_phase(double &s, int &n);

        void beamsplitter(double &theta, double &phi, intvec &n);
        void two_mode_squeezing(double &r, double &phi, intvec &n);
        void controlled_addition(double &s, intvec &n);
        void controlled_phase(double &s, intvec &n);

        void interferometer(complexmat &U, intvec &n);

        float mean_photon(int &n);

        floatvec apply();
    };
}

