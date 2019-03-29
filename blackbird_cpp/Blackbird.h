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
#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <cmath>
#include <complex>
#include <stdexcept>
#include <unordered_map>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdLexer.h"
#include "blackbirdParser.h"
#include "blackbirdBaseVisitor.h"

#include "BlackbirdProgram.h"

/**
 * \rst
 *
 * The main Blackbird namespace. All C++ functions and classes
 * are available from this namespace after including the header file:
 *
 * .. code-block:: cpp
 *
 *     #include "Blackbird.h"
 *
 * Files
 * -----
 *
 *
 * .. toctree::
 *    :maxdepth: 5
 *
 *    file_blackbird_cpp_Blackbird.h.rst
 *
 * .. toctree::
 *    :maxdepth: 5
 *
 *    file_blackbird_cpp_BlackbirdProgram.h.rst
 *
 * .. toctree::
 *    :maxdepth: 5
 *
 *    file_blackbird_cpp_BlackbirdVariables.h.rst
 *
 * .. toctree::
 *    :maxdepth: 5
 *
 *    file_blackbird_cpp_Visitor.cpp.rst
 * \endrst
 */
namespace blackbird {

    /**
     * Checks if a class are of the same derived type as another.
     *
     * @tparam DstType Type of the destination class
     * @tparam SrcType Type of the source class
     * @param src source object
     * @return True or False
     */
    template <class DstType, class SrcType>
    bool is_type(const SrcType* src)
    {
      return dynamic_cast<const DstType*>(src) != nullptr;
    }


    /**
     * The main Blackbird visitor. This visitor is invoked implicitly
     * via the `parse` function to parse the Blackbird script.
     *
     * The methods defined in this class describe how to traverse the
     * abstract syntax tree describing the blackbird program,
     * how to extract and evaluate arrays, variables, expressions,
     * and quantum programs.
     */
    class  Visitor : public blackbirdBaseVisitor {
    private:
        std::string var_type;
        std::string var_name;
    public:
        /** \brief Unordered map mapping from blackbird complex variable names to `std::complex<double>` values */
        std::unordered_map<std::string, std::complex<double>> complex_vars;
        /** Unordered map mapping from blackbird float variable names to `double` values */
        std::unordered_map<std::string, double> float_vars;
        /** Unordered map mapping from blackbird int variable names to `int` values */
        std::unordered_map<std::string, int> int_vars;
        /** Unordered map mapping from blackbird string variable names to `std::string` values */
        std::unordered_map<std::string, std::string> str_vars;
        /** Unordered map mapping from blackbird bool variable names to `bool` values */
        std::unordered_map<std::string, bool> bool_vars;

        /** \brief Unordered map mapping from blackbird complex array variable names to `complexmat` values */
        std::unordered_map<std::string, complexmat> complexmat_vars;
        /** \brief Unordered map mapping from blackbird float array variable names to `floatmat` values */
        std::unordered_map<std::string, floatmat> floatmat_vars;
        /** \brief Unordered map mapping from blackbird int array variable names to `intmat` values */
        std::unordered_map<std::string, intmat> intmat_vars;

        /// quantum Program that is populated by the Visitor
        Program* program;

        template <class O>
        O* _create_operation(blackbirdParser::ArgumentsContext *ctx, intvec modes);

        antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx);
        antlrcpp::Any visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx);

        antlrcpp::Any visitArrayvar(blackbirdParser::ArrayvarContext *ctx);
        antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext*);

        antlrcpp::Any visitStatement(blackbirdParser::StatementContext *ctx);
        antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *ctx);

        antlrcpp::Any visitStart(blackbirdParser::StartContext *ctx);
    };

    Program* parse(std::ifstream &stream);
    Program* parse(std::string &s_input);
}
