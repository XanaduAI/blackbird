
#include <unordered_map>

typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

typedef std::vector<std::vector<double>> floatmat;
typedef std::vector<double> floatvec;

typedef std::vector<std::vector<int>> intmat;
typedef std::vector<int> intvec;


enum class Device {Chip0, Gaussian, Fock};

enum class Gate {
    // State preparations
    Vacuum, Coherent, Squeezed, Thermal, Fock, Catstate,
    // one mode gates
    Rgate, Dgate, Xgate, Zgate, Sgate, Pgate, Vgate,
    // two mode gates
    BSgate, S2gate, CXgate, CZgate, CKgate,
    // channels
    LossChannel, ThermalLossChannel,
    // decompositions
    Interferometer, GaussianTransform, Gaussian,
    // measurements
    MeasureFock, MeasureHomodyne, MeasureHeterodyne};

enum class ParDomain {None, Int, Float, Complex, String, Bool, ArrayFloat, ArrayComplex};

//================================
// Operation definitions
//================================

class Operation {
    // Base operation class
    public:
        Gate gate;
        intvec modes;

        std::string name;
        int num_params;
        ParDomain domain;
        int num_modes;

        int i1;

        double f1;
        double f2;
        double f3;

        std::complex<double> c1;

        complexmat U1;

        floatmat S1;
        floatmat S2;

        void print_op() {
            std::cout << name << "() | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T>
        void print_op(T p1) {
            std::cout << name << "(" << p1 << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T, typename S>
        void print_op(T p1, S p2) {
            std::cout << name << "(" << p1 << ", " << p2 << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T, typename S, typename O>
        void print_op(T p1, S p2, O p3) {
            std::cout << name << "(" << p1 << ", " << p2 << ", " << p3 << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T>
        void print_array_op(T p1) {
            std::cout << name << "(" << std::endl;
            for (auto j : p1) {
                for (auto k : j) {
                    std::cout << k << ',' << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T, typename S>
        void print_array_op(T p1, S p2) {
            std::cout << name << "(" << std::endl;
            for (auto j : p1) {
                for (auto k : j) {
                    std::cout << k << ',' << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << ", " << std::endl;
            for (auto j : p2) {
                for (auto k : j) {
                    std::cout << k << ',' << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        void check_num_args(int args_size) {
            if (args_size != num_params) {
                std::string np = std::to_string(num_params);
                std::string as = std::to_string(args_size);
                throw std::invalid_argument(name+" is a "+np+" parameter operation, but "
                    +as+" parameters were given.");
            }
        };

        void check_num_modes(int mode_size) {
            if (mode_size != num_modes) {
                std::string nm = std::to_string(num_modes);
                std::string ms = std::to_string(mode_size);
                throw std::invalid_argument(name+" is a "+nm+" mode operation, but "
                    +ms+" modes were given.");
            }
        };
};


//================================
// State preparation
//================================

class Vacuum : public Operation {
    // Vacuum state
    public:
        Vacuum(intvec m) {
            gate = Gate::Vacuum;
            name = "Vacuum";
            num_params = 0;
            num_modes = 1;
            domain = ParDomain::None;

            // put input validation here
            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class Coherent : public Operation {
    // Coherent state preparation
    public:
        Coherent(floatvec displacement_phase, intvec m) {
            gate = Gate::Coherent;
            name = "Coherent";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = displacement_phase[0];
            f2 = displacement_phase[1];

            // put input validation here
            int args_size = static_cast<int>(displacement_phase.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Coherent(complexvec alpha, intvec m) {
            gate = Gate::Coherent;
            name = "Coherent";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = std::abs(alpha[0]);
            f2 = std::arg(alpha[0]);

            // put input validation here
            int args_size = static_cast<int>(alpha.size())+1;
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
        Coherent(intvec alpha, intvec m) {
            throw std::invalid_argument("Coherent must have real arguments");
        };
};


class Squeezed : public Operation {
    // Squeezed state
    public:
        Squeezed(floatvec r_phase, intvec m) {
            gate = Gate::Squeezed;
            name = "Squeezed";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            if (r_phase.size() == 1) {
                r_phase.push_back(0);
            }
            f1 = r_phase[0];
            f2 = r_phase[1];

            // put input validation here
            int args_size = static_cast<int>(r_phase.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Squeezed(complexvec alpha, intvec m) {
            throw std::invalid_argument("Squeezed must have real arguments");
        };
        Squeezed(intvec alpha, intvec m) {
            throw std::invalid_argument("Squeezed must have real arguments");
        };
};


class Thermal : public Operation {
    // Thermal state
    public:
        Thermal(floatvec nbar, intvec m) {
            gate = Gate::Thermal;
            name = "Thermal";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = nbar[0];

            // put input validation here
            if (f1 < 0) {
                throw std::invalid_argument("Thermal state: cannot have negative thermal population.");
            }
            int args_size = static_cast<int>(nbar.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Thermal(complexvec nbar, intvec m) {
            throw std::invalid_argument("Thermal must have real arguments");
        };
        Thermal(intvec nbar, intvec m) {
            throw std::invalid_argument("Thermal must have real arguments");
        };
};


class Fock : public Operation {
    // Fock state
    public:
        Fock(intvec n, intvec m) {
            gate = Gate::Fock;
            name = "Fock";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Int;

            i1 = n[0];

            // put input validation here
            if (i1 < 0) {
                throw std::invalid_argument("Fock state: cannot have negative Fock state.");
            }
            int args_size = static_cast<int>(n.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Fock(floatvec n, intvec m) {
            throw std::invalid_argument("Fock must have integer arguments");
        };

        Fock(complexvec n, intvec m) {
            throw std::invalid_argument("Fock must have integer arguments");
        };
};


class Catstate : public Operation {
    // Cat state
    public:
        Catstate(complexvec alpha, intvec m, float parity=0.) {
            gate = Gate::Catstate;
            name = "Catstate";
            num_params = 3;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = std::abs(alpha[0]);
            f2 = std::arg(alpha[0]);
            f3 = parity;

            // put input validation here
            int args_size = static_cast<int>(alpha.size())+2;
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Catstate(floatvec alpha, intvec m) {
            throw std::invalid_argument("Catstate alpha parameter must be complex");
        };
        Catstate(intvec alpha, intvec m) {
            throw std::invalid_argument("Catstate alpha parameter must be complex");
        };
};


//================================
// Single mode gates
//================================

class Rgate : public Operation {
    // Rotation gate
    public:
        Rgate(complexvec phi, intvec m) {
            throw std::invalid_argument("Rgate must have real arguments");
        };
        Rgate(intvec phi, intvec m) {
            throw std::invalid_argument("Rgate must have real arguments");
        };
        Rgate(floatvec phi, intvec m) {
            gate = Gate::Rgate;
            name = "Rgate";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = phi[0];

            // put input validation here
            int args_size = static_cast<int>(phi.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class Dgate : public Operation {
    // Rotation gate
    public:
        Dgate(floatvec displacement_phase, intvec m) {
            gate = Gate::Dgate;
            name = "Dgate";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = displacement_phase[0];
            f2 = displacement_phase[1];

            // put input validation here
            int args_size = static_cast<int>(displacement_phase.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Dgate(complexvec alpha, intvec m) {
            gate = Gate::Dgate;
            name = "Dgate";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = std::abs(alpha[0]);
            f2 = std::arg(alpha[0]);

            // put input validation here
            int args_size = static_cast<int>(alpha.size())+1;
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
        Dgate(intvec x, intvec m) {
            throw std::invalid_argument("Dgate must have real arguments");
        };
};

class Xgate : public Operation {
    // X displacement gate
    public:
        Xgate(complexvec x, intvec m) {
            throw std::invalid_argument("Xgate must have real arguments");
        };
        Xgate(intvec x, intvec m) {
            throw std::invalid_argument("Xgate must have real arguments");
        };
        Xgate(floatvec x, intvec m) {
            gate = Gate::Xgate;
            name = "Xgate";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = x[0];

            // put input validation here
            int args_size = static_cast<int>(x.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};

class Zgate : public Operation {
    // Z displacement gate
    public:
        Zgate(complexvec z, intvec m) {
            throw std::invalid_argument("Zgate must have real arguments");
        };
        Zgate(intvec z, intvec m) {
            throw std::invalid_argument("Zgate must have real arguments");
        };
        Zgate(floatvec z, intvec m) {
            gate = Gate::Zgate;
            name = "Zgate";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = z[0];

            // put input validation here
            int args_size = static_cast<int>(z.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};

class Sgate : public Operation {
    // Squeezed gate
    public:
        Sgate(floatvec r_phase, intvec m) {
            gate = Gate::Sgate;
            name = "Sgate";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            if (r_phase.size() == 1) {
                r_phase.push_back(0);
            }
            f1 = r_phase[0];
            f2 = r_phase[1];

            // put input validation here
            int args_size = static_cast<int>(r_phase.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        Sgate(complexvec alpha, intvec m) {
            throw std::invalid_argument("Sgate must have real arguments");
        };
        Sgate(intvec alpha, intvec m) {
            throw std::invalid_argument("Sgate must have real arguments");
        };
};

class Pgate : public Operation {
    // Quadratic shift gate
    public:
        Pgate(complexvec s, intvec m) {
            throw std::invalid_argument("Pgate must have real arguments");
        };
        Pgate(intvec s, intvec m) {
            throw std::invalid_argument("Pgate must have real arguments");
        };
        Pgate(floatvec s, intvec m) {
            gate = Gate::Pgate;
            name = "Pgate";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = s[0];

            // put input validation here
            int args_size = static_cast<int>(s.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class Vgate : public Operation {
    // Cubic shift gate
    public:
        Vgate(complexvec s, intvec m) {
            throw std::invalid_argument("Vgate must have real arguments");
        };
        Vgate(intvec s, intvec m) {
            throw std::invalid_argument("Vgate must have real arguments");
        };
        Vgate(floatvec s, intvec m) {
            gate = Gate::Vgate;
            name = "Vgate";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = s[0];

            // put input validation here
            int args_size = static_cast<int>(s.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


// ==================================
// Multimode gates
// ==================================

class BSgate : public Operation {
    // Beamsplitter
    public:
        BSgate(complexvec theta_phi, intvec m) {
            throw std::invalid_argument("BSgate must have real arguments");
        };
        BSgate(intvec theta_phi, intvec m) {
            throw std::invalid_argument("BSgate must have real arguments");
        };
        BSgate(floatvec theta_phi, intvec m) {
            gate = Gate::BSgate;
            name = "BSgate";
            num_params = 2;
            num_modes = 2;
            domain = ParDomain::Float;

            f1 = theta_phi[0];
            f2 = theta_phi[1];

            // put input validation here
            int args_size = static_cast<int>(theta_phi.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class S2gate : public Operation {
    // Beamsplitter
    public:
        S2gate(complexvec r_phi, intvec m) {
            throw std::invalid_argument("S2gate must have real arguments");
        };
        S2gate(intvec r_phi, intvec m) {
            throw std::invalid_argument("S2gate must have real arguments");
        };
        S2gate(floatvec r_phi, intvec m) {
            gate = Gate::S2gate;
            name = "S2gate";
            num_params = 2;
            num_modes = 2;
            domain = ParDomain::Float;

            int args_size = static_cast<int>(r_phi.size());

            if (r_phi.size() == 1) {
                r_phi.push_back(0);
                args_size = 2;
            }

            f1 = r_phi[0];
            f2 = r_phi[1];

            // put input validation here
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class CXgate : public Operation {
    // Beamsplitter
    public:
        CXgate(complexvec s, intvec m) {
            throw std::invalid_argument("CXgate must have real arguments");
        };
        CXgate(intvec s, intvec m) {
            throw std::invalid_argument("CXgate must have real arguments");
        };
        CXgate(floatvec s, intvec m) {
            gate = Gate::CXgate;
            name = "CXgate";
            num_params = 1;
            num_modes = 2;
            domain = ParDomain::Float;

            f1 = s[0];

            // put input validation here
            int args_size = static_cast<int>(s.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class CZgate : public Operation {
    // Beamsplitter
    public:
        CZgate(complexvec s, intvec m) {
            throw std::invalid_argument("CZgate must have real arguments");
        };
        CZgate(intvec s, intvec m) {
            throw std::invalid_argument("CZgate must have real arguments");
        };
        CZgate(floatvec s, intvec m) {
            gate = Gate::CZgate;
            name = "CZgate";
            num_params = 1;
            num_modes = 2;
            domain = ParDomain::Float;

            f1 = s[0];

            // put input validation here
            int args_size = static_cast<int>(s.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class CKgate : public Operation {
    // Beamsplitter
    public:
        CKgate(complexvec s, intvec m) {
            throw std::invalid_argument("CKgate must have real arguments");
        };
        CKgate(intvec s, intvec m) {
            throw std::invalid_argument("CKgate must have real arguments");
        };
        CKgate(floatvec s, intvec m) {
            gate = Gate::CKgate;
            name = "CKgate";
            num_params = 1;
            num_modes = 2;
            domain = ParDomain::Float;

            f1 = s[0];

            // put input validation here
            int args_size = static_cast<int>(s.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};

// ==================================
// Loss channels
// ==================================

class LossChannel : public Operation {
    // loss channel
    public:
        LossChannel(complexvec phi, intvec m) {
            throw std::invalid_argument("LossChannel must have real arguments");
        };
        LossChannel(intvec phi, intvec m) {
            throw std::invalid_argument("LossChannel must have real arguments");
        };
        LossChannel(floatvec T, intvec m) {
            gate = Gate::LossChannel;
            name = "LossChannel";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = T[0];

            // put input validation here
            if (0 <= f1 <= 1) {
                throw std::invalid_argument("LossChannel: loss parameter must be between 0 and 1");
            }
            int args_size = static_cast<int>(T.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};


class ThermalLossChannel : public Operation {
    // loss channel
    public:
        ThermalLossChannel(complexvec phi, intvec m) {
            throw std::invalid_argument("ThermalLossChannel must have real arguments");
        };
        ThermalLossChannel(intvec phi, intvec m) {
            throw std::invalid_argument("ThermalLossChannel must have real arguments");
        };
        ThermalLossChannel(floatvec T, intvec m) {
            gate = Gate::ThermalLossChannel;
            name = "ThermalLossChannel";
            num_params = 2;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = T[0];
            f2 = T[1];

            // put input validation here
            if (0 <= f1 <= 1) {
                throw std::invalid_argument("ThermalLossChannel: loss parameter must be between 0 and 1");
            }
            if (f2 < 0) {
                throw std::invalid_argument("ThermalLossChannel: thermal population must be positive");
            }
            int args_size = static_cast<int>(T.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};

// ==================================
// Decomposition gates
// ==================================

class Interferometer : public Operation {
    // Interferometer
    public:
        Interferometer(complexmat unitary, intvec m) {
            gate = Gate::Interferometer;
            name = "Interferometer";
            num_params = 1;
            num_modes = 0;
            domain = ParDomain::ArrayComplex;

            U1 = unitary;

            // put input validation here
            int U_rows = static_cast<int>(U1.size());
            int U_cols = static_cast<int>(U1[0].size());
            int mode_size = static_cast<int>(m.size());

            if (U_rows != U_cols) {
                throw std::invalid_argument("Interferometer unitary matrix should be square");
            }
            else if (U_rows != mode_size) {
                throw std::invalid_argument("Interferometer unitary matrix must have the same size as the number of modes");
            }
            modes = m;
        };
};


class GaussianTransform : public Operation {
    // Symplectic transformation
    public:
        GaussianTransform(floatmat symplectic, intvec m) {
            gate = Gate::GaussianTransform;
            name = "GaussianTransform";
            num_params = 1;
            num_modes = 0;
            domain = ParDomain::ArrayFloat;

            S1 = symplectic;

            // put input validation here
            int rows = static_cast<int>(S1.size());
            int cols = static_cast<int>(S1[0].size());
            int mode_size = static_cast<int>(m.size());

            if (rows != cols) {
                throw std::invalid_argument("GaussianTransform symplectic matrix should be square");
            }
            else if (rows != 2*mode_size) {
                throw std::invalid_argument("GaussianTransform symplectic matrix should have size double the number of modes");
            }
            modes = m;
        };
};


class Gaussian : public Operation {
    // Gaussian state preparation
    public:
        Gaussian(floatmat cov, floatmat means, intvec m) {
            gate = Gate::Gaussian;
            name = "Gaussian";
            num_params = 2;
            num_modes = 0;
            domain = ParDomain::ArrayFloat;

            S1 = cov;
            S2 = means;

            // put input validation here
            int rows = static_cast<int>(S1.size());
            int cols = static_cast<int>(S1[0].size());
            int mode_size = static_cast<int>(m.size());

            if (rows != cols) {
                throw std::invalid_argument("Gaussian: covariance matrix should be square");
            }
            else if (rows != 2*mode_size) {
                throw std::invalid_argument("Gaussian: covariance matrix should have size double the number of modes");
            }

            rows = static_cast<int>(S2.size());
            cols = static_cast<int>(S2[0].size());

            if (rows != 1) {
                throw std::invalid_argument("Gaussian: means vector should only have 1 row");
            }
            else if (cols != 2*mode_size) {
                throw std::invalid_argument("Gaussian: means vector should have size double the number of modes");
            }

            modes = m;
        };

        Gaussian(floatmat cov, intvec m) {
            gate = Gate::Gaussian;
            name = "Gaussian";
            num_params = 2;
            num_modes = 0;
            domain = ParDomain::ArrayFloat;

            S1 = cov;

            // put input validation here
            int rows = static_cast<int>(S1.size());
            int cols = static_cast<int>(S1[0].size());
            int mode_size = static_cast<int>(m.size());

            floatmat means_vector(1, floatvec(2*mode_size, 0.0));
            S2 = means_vector;

            if (rows != cols) {
                throw std::invalid_argument("Gaussian: covariance matrix should be square");
            }
            else if (rows != 2*mode_size) {
                throw std::invalid_argument("Gaussian: covariance matrix should have size double the number of modes");
            }

            modes = m;
        };
};

// ==================================
// Measurements
// ==================================

class MeasureFock : public Operation {
    // Photon number measurement
    public:
        MeasureFock(intvec m) {
            gate = Gate::MeasureFock;
            name = "MeasureFock";
            num_params = 0;
            num_modes = 1;
            domain = ParDomain::None;

            // put input validation here
            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};

class MeasureHomodyne : public Operation {
    // Homodyne measurement
    public:
        MeasureHomodyne(intvec m) {
            // By default, if no quadrature angle is provided,
            // assume the measurement is in X
            gate = Gate::MeasureHomodyne;
            name = "MeasureHomodyne";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = 0.0;

            // put input validation here
            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        MeasureHomodyne(floatvec phi, intvec m) {
            gate = Gate::MeasureHomodyne;
            name = "MeasureHomodyne";
            num_params = 1;
            num_modes = 1;
            domain = ParDomain::Float;

            f1 = phi[0];

            // put input validation here
            int args_size = static_cast<int>(phi.size());
            check_num_args(args_size);

            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };

        MeasureHomodyne(complexvec phi, intvec m) {
            throw std::invalid_argument("MeasureHomodyne must have real arguments");
        };
        MeasureHomodyne(intvec phi, intvec m) {
            throw std::invalid_argument("MeasureHomodyne must have real arguments");
        };
};

class MeasureHeterodyne : public Operation {
    // Heterodyne measurement
    public:
        MeasureHeterodyne(intvec m) {
            gate = Gate::MeasureHeterodyne;
            name = "MeasureHeterodyne";
            num_params = 0;
            num_modes = 1;
            domain = ParDomain::None;

            // put input validation here
            int mode_size = static_cast<int>(m.size());
            check_num_modes(mode_size);
            modes = m;
        };
};

//================================
// Device definitions
//================================

class Program {
    public:
        Device name;
        std::vector<Operation*> operations;

        virtual void print_device_info() {};

        void print_operations() {
            for (auto i : operations) {
                if (i->num_params == 0) {
                    i->print_op();
                }
                else if (i->num_params == 1) {
                    if (i->domain == ParDomain::Float) {
                        i->print_op(i->f1);
                    }
                    else if (i->domain == ParDomain::Int) {
                        i->print_op(i->i1);
                    }
                    else if (i->domain == ParDomain::Complex) {
                        i->print_op(i->c1);
                    }
                    else if (i->domain == ParDomain::ArrayComplex) {
                        i->print_array_op(i->U1);
                    }
                    else if (i->domain == ParDomain::ArrayFloat) {
                        i->print_array_op(i->S1);
                    }
                }
                else if (i->num_params == 2) {
                    if (i->domain == ParDomain::Float) {
                        i->print_op(i->f1, i->f2);
                    }
                    else if (i->domain == ParDomain::ArrayFloat) {
                        i->print_array_op(i->S1, i->S2);
                    }
                }
                else if (i->num_params == 3) {
                    i->print_op(i->f1, i->f2, i->f3);
                }
            }
        };
};


class Chip0 : public Program {
    public:
        Device name = Device::Chip0;
        int shots = 1;

        Chip0(Program dev) {};
        Chip0(int s=1) {
            shots = s;
        };

        void print_device_info() {
            std::cout << "Device: Chip0" << std::endl;
            std::cout << "Shots: " << shots << std::endl;
        };
};


class GaussianSimulator : public Program {
    public:
        Device name = Device::Gaussian;
        int ns;
        int shots = 1;
        double hb = 2.0;

        GaussianSimulator() {};
        GaussianSimulator(Program dev) {};
        GaussianSimulator(int num_subsystems, int s=0, double hbar=2) {
            ns = num_subsystems;
            shots = s;
            hb = hbar;
        };

        void print_device_info() {
            std::cout << "Device: Gaussian (simulator)" << std::endl;
            std::cout << "Number of subsystems: " << ns << std::endl;
            std::cout << "Shots: " << shots << std::endl;
            std::cout << "hbar: " << hb << std::endl;
        };
};


class FockSimulator : public Program {
    public:
        Device name = Device::Fock;
        int ns;
        int cutoff;
        int shots = 1;
        double hb = 2.0;

        FockSimulator() {};
        FockSimulator(Program dev) {};
        FockSimulator(int num_subsystems, int cutoff_dim, int s=0, double hbar=2) {
            cutoff = cutoff_dim;
            ns = num_subsystems;
            shots = s;
            hb = hbar;
        };

        void print_device_info() {
            std::cout << "Device: Fock (simulator)" << std::endl;
            std::cout << "Number of subsystems: " << ns << std::endl;
            std::cout << "Cutoff dimension: " << cutoff << std::endl;
            std::cout << "Shots: " << shots << std::endl;
            std::cout << "hbar: " << hb << std::endl;
        };
};