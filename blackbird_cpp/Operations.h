class Operation {
    public:
        std::string name = "sadasdsa";
        std::vector<std::vector<int>> modes;
};

class Coherent : public Operation {
    public:
        std::string name = "Coherent";
        double alpha_mag;
        double alpha_phase;
};

class Interferometer : public Operation {
    public:
        std::string name = "Interferometer";
        std::vector<std::vector<std::complex<double>>> U;
};
