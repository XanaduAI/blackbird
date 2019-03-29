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
// ===========================
// Define the variable maps
// ===========================

namespace blackbird {

    /// generic variable_map definition
    template<typename T>
    struct variable_map;


    /// get and set integer values in the variable map
    template<>
    struct variable_map<int>
    {
        /**
         * Get value from the variable map corresponding to a name,
         * and attempt to convert it into an integer
         *
         * @param V Blackbird Visitor
         * @param key variable name
         *
         * @returns integer value
         * @throws invalid_argument Cannot convert a complex variable to an int
         * @throws invalid_argument Cannot convert a string variable to an int
         * @throws invalid_argument Cannot convert a bool variable to an int
         * @throws invalid_argument Variable key not defined
         */
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
        /**
         * Set an integer value in the variable map corresponding to a name
         *
         * @param V Blackbird Visitor
         * @param key variable name
         * @param val variable value
         */
        static void setVal(Visitor *V, std::string key, int val) {
            V->int_vars[key] = val;
        }
    };

    /// get and set real values in the variable map
    template<>
    struct variable_map<double>
    {
        /**
         * Get value from the variable map corresponding to a name,
         * and attempt to convert it into an double
         *
         * @param V Blackbird Visitor
         * @param key variable name
         *
         * @returns real value
         * @throws invalid_argument Cannot convert a complex variable to an float
         * @throws invalid_argument Cannot convert a string variable to an float
         * @throws invalid_argument Cannot convert a bool variable to an float
         * @throws invalid_argument Variable key not defined
         */
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
        /**
         * Set a real value in the variable map corresponding to a name
         *
         * @param V Blackbird Visitor
         * @param key variable name
         * @param val variable value
         */
        static void setVal(Visitor *V, std::string key, double val) {
            V->float_vars[key] = val;
        }
    };


    /// get and set complex values in the variable map
    template<>
    struct variable_map<std::complex<double>>
    {
        /**
         * Get value from the variable map corresponding to a name,
         * and attempt to convert it into an complex value
         *
         * @param V Blackbird Visitor
         * @param key variable name
         *
         * @returns integer value
         * @throws invalid_argument Cannot convert a string variable to an complex
         * @throws invalid_argument Cannot convert a bool variable to an complex
         * @throws invalid_argument Variable key not defined
         */
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
        /**
         * Set an complex value in the variable map corresponding to a name
         *
         * @param V Blackbird Visitor
         * @param key variable name
         * @param val variable value
         */
        static void setVal(Visitor *V, std::string key, std::complex<double> val) {
            V->complex_vars[key] = val;
        }
    };


    /// get and set string values in the variable map
    template<>
    struct variable_map<std::string>
    {
        /**
         * Get value from the variable map corresponding to a name,
         * and attempt to convert it into an string
         *
         * @param V Blackbird Visitor
         * @param key variable name
         *
         * @returns integer value
         * @throws invalid_argument Cannot convert a complex variable to an string
         * @throws invalid_argument Cannot convert a int variable to an string
         * @throws invalid_argument Cannot convert a float variable to an string
         * @throws invalid_argument Cannot convert a bool variable to an string
         * @throws invalid_argument Variable key not defined
         */
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
        /**
         * Set a string value in the variable map corresponding to a name
         *
         * @param V Blackbird Visitor
         * @param key variable name
         * @param val variable value
         */
        static void setVal(Visitor *V, std::string key, std::string val) {
            if (val.front() == '"') {
                val.erase(0, 1); // erase the first character
                val.erase(val.size() - 1); // erase the last character
            }
            V->str_vars[key] = val;
        }
    };


    /// get and set boolean values in the variable map
    template<>
    struct variable_map<bool>
    {
        /**
         * Get value from the variable map corresponding to a name,
         * and attempt to convert it into an bool
         *
         * @param V Blackbird Visitor
         * @param key variable name
         *
         * @returns integer value
         * @throws invalid_argument Cannot convert a complex variable to an bool
         * @throws invalid_argument Cannot convert a int variable to an bool
         * @throws invalid_argument Cannot convert a float variable to an bool
         * @throws invalid_argument Cannot convert a string variable to an bool
         * @throws invalid_argument Variable key not defined
         */
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
        /**
         * Set a bool value in the variable map corresponding to a name
         *
         * @param V Blackbird Visitor
         * @param key variable name
         * @param val variable value
         */
        static void setVal(Visitor *V, std::string key, bool val) {
            V->bool_vars[key] = val;
        }
        /**
         * Set a string value representing a boolean in the variable map corresponding to a name
         *
         * @param V Blackbird Visitor
         * @param key variable name
         * @param val variable value (either "True" or "False")
         * @throws invalid_argument val is not a valid boolean variable
         */
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
