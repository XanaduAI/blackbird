// ===========================
// Define the variable maps
// ===========================

namespace blackbird {

    template<typename T>
    struct variable_map;


    template<>
    struct variable_map<int>
    {
        static int getVal(Visitor *V, std::string key) {
            auto iter_int = V->int_vars.find(key);
            auto iter_float = V->float_vars.find(key);
            auto iter_complex = V->complex_vars.find(key);
            auto iter_str = V->str_vars.find(key);
            auto iter_bool = V->bool_vars.find(key);

            int val;

            if (iter_int != V->int_vars.end()) {
                val = iter_int->second;
            }
            else if (iter_float != V->float_vars.end()) {
                val = iter_float->second;
            }
            else if (iter_complex != V->complex_vars.end()) {
                throw std::invalid_argument("Cannot convert a complex variable to an int");
            }
            else if (iter_str != V->str_vars.end()) {
                throw std::invalid_argument("Cannot convert a string variable to an int");
            }
            else if (iter_bool != V->bool_vars.end()) {
                throw std::invalid_argument("Cannot convert a bool variable to an int");
            }
            else {
                throw std::invalid_argument("Variable " + key + " not defined");
            }

            return val;
        }
        static void setVal(Visitor *V, std::string key, int val) {
            V->int_vars[key] = val;
        }
    };

    template<>
    struct variable_map<double>
    {
        static double getVal(Visitor *V, std::string key) {
            auto iter_int = V->int_vars.find(key);
            auto iter_float = V->float_vars.find(key);
            auto iter_complex = V->complex_vars.find(key);
            auto iter_str = V->str_vars.find(key);
            auto iter_bool = V->bool_vars.find(key);

            double val;

            if (iter_float != V->float_vars.end()) {
                val = iter_float->second;
            }
            else if (iter_int != V->int_vars.end()) {
                val = iter_int->second;
            }
            else if (iter_complex != V->complex_vars.end()) {
                throw std::invalid_argument("Cannot convert a complex variable to a float");
            }
            else if (iter_str != V->str_vars.end()) {
                throw std::invalid_argument("Cannot convert a string variable to a float");
            }
            else if (iter_bool != V->bool_vars.end()) {
                throw std::invalid_argument("Cannot convert a bool variable to a float");
            }
            else {
                throw std::invalid_argument("Variable " + key + " not defined");
            }

            return val;
        }
        static void setVal(Visitor *V, std::string key, double val) {
            V->float_vars[key] = val;
        }
    };


    template<>
    struct variable_map<std::complex<double>>
    {
        static std::complex<double> getVal(Visitor *V, std::string key) {
            auto iter_int = V->int_vars.find(key);
            auto iter_float = V->float_vars.find(key);
            auto iter_complex = V->complex_vars.find(key);
            auto iter_str = V->str_vars.find(key);
            auto iter_bool = V->bool_vars.find(key);

            std::complex<double> val;

            if (iter_complex != V->complex_vars.end()) {
                val = iter_complex->second;
            }
            else if (iter_int != V->int_vars.end()) {
                val = iter_int->second;
            }
            else if (iter_float != V->float_vars.end()) {
                val = iter_float->second;
            }
            else if (iter_str != V->str_vars.end()) {
                throw std::invalid_argument("Cannot convert a string variable to a complex");
            }
            else if (iter_bool != V->bool_vars.end()) {
                throw std::invalid_argument("Cannot convert a bool variable to a complex");
            }
            else {
                throw std::invalid_argument("Variable " + key + " not defined");
            }

            return val;
        }
        static void setVal(Visitor *V, std::string key, std::complex<double> val) {
            V->complex_vars[key] = val;
        }
    };


    template<>
    struct variable_map<std::string>
    {
        static std::string getVal(Visitor *V, std::string key) {
            auto iter_int = V->int_vars.find(key);
            auto iter_float = V->float_vars.find(key);
            auto iter_complex = V->complex_vars.find(key);
            auto iter_str = V->str_vars.find(key);
            auto iter_bool = V->bool_vars.find(key);

            if (iter_str != V->str_vars.end()) {
                return iter_str->second;
            }
            else if (iter_complex != V->complex_vars.end()) {
                throw std::invalid_argument("Cannot convert a complex variable to a string");
            }
            else if (iter_int != V->int_vars.end()) {
                throw std::invalid_argument("Cannot convert an int variable to a string");
            }
            else if (iter_float != V->float_vars.end()) {
                throw std::invalid_argument("Cannot convert a float variable to a string");
            }
            else if (iter_bool != V->bool_vars.end()) {
                throw std::invalid_argument("Cannot convert a bool variable to a string");
            }
            else {
                throw std::invalid_argument("Variable " + key + " not defined");
            }

        }
        static void setVal(Visitor *V, std::string key, std::string val) {
            if (val.front() == '"') {
                val.erase(0, 1); // erase the first character
                val.erase(val.size() - 1); // erase the last character
            }
            V->str_vars[key] = val;
        }
    };


    template<>
    struct variable_map<bool>
    {
        static bool getVal(Visitor *V, std::string key) {
            auto iter_int = V->int_vars.find(key);
            auto iter_float = V->float_vars.find(key);
            auto iter_complex = V->complex_vars.find(key);
            auto iter_str = V->str_vars.find(key);
            auto iter_bool = V->bool_vars.find(key);

            if (iter_bool != V->bool_vars.end()) {
                return iter_bool->second;
            }
            else if (iter_complex != V->complex_vars.end()) {
                throw std::invalid_argument("Cannot convert a complex variable to a bool");
            }
            else if (iter_int != V->int_vars.end()) {
                throw std::invalid_argument("Cannot convert an int variable to a bool");
            }
            else if (iter_float != V->float_vars.end()) {
                throw std::invalid_argument("Cannot convert a float variable to a bool");
            }
            else if (iter_str != V->str_vars.end()) {
                throw std::invalid_argument("Cannot convert a string variable to a bool");
            }
            else {
                throw std::invalid_argument("Variable " + key + " not defined");
            }

        }
        static void setVal(Visitor *V, std::string key, bool val) {
            V->bool_vars[key] = val;
        }
        static void setVal(Visitor *V, std::string key, std::string val) {
            if (val == "True") {
                V->bool_vars[key] = true;
            }
            else if (val == "False") {
                V->bool_vars[key] = false;
            }
            else {
                throw std::invalid_argument(val + "is not a valid boolean variable");
            }
        }
    };
}