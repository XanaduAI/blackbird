
#include <unordered_map>

typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

typedef std::vector<std::vector<double>> floatmat;
typedef std::vector<double> floatvec;

typedef std::vector<std::vector<int>> intmat;
typedef std::vector<int> intvec;


enum class Device {Chip0};
enum class Gate {Coherent, BSgate, Rgate, Dgate, Xgate, Zgate, Sgate,
    Pgate, Vgate, S2gate, CXgate, CZgate, CKgate, Interferometer, MeasureIntensity};
enum class ParDomain {None, Int, Float, Complex, String, Bool, Array};

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

        std::complex<double> c1;

        complexmat U1;

        void print_zero_param_op() {
            std::cout << name << "() | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T>
        void print_one_param_op(T p1) {
            std::cout << name << "(" << p1 << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T, typename S>
        void print_two_param_op(T p1, S p2) {
            std::cout << name << "(" << p1 << ", " << p2 << ") | ";
            for (auto j : modes) {
                std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        };

        template <typename T>
        void print_array_param_op(T p1) {
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
};

class Xgate : public Operation {
    // X displacement gate
    public:
        Xgate(complexvec x, intvec m) {
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
    // Squeezing gate
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
};

class Pgate : public Operation {
    // Quadratic shift gate
    public:
        Pgate(complexvec s, intvec m) {
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
// Multimode gate
// ==================================



class BSgate : public Operation {
    // Beamsplitter
    public:
        BSgate(complexvec theta_phi, intvec m) {
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


class Interferometer : public Operation {
    // Interferometer
    public:
        Interferometer(complexmat unitary, intvec m) {
            gate = Gate::Interferometer;
            name = "Interferometer";
            num_params = 1;
            num_modes = 0;
            domain = ParDomain::Array;

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


class MeasureIntensity : public Operation {
    // Mean photon number measurement
    public:
        MeasureIntensity(intvec m) {
            gate = Gate::MeasureIntensity;
            name = "MeasureIntensity";
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
                    i->print_zero_param_op();
                }
                else if (i->num_params == 1) {
                    if (i->domain == ParDomain::Float) {
                        i->print_one_param_op(i->f1);
                    }
                    else if (i->domain == ParDomain::Int) {
                        i->print_one_param_op(i->i1);
                    }
                    else if (i->domain == ParDomain::Complex) {
                        i->print_one_param_op(i->c1);
                    }
                    else if (i->domain == ParDomain::Array) {
                        i->print_array_param_op(i->U1);
                    }
                }
                else if (i->num_params == 2) {
                    i->print_two_param_op(i->f1, i->f2);
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
