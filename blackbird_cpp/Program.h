typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

typedef std::vector<std::vector<double>> floatmat;
typedef std::vector<double> floatvec;

typedef std::vector<std::vector<int>> intmat;
typedef std::vector<int> intvec;


enum class Gate {Coherent, Interferometer, MeasureIntensity};

class Operation {
    public:
        Gate gate;
        intvec modes;
};


class Coherent : public Operation {
    public:
        double a;
        double p;

        Coherent(double displacement, double phase, intvec m) {
            gate = Gate::Coherent;
            a = displacement;
            p = phase;

            // put input validation here
            int mode_size = static_cast<int>(m.size());

            if (mode_size != 1) {
                throw std::invalid_argument("Coherent gate only acts on one mode");
            }
            modes = m;
        };
};


class Interferometer : public Operation {
    public:
        complexmat U;

        Interferometer(complexmat unitary, intvec m) {
            gate = Gate::Interferometer;
            U = unitary;

            // put input validation here
            int U_rows = static_cast<int>(U.size());
            int U_cols = static_cast<int>(U[0].size());
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
    public:
        complexmat U;

        MeasureIntensity(intvec m) {
            gate = Gate::MeasureIntensity;

            // put input validation here
            int mode_size = static_cast<int>(m.size());

            if (mode_size != 1) {
                throw std::invalid_argument("MeasureIntensity operation only acts on one mode");
            }
            modes = m;
        };
};



enum class Device {Chip0};


class Program {
    public:
        Device name;
        std::vector<Operation*> operations;
};


class Chip0 : public Program {
    public:
        Device name = Device::Chip0;
        int shots = 1;

        Chip0(Program dev) {};
        Chip0(int s=1) {
            shots = s;
        }
};
