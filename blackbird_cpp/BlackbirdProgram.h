// Copyright 2019 Xanadu Quantum Technologies Inc.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <unordered_map>

typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

typedef std::vector<std::vector<double>> floatmat;
typedef std::vector<double> floatvec;

typedef std::vector<std::vector<int>> intmat;
typedef std::vector<int> intvec;

namespace blackbird {

    /**
    * The current available Blackbird devices.
    * Currently, `Chip0`, `Gaussian`, and `Fock` devices are defined.
    */
    enum class Device {
        /// a physical 4x4 sampling device with coherent state input
        Chip0,
        /// a full Gaussian simulator or device that supports all Gaussian operations
        Gaussian,
        /// a full Fock simulator or device that supports _all_ CV operations.
        Fock
    };

    /**
    * The current defined Blackbird quantum operation gate set.
    */
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
        MeasureFock, MeasureHomodyne, MeasureHeterodyne, MeasureIntensity};

    /**
    * The allowed domains of the blackbird quantum operation gate set
    */
    enum class ParDomain {
        /// gate accepts no parameters
        None,
        /// integer parameters
        Int,
        /// float parameters
        Float,
        /// complex parameters
        Complex,
        /// string parameters
        String,
        /// boolean parameters
        Bool,
        /// a real array parameter
        ArrayFloat,
        /// a complex array parameter
        ArrayComplex
    };

    //================================
    // Operation definitions
    //================================

    /**
     * The base class inherited by all quantum operations.
     * This defines public attributes common to all operations,
     * such as gate name, modes it acts on, number of parameters,
     * number of modes it acts on, as well as parameter details.
     *
     * It also defines some utility methods for printing out
     * gate information.
     */
    class Operation {
        public:
            /// gate type
            Gate gate;
            /// modes the gate applies to
            intvec modes;

            /// name of the gate
            std::string name;
            /// number of params gate accepts
            int num_params;
            /// the domain of the parameters
            ParDomain domain;
            /// number of modes the gate is allowed to act on
            int num_modes;

            /// integer paramter 1
            int i1;

            /// real parameter 1
            double f1;
            /// real parameter 2
            double f2;
            /// real parameter 3
            double f3;

            /// compelx parameter 1
            std::complex<double> c1;

            /// complex matrix parameter 1
            complexmat U1;

            /// real matrix parameter 1
            floatmat S1;
            /// real matrix parameter 2
            floatmat S2;

            /// Print operation information in Blackbird syntax
            /// for an operation with zero parameters.
            void print_op() {
                std::cout << name << "() | ";
                for (auto j : modes) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            };

            /**
             * Print operation information in Blackbird syntax
             * for an operation with one parameter.
             *
             * @param p1 parameter 1
             */
            template <typename T>
            void print_op(T p1) {
                std::cout << name << "(" << p1 << ") | ";
                for (auto j : modes) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            };

            /**
             * Print operation information in Blackbird syntax
             * for an operation with two parameters.
             *
             * @param p1 parameter 1
             * @param p2 parameter 2
             */
            template <typename T, typename S>
            void print_op(T p1, S p2) {
                std::cout << name << "(" << p1 << ", " << p2 << ") | ";
                for (auto j : modes) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            };

            /**
             * Print operation information in Blackbird syntax
             * for an operation with three parameters.
             *
             * @param p1 parameter 1
             * @param p2 parameter 2
             * @param p3 parameter 3
             */
            template <typename T, typename S, typename O>
            void print_op(T p1, S p2, O p3) {
                std::cout << name << "(" << p1 << ", " << p2 << ", " << p3 << ") | ";
                for (auto j : modes) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            };

            /**
             * Print operation information in Blackbird syntax
             * for an operation with an array parameter.
             *
             * @param p1 the array parameter
             */
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

            /**
             * Print operation information in Blackbird syntax
             * for an operation with two array parameters.
             *
             * @param p1 the first array parameter
             * @param p2 the second array parameter
             */
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

            /**
             * Checks that the number of gate parameters
             * matches the allowed number of gate parameters.
             *
             * @param args_size user provided number of parameters
             * @throws std::invalid_argument
             */
            void check_num_args(int args_size) {
                if (args_size != num_params) {
                    std::string np = std::to_string(num_params);
                    std::string as = std::to_string(args_size);
                    throw std::invalid_argument(name+" is a "+np+" parameter operation, but "
                        +as+" parameters were given.");
                }
            };

            /**
             * Checks that the number of modes applied
             * matches the allowed number of modes for the gate.
             *
             * @param mode_size user provided number of modes
             * @throws std::invalid_argument
             */
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

    /**
     * Represents the vacuum state
     */
    class Vacuum : public Operation {
        public:
            /**
             * Constructor for the vacuum class to automatically
             * initialize a vacuum state acting on mode `m`
             *
             * @param m mode vacuum state is initialized on
             */
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


    /**
     * Represents the coherent state.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/states.html#coherent-state).
     *
     * \rst
     * Displacement parameter :math:`\alpha` is accessible via:
     *
     * * :math:`|\alpha|`: ``Coherent->f1``
     * * :math:`\text{arg}(\alpha)`: ``Coherent->f2``
     *
     * \endrst
     */
    class Coherent : public Operation {
        public:
            /**
             * Constructor for the coherent class to automatically
             * initialize a coherent state acting on mode `m`
             *
             * @param displacement_phase `vector<double>` of length 2 containing
             *     the displacement magnitude and phase
             * @param m mode state is initialized on
             */
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

            /**
             * Constructor for the coherent class to automatically
             * initialize a coherent state acting on mode `m`
             *
             * @param alpha `vector<complex<double>>` of length 1 containing
             *     the displacement as a complex value
             * @param m mode state is initialized on
             */
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

            /**
             * Constructor for the coherent class that
             * throws an error if integer parameters are provided.
             *
             * @param alpha `vector<int>` parmeters
             * @param m mode state is initialized on
             * @throws invalid_argument Coherent must have real arguments
             */
            Coherent(intvec alpha, intvec m) {
                throw std::invalid_argument("Coherent must have real arguments");
            };
    };


    /**
     * Represents the squeezed state.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/states.html#squeezed-state).
     *
     * \rst
     * Squeezing parameter :math:`z` is accessible via:
     *
     * * :math:`r=|z|`: ``Squeezed->f1``
     * * :math:`\phi=\text{arg}(z)`: ``Squeezed->f2``
     *
     * \endrst
     */
    class Squeezed : public Operation {
        public:
            /**
             * Constructor for the squeezed class to automatically
             * initialize a squeezed state acting on mode `m`
             *
             * @param r_phase `vector<double>` of length 2 containing
             *     the squeezing magnitude and phase
             * @param m mode state is initialized on
             */
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

            /**
             * Constructor for the squeezed class that
             * throws an error if complex parameters are provided.
             *
             * @param alpha `vector<complex>` parmeters
             * @param m mode state is initialized on
             * @throws invalid_argument Squeezed must have real arguments
             */
            Squeezed(complexvec alpha, intvec m) {
                throw std::invalid_argument("Squeezed must have real arguments");
            };
            /**
             * Constructor for the squeezed class that
             * throws an error if integer parameters are provided.
             *
             * @param alpha `vector<int>` integer parmeters
             * @param m mode state is initialized on
             * @throws invalid_argument Squeezed must have real arguments
             */
            Squeezed(intvec alpha, intvec m) {
                throw std::invalid_argument("Squeezed must have real arguments");
            };
    };


    /**
     * Represents the thermal state.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/states.html#thermal-state).
     *
     * \rst
     * Mean photon number parameter :math:`\bar{n}` is accessible via:
     *
     * * :math:`\bar{n}`: ``Thermal->f1``
     *
     * \endrst
     */
    class Thermal : public Operation {
        public:
            /**
             * Constructor to automatically initialize a thermal state acting on mode `m`
             *
             * @param nbar `vector<double>` of length 1 containing mean photon number
             * @param m mode state is initialized on
             * @throws std::invalid_argument cannot have negative thermal population (`nbar` must be >= 0)
             */
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

            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param nbar `vector<complex>` parameters
             * @param m mode state is initialized on
             * @throws invalid_argument Operation must have real arguments
             */
            Thermal(complexvec nbar, intvec m) {
                throw std::invalid_argument("Thermal must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param nbar `vector<int>` parameters
             * @param m mode state is initialized on
             * @throws invalid_argument Operation must have real arguments
             */
            Thermal(intvec nbar, intvec m) {
                throw std::invalid_argument("Thermal must have real arguments");
            };
    };


    /**
     * Represents a Fock state.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/states.html#fock-state).
     *
     * \rst
     * Photon number :math:`n` is accessible via:
     *
     * * :math:`n`: ``Fock->i1``
     *
     * \endrst
     */
    class Fock : public Operation {
        public:
            /**
             * Constructor to automatically initialize a Fock state acting on mode `m`
             *
             * @param n `vector<double>` of length 1 containing photon number
             * @param m mode state is initialized on
             * @throws std::invalid_argument cannot have negative Fock state (`n < 0`)
             */
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

            /**
             * Constructor that throws an error if real parameters are provided.
             *
             * @param n `vector<double>` parameters
             * @param m mode state is initialized on
             * @throws invalid_argument Operation must have integer arguments
             */
            Fock(floatvec n, intvec m) {
                throw std::invalid_argument("Fock must have integer arguments");
            };

            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param n `vector<complex>` parameters
             * @param m mode state is initialized on
             * @throws invalid_argument Operation must have integer arguments
             */
            Fock(complexvec n, intvec m) {
                throw std::invalid_argument("Fock must have integer arguments");
            };
    };

    /**
     * Represents the cat state.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/states.html#cat-state).
     *
     * \rst
     * Cat state parameters :math:`\alpha` and :math:`p` (parity) is accessible via:
     *
     * * :math:`|\alpha|`: ``Catstate->f1``
     * * :math:`\text{arg}(\alpha)`: ``Catstate->f2``
     * * :math:`p`: ``Catstate->f3``
     *
     * \endrst
     */
    class Catstate : public Operation {
        // Cat state
        public:
            /**
             * Constructor to automatically initialize a cat state acting on mode `m`
             *
             * @param alpha `vector<complex>` of length 2 containing displacement
             * @param m mode state is initialized on
             * @param parity `float` parity of the cat state
             */
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

            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param alpha `vector<double>` parameters
             * @param m mode state is initialized on
             * @throws invalid_argument alpha parameter must be complex
             */
            Catstate(floatvec alpha, intvec m) {
                throw std::invalid_argument("Catstate alpha parameter must be complex");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param alpha `vector<int>` parameters
             * @param m mode state is initialized on
             * @throws invalid_argument alpha parameter must be complex
             */
            Catstate(intvec alpha, intvec m) {
                throw std::invalid_argument("Catstate alpha parameter must be complex");
            };
    };


    //================================
    // Single mode gates
    //================================

    /**
     * Represents the rotation gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#rotation).
     *
     * \rst
     * Rotation gate parameter :math:`\phi` accessible via:
     *
     * * :math:`\phi`: ``Rgate->f1``
     *
     * \endrst
     */
    class Rgate : public Operation {
        // Rotation gate
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param phi `vector<double>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument gate must have real arguments
             */
            Rgate(complexvec phi, intvec m) {
                throw std::invalid_argument("Rgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param phi `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument gate must have real arguments
             */
            Rgate(intvec phi, intvec m) {
                throw std::invalid_argument("Rgate must have real arguments");
            };
            /**
             * Constructor to automatically initialize a rotation gate acting on mode `m`
             *
             * @param phi `vector<double>` of length 1 containing phase
             * @param m mode gate acts on
             */
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

    /**
     * Represents the displacement gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#displacement).
     *
     * \rst
     * Displacement gate parameter :math:`\alpha` accessible via:
     *
     * * :math:`|\alpha|`: ``Dgate->f1``
     * * :math:`\text{arg}(\alpha)`: ``Dgate->f2``
     *
     * \endrst
     */
    class Dgate : public Operation {
        public:
            /**
             * Constructor to initialize a displacement gate acting on mode `m`
             *
             * @param displacement_phase `vector<double>` of length 2 containing
             *     the displacement magnitude and phase
             * @param m mode gate acts on
             */
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

            /**
             * Constructor to initialize a displacement gate acting on mode `m`
             *
             * @param alpha `vector<complex<double>>` of length 1 containing
             *     the displacement as a complex value
             * @param m mode gate acts on
             */
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
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param x `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Dgate(intvec x, intvec m) {
                throw std::invalid_argument("Dgate must have real arguments");
            };
    };

    /**
     * Represents the position displacement gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#displacement).
     *
     * \rst
     * Position displacement gate parameter :math:`x` accessible via:
     *
     * * :math:`x`: ``Xgate->f1``
     *
     * \endrst
     */
    class Xgate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param x `vector<complex<double>>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Xgate(complexvec x, intvec m) {
                throw std::invalid_argument("Xgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param x `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Xgate(intvec x, intvec m) {
                throw std::invalid_argument("Xgate must have real arguments");
            };
            /**
             * Constructor to initialize a Xgate acting on mode `m`
             *
             * @param x `vector<double>` of length 1 containing the
             *     position displacement
             * @param m mode gate acts on
             */
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

    /**
     * Represents the momentum displacement gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#displacement).
     *
     * \rst
     * Momentum displacement gate parameter :math:`z` accessible via:
     *
     * * :math:`z`: ``Zgate->f1``
     *
     * \endrst
     */
    class Zgate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param z `vector<complex<double>>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Zgate(complexvec z, intvec m) {
                throw std::invalid_argument("Zgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param z `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Zgate(intvec z, intvec m) {
                throw std::invalid_argument("Zgate must have real arguments");
            };
            /**
             * Constructor to initialize a Zgate acting on mode `m`
             *
             * @param z `vector<double>` of length 1 containing the
             *     momentum displacement
             * @param m mode gate acts on
             */
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

    /**
     * Represents the squeeze gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#squeezing).
     *
     * \rst
     * Squeezing parameter :math:`z` is accessible via:
     *
     * * :math:`r=|z|`: ``Sgate->f1``
     * * :math:`\phi=\text{arg}(z)`: ``Sgate->f2``
     *
     * \endrst
     */
    class Sgate : public Operation {
        public:
            /**
             * Constructor to initialize a Sgate acting on mode `m`
             *
             * @param r_phase `vector<double>` of length 2 containing the
             *     squeezing magnitude and phase
             * @param m mode gate acts on
             */
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

            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param alpha `vector<complex<double>>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Sgate(complexvec alpha, intvec m) {
                throw std::invalid_argument("Sgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param alpha `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Sgate(intvec alpha, intvec m) {
                throw std::invalid_argument("Sgate must have real arguments");
            };
    };

    /**
     * Represents the quadratic phase gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#quadratic-phase).
     *
     * \rst
     * Phase shift parameter :math:`s` accessible via:
     *
     * * :math:`s`: ``Pgate->f1``
     *
     * \endrst
     */
    class Pgate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param s `vector<complex<double>>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Pgate(complexvec s, intvec m) {
                throw std::invalid_argument("Pgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param s `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Pgate(intvec s, intvec m) {
                throw std::invalid_argument("Pgate must have real arguments");
            };
            /**
             * Constructor to initialize a Pgate acting on mode `m`
             *
             * @param s `vector<double>` of length 1 containing the phase shift
             * @param m mode gate acts on
             */
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

    /**
     * Represents the cubic phase gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#cubic-phase).
     *
     * \rst
     * Phase shift parameter :math:`s` accessible via:
     *
     * * :math:`s`: ``Vgate->f1``
     *
     * \endrst
     */
    class Vgate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param s `vector<complex<double>>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Vgate(complexvec s, intvec m) {
                throw std::invalid_argument("Vgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param s `vector<int>` parameters
             * @param m mode gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            Vgate(intvec s, intvec m) {
                throw std::invalid_argument("Vgate must have real arguments");
            };
            /**
             * Constructor to initialize a Vgate acting on mode `m`
             *
             * @param s `vector<double>` of length 1 containing the phase shift
             * @param m mode gate acts on
             */
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

    /**
     * Represents the beamsplitter.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#beamsplitter).
     *
     * \rst
     * Beamsplitter parameters :math:`\theta` and :math:`\phi` accessible via:
     *
     * * :math:`\theta`: ``BSgate->f1``
     * * :math:`\phi`: ``BSgate->f1``
     *
     * \endrst
     */
    class BSgate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param theta_phi `vector<complex<double>>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            BSgate(complexvec theta_phi, intvec m) {
                throw std::invalid_argument("BSgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param theta_phi `vector<int>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            BSgate(intvec theta_phi, intvec m) {
                throw std::invalid_argument("BSgate must have real arguments");
            };
            /**
             * Constructor to initialize a BSgate acting on modes `m`
             *
             * @param theta_phi `vector<double>` of length 2 containing the
             *     beamsplitter angle and phase
             * @param m `vector<int>` containing both modes the gate acts on
             */
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


    /**
     * Represents the two mode squeezing gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#two-mode-squeezing).
     *
     * \rst
     * Squeezing parameter :math:`z` accessible via:
     *
     * * :math:`r=|z|`: ``S2gate->f1``
     * * :math:`\phi=\text{arg}(z)`: ``S2gate->f2``
     *
     * \endrst
     */
    class S2gate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param r_phi `vector<complex<double>>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            S2gate(complexvec r_phi, intvec m) {
                throw std::invalid_argument("S2gate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param r_phi `vector<int>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            S2gate(intvec r_phi, intvec m) {
                throw std::invalid_argument("S2gate must have real arguments");
            };
            /**
             * Constructor to initialize a BSgate acting on modes `m`
             *
             * @param r_phi `vector<double>` of length 2 containing
             *     the squeezing magnitude and phase
             * @param m `vector<int>` containing both modes the gate acts on
             */
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

    /**
     * Represents the controlled addition gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#controlled-x-gate).
     *
     * \rst
     * CX parameter :math:`s` accessible via:
     *
     * * :math:`s`: ``CXgate->f1``
     *
     * \endrst
     */
    class CXgate : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param s `vector<complex<double>>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            CXgate(complexvec s, intvec m) {
                throw std::invalid_argument("CXgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param s `vector<int>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            CXgate(intvec s, intvec m) {
                throw std::invalid_argument("CXgate must have real arguments");
            };
            /**
             * Constructor to initialize a CXgate acting on modes `m`
             *
             * @param s `vector<double>` of length 1 containing the parameter
             * @param m `vector<int>` containing both modes the gate acts on
             */
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


    /**
     * Represents the controlled phase gate.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#controlled-phase).
     *
     * \rst
     * CZ parameter :math:`s` accessible via:
     *
     * * :math:`s`: ``CZgate->f1``
     *
     * \endrst
     */
    class CZgate : public Operation {
        // Beamsplitter
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param s `vector<complex<double>>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            CZgate(complexvec s, intvec m) {
                throw std::invalid_argument("CZgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param s `vector<int>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            CZgate(intvec s, intvec m) {
                throw std::invalid_argument("CZgate must have real arguments");
            };
            /**
             * Constructor to initialize a CZgate acting on modes `m`
             *
             * @param s `vector<double>` of length 1 containing the parameter
             * @param m `vector<int>` containing both modes the gate acts on
             */
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


    /**
     * Represents the cross-Kerr interaction.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/gates.html#cross-kerr-interaction).
     *
     * \rst
     * Cross-Kerr parameter :math:`\kappa` accessible via:
     *
     * * :math:`\kappa`: ``CKgate->f1``
     *
     * \endrst
     */
    class CKgate : public Operation {
        // Beamsplitter
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param s `vector<complex<double>>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            CKgate(complexvec s, intvec m) {
                throw std::invalid_argument("CKgate must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param s `vector<int>` parameters
             * @param m `vector<int>` containing both modes the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            CKgate(intvec s, intvec m) {
                throw std::invalid_argument("CKgate must have real arguments");
            };
            /**
             * Constructor to initialize a CKgate acting on modes `m`
             *
             * @param s `vector<double>` of length 1 containing the parameter :math:`\kappa`
             * @param m `vector<int>` containing both modes the gate acts on
             */
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

    /**
     * Represents the loss channel
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/others.html#loss-channel).
     *
     * \rst
     * Loss parameter :math:`T` accessible via:
     *
     * * :math:`T`: ``LossChannel->f1``
     *
     * \endrst
     */
    class LossChannel : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param phi `vector<complex<double>>` parameters
             * @param m `vector<int>` containing mode the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            LossChannel(complexvec phi, intvec m) {
                throw std::invalid_argument("LossChannel must have real arguments");
            };
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param phi `vector<complex<double>>` parameters
             * @param m `vector<int>` containing mode the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            LossChannel(intvec phi, intvec m) {
                throw std::invalid_argument("LossChannel must have real arguments");
            };
            /**
             * Constructor to initialize a loss channel acting on modes `m`
             *
             * @param T `vector<double>` of length 1 containing the parameter
             * @param m `vector<int>` containing mode the gate acts on
             */
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


    /**
     * Represents the thermal loss channel
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/others.html#thermal-loss-channel).
     *
     * \rst
     * Loss parameter :math:`T` and mean thermal population :math:`\bar{n}` accessible via:
     *
     * * :math:`T`: ``ThermalLossChannel->f1``
     * * :math:`\bar{n}`: ``ThermalLossChannel->f2``
     *
     * \endrst
     */
    class ThermalLossChannel : public Operation {
        public:
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param phi `vector<complex<double>>` parameters
             * @param m `vector<int>` containing mode the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            ThermalLossChannel(complexvec phi, intvec m) {
                throw std::invalid_argument("ThermalLossChannel must have real arguments");
            };
            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param phi `vector<complex<double>>` parameters
             * @param m `vector<int>` containing mode the gate acts on
             * @throws invalid_argument Operation must have real arguments
             */
            ThermalLossChannel(intvec phi, intvec m) {
                throw std::invalid_argument("ThermalLossChannel must have real arguments");
            };
            /**
             * Constructor to initialize a thermal loss channel acting on modes `m`
             *
             * @param T `vector<double>` of length 2 containing the parameter and thermal population
             * @param m `vector<int>` containing mode the gate acts on
             */
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

    /**
     * Represents an interferometer
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/code/ops.html#strawberryfields.ops.Interferometer).
     *
     * This operation stores a linear interferometer unitary as a
     * unitary matrix, ready to be decomposed into beamsplitters and rotation gates.
     *
     * \rst
     * Unitary matrix :math:`U` accessible via:
     *
     * * :math:`U`: ``Interferometer->U1``
     *
     * \endrst
     */
    class Interferometer : public Operation {
        public:
            /**
             * Constructor to initialize an interferometer acting on modes `m`
             *
             * @param unitary `vector<vector<complex<double>>>` representing the unitary matrix
             * @param m `vector<int>` containing the list of modes the gate acts on
             * @throws invalid_argument unitary matrix should be square
             * @throws invalid_argument unitary matrix must have the same size as the number of modes
             */
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


    /**
     * Represents a Gaussian transformation
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/code/ops.html#strawberryfields.ops.GaussianTransform).
     *
     * This operation stores a Gaussian transformation as a
     * symplectic matrix, ready to be decomposed into squeezers, beamsplitters, and rotation gates.
     *
     * \rst
     * Symplectic matrix :math:`S` accessible via:
     *
     * * :math:`S`: ``GaussianTransform->S1``
     *
     * \endrst
     */
    class GaussianTransform : public Operation {
        public:
            /**
             * Constructor to initialize an Gaussian transform acting on modes `m`
             *
             * @param symplectic `vector<vector<double>>` representing the symplectic matrix
             * @param m `vector<int>` containing the list of modes the gate acts on
             * @throws invalid_argument symplectic matrix should be square
             * @throws invalid_argument symplectic matrix must have the size double the number of modes
             */
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


    /**
     * Represents a Gaussian state
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/code/ops.html#strawberryfields.ops.Gaussian).
     *
     * This operation intializes a Gaussian state as a
     * covaraince matrix and vector of means, ready to be decomposed into
     * initial thermal state, displacements, squeezers, beamsplitters, and rotation gates.
     *
     * \rst
     * Covariance matrix :math:`V` and vector of means :math:`r` accessible via:
     *
     * * :math:`V`: ``Gaussian->S1``
     * * :math:`r`: ``Gaussian->S2``
     *
     * \endrst
     */
    class Gaussian : public Operation {
        public:
            /**
             * Constructor to initialize a Gaussian state on modes `m`
             *
             * @param cov `vector<vector<double>>` representing the covariance matrix
             * @param means single row `vector<vector<double>>` array representing the vector of means
             * @param m `vector<int>` containing the list of modes the gate acts on
             * @throws invalid_argument covariance matrix should be square
             * @throws invalid_argument covariance matrix must have size double the number of modes
             * @throws invalid_argument means vector should only have 1 row
             * @throws invalid_argument means vector must have size double the number of modes
             */
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

            /**
             * Constructor to initialize a Gaussian state with zero displacement on modes `m`
             *
             * @param cov `vector<vector<double>>` representing the covariance matrix
             * @param m `vector<int>` containing the list of modes the gate acts on
             * @throws invalid_argument covariance matrix should be square
             * @throws invalid_argument covariance matrix must have size double the number of modes
             */
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

    /**
     * Represents the photon number resolution measurement.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/measurements.html#photon-counting-measurement).
     */
    class MeasureFock : public Operation {
        public:
            /**
             * Constructor to automatically initialize a PNR measurement acting on mode `m`
             *
             * @param m `vector<int>` containing mode the measurement acts on
             */
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

    /**
     * Represents the Homodyne measurement.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/measurements.html#homodyne-measurement).

     * \rst
     * Homodyne phase parameter :math:`\phi` accessible via:
     *
     * * :math:`\phi`: ``MeasureHomodyne->f1``
     *
     * \endrst
     */
    class MeasureHomodyne : public Operation {
        public:
            /**
             * Constructor to automatically initialize a Homodyne measurement acting on mode `m`
             *
             * By default, if no quadrature angle is provided, we assume the measurement is in X.
             *
             * @param m `vector<int>` containing mode the measurement acts on
             */
            MeasureHomodyne(intvec m) {
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

            /**
             * Constructor to automatically initialize a Homodyne measurement acting on mode `m`
             *
             * @param phi `vector<double>` containing the measurement phase
             * @param m `vector<int>` containing mode the measurement acts on
             */
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

            /**
             * Constructor that throws an error if complex parameters are provided.
             *
             * @param phi `vector<double>` parameters
             * @param m mode measurement acts on
             * @throws invalid_argument operation must have real arguments
             */
            MeasureHomodyne(complexvec phi, intvec m) {
                throw std::invalid_argument("MeasureHomodyne must have real arguments");
            };
            /**
             * Constructor that throws an error if integer parameters are provided.
             *
             * @param phi `vector<int>` parameters
             * @param m mode measurement acts on
             * @throws invalid_argument operation must have real arguments
             */
            MeasureHomodyne(intvec phi, intvec m) {
                throw std::invalid_argument("MeasureHomodyne must have real arguments");
            };
    };

    /**
     * Represents the Heterodyne measurement.
     * For more details, see the
     * [Strawberry Fields convention page]
     * (https://strawberryfields.readthedocs.io/en/latest/conventions/measurements.html#heterodyne-measurement).
     */
    class MeasureHeterodyne : public Operation {
        public:
            /**
             * Constructor to automatically initialize a Heterodyne measurement acting on mode `m`
             *
             * @param m `vector<int>` containing mode the measurement acts on
             */
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

    /**
     * Represents a classical intensity measurement.
     */
    class MeasureIntensity : public Operation {
        public:
            /**
             * Constructor to automatically initialize an intensity measurement acting on mode `m`
             *
             * @param m `vector<int>` containing mode the measurement acts on
             */
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

    /**
     * The quantum program. This is the main class for viewing and extracting
     * details of the quantum operations requested in the Blackbird script.
     */
    class Program {
        public:
            /// Name of the device the quantum program is destined for
            Device name;
            /// Vector of operations to be performed
            std::vector<Operation*> operations;

            /// Virtual method to print the corresponding device info.
            /// This _must_ be overwritten by the device class that inherits from Program.
            virtual void print_device_info() {};

            /// This methods loops through all operations in the operations vector,
            /// and, depending on the number of arguments and the domain of the arguments,
            /// calls the corresponding Operation method to print operation details.
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


    /**
     * Device Chip0:
     * a physical photonic chip with coherent state input, 4x4 interferometer,
     * and 4 intensity measurements.
     */
    class Chip0 : public Program {
        public:
            /// Number of shots to perform on the device (default 1)
            int shots = 1;

            /**
             * Constructor to initialise the device
             */
            Chip0(Program dev) {
                name = Device::Chip0;
            };
            /**
             * Constructor to initialise the device with a specific number of shots.
             * @param s number of shots to perform
             */
            Chip0(int s=1) {
                name = Device::Chip0;
                shots = s;
            };
            /// prints out device information
            void print_device_info() {
                std::cout << "Device: Chip0" << std::endl;
                std::cout << "Shots: " << shots << std::endl;
            };
    };


    /**
     * Device GaussianSimulator:
     * corresponds to any able Gaussian simulator; i.e. a simulator able to apply
     * and manipulate all Gaussian states/operations/measurements defined in Blackbird.
     */
    class GaussianSimulator : public Program {
        public:
            /// number of subsystems
            int ns;
            /// Number of shots to perform on the device (default 1)
            int shots = 1;
            /**
             *\rst
             * Value of :math:`\hbar` to use in the commutation relation :math:`[\hat{x},\hat{p}]=i\hbar`
             * \endrst
             */
            double hb = 2.0;

            /**
             * Constructor to initialise the device
             */
            GaussianSimulator() {
                name = Device::Gaussian;
            };
            /**
             * Constructor to initialise the device
             */
            GaussianSimulator(Program dev) {
                name = Device::Gaussian;
            };
            /**
             * Constructor to initialise the device with a specific set of parameters.
             * @param num_subsystems number of modes to initialise the simulator with
             * @param s number of shots to perform
             * @param hbar value of hbar in the canonical commutation relation
             */
            GaussianSimulator(int num_subsystems, int s=0, double hbar=2) {
                name = Device::Gaussian;
                ns = num_subsystems;
                shots = s;
                hb = hbar;
            };

            /// prints out device information
            void print_device_info() {
                std::cout << "Device: Gaussian (simulator)" << std::endl;
                std::cout << "Number of subsystems: " << ns << std::endl;
                std::cout << "Shots: " << shots << std::endl;
                std::cout << "hbar: " << hb << std::endl;
            };
    };


    /**
     * Device FockSimulator:
     * corresponds to any able Fock simulator; i.e. a simulator able to apply
     * and manipulate every CV state/operation/measurement defined in Blackbird.
     */
    class FockSimulator : public Program {
        public:
            /// number of subsystems
            int ns;
            /// Fock space cutoff/truncation
            int cutoff;
            /// Number of shots to perform on the device (default 1)
            int shots = 1;
            /**
             *\rst
             * Value of :math:`\hbar` to use in the commutation relation :math:`[\hat{x},\hat{p}]=i\hbar`
             * \endrst
             */
            double hb = 2.0;

            /**
             * Constructor to initialise the device
             */
            FockSimulator() {
                name = Device::Fock;
            };
            /**
             * Constructor to initialise the device
             */
            FockSimulator(Program dev) {
                name = Device::Fock;
            };
            /**
             * Constructor to initialise the device with a specific set of parameters.
             * @param num_subsystems number of modes to initialise the simulator with
             * @param cutoff_dim Fock basis truncation
             * @param s number of shots to perform
             * @param hbar value of hbar in the canonical commutation relation
             */
            FockSimulator(int num_subsystems, int cutoff_dim, int s=0, double hbar=2) {
                name = Device::Fock;
                cutoff = cutoff_dim;
                ns = num_subsystems;
                shots = s;
                hb = hbar;
            };

            /// prints out device information
            void print_device_info() {
                std::cout << "Device: Fock (simulator)" << std::endl;
                std::cout << "Number of subsystems: " << ns << std::endl;
                std::cout << "Cutoff dimension: " << cutoff << std::endl;
                std::cout << "Shots: " << shots << std::endl;
                std::cout << "hbar: " << hb << std::endl;
            };
    };
}