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
#include <regex>

#include "Blackbird.h"
#include "BlackbirdVariables.h"

namespace blackbird {
    // ===========================
    // Parser utility functions
    // ===========================

    /**
     * Parse Blackbird code contained within a C++ `std::string`
     *
     * To apply the parser directly to a file stream (`std::ifstream`),
     * use `parse(std::ifstream &stream)`.
     *
     * @param s_input string input
     * @return an instance of the Blackbird program containing details
     * about the device, gates, and parameters.
     */
    Program* parse(std::string &s_input) {
        antlr4::ANTLRInputStream input(s_input);
        blackbirdLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        blackbirdParser parser(&tokens);

        blackbirdParser::StartContext* tree = parser.start();
        Visitor visitor;
        Program* program = visitor.visitStart(tree);

        return program;
    }


    /**
     * Parse Blackbird code contained within a C++ `std::ifstream` file stream
     *
     * To apply the parser directly to a string container (`std::string`),
     * use `parse(std::string &s_input)`.
     *
     * @param stream file stream
     * @return an instance of the Blackbird program containing details
     * about the device, gates, and parameters.
     */
    Program* parse(std::ifstream &stream) {
        antlr4::ANTLRInputStream input(stream);
        blackbirdLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        blackbirdParser parser(&tokens);

        blackbirdParser::StartContext* tree = parser.start();
        Visitor visitor;
        Program* program = visitor.visitStart(tree);

        return program;
    }
    // ===========================
    // Number auxillary functions
    // ===========================

    /**
     * Split a string of the form "0, 6, 2, 1" into a list of integers
     *
     * @param string_list string containing comma-separated integers
     * @return returns a vector containing the integers
     */
    std::vector<int> split_string_to_ints(std::string string_list) {
        std::stringstream orig_string(string_list);
        std::vector<int> vec;

        while(orig_string.good()) {
            std::string substr;
            getline(orig_string, substr, ',');
            int n = std::stoi(substr);
            vec.push_back(n);
        }

        return vec;
    }


    /**
     * Convert a string containing a Blackbird-style complex number to a C++ complex double.
     *
     * @param num_string Blackbird style complex number string
     * @return C++ complex container
     */
    std::complex<double> _complex(std::string num_string) {
        std::regex num_regex("((\\+|-)?[0-9\\.]+)(e((\\+|-)?\\d))?((\\+|-)[0-9\\.]+)(e((\\+|-)?\\d))?j");
        std::smatch match;

        double real;
        double imag;
        std::complex<double> number;

        if (regex_search(num_string, match, num_regex)) {
            real = std::atof(match[1].str().c_str());
            if(match[4] != ""){
                int pwr = std::stoi(match[4].str().c_str());
                real *= pow(10, pwr);
            }
            imag = atof(match[6].str().c_str());
            if(match[9] != ""){
                int pwr = std::stoi(match[9].str().c_str());
                imag *= pow(10, pwr);
            }
        }

        number = std::complex<double>(real, imag);
        return number;
    }


    /**
     * Convert a string containing a Blackbird-style real number to a C++ double.
     *
     * @param num_string Blackbird style real number string
     * @return double literal
     */
    double _float(std::string num_string) {
        std::regex num_regex("((\\+|-)?[0-9\\.]+)(e((\\+|-)?\\d))?");
        std::smatch match;

        double real;

        if (regex_search(num_string, match, num_regex)) {
            real = std::atof(match[1].str().c_str());
            if(match[4] != ""){
                int pwr = std::stoi(match[4].str().c_str());
                real *= pow(10, pwr);
            }
        }

        return real;
    }

    // ==========================================
    // Extract expressions and numbers
    // ==========================================


    /**
     * Apply a blackbird function to an C++ argument.
     *
     * @param V the Blackbird visitor
     * @param ctx `FunctionLabelContext`
     * @param value a dummy template argument that corresponds to the expected
     *     type of the function value, as determined by the Blackbird type declarations.
     * @return the function value
     */
    template <typename T>
    T _func(Visitor *V, blackbirdParser::FunctionLabelContext *ctx, T value) {
        blackbirdParser::FunctionContext *func = ctx->function();
        blackbirdParser::ExpressionContext *arg = ctx->expression();

        if (func->EXP()) {
            return exp(_expression(V, arg, value));
        }
        else if (func->SIN()) {
            return sin(_expression(V, arg, value));
        }
        else if (func->COS()) {
            return cos(_expression(V, arg, value));
        }
        else if (func->SQRT()) {
            return sqrt(_expression(V, arg, value));
        }
        else {
            throw std::invalid_argument("Unkown function "+func->getText());
        }
    }


    /**
     * Evaluate a blackbird expression.
     *
     * This is a recursive function, that continually calls itself
     * until the full expression has been evaluated.
     *
     * @param V the Blackbird visitor
     * @param ctx `ExpressionContext`
     * @param value a dummy template argument that corresponds to the expected
     *     type of the expression value, as determined by the Blackbird type declarations.
     * @return the expression value
     */
    template <typename T>
    T _expression(Visitor* V, blackbirdParser::ExpressionContext* ctx, T value) {

        if (is_type<blackbirdParser::NumberLabelContext>(ctx)) {
            blackbirdParser::NumberLabelContext* child_ctx = dynamic_cast<blackbirdParser::NumberLabelContext*>(ctx);
            T val = V->visitNumber(child_ctx->number());
            return val;
        }
        else if (is_type<blackbirdParser::BracketsLabelContext>(ctx)) {
            blackbirdParser::BracketsLabelContext* child_ctx = dynamic_cast<blackbirdParser::BracketsLabelContext*>(ctx);
            T val = _expression(V, child_ctx->expression(), value);
            return val;
        }
        else if (is_type<blackbirdParser::VariableLabelContext>(ctx)) {
            blackbirdParser::VariableLabelContext* child_ctx = dynamic_cast<blackbirdParser::VariableLabelContext*>(ctx);
            return variable_map<T>::getVal(V, child_ctx->getText());
        }
        else if (is_type<blackbirdParser::SignLabelContext>(ctx)) {
            blackbirdParser::SignLabelContext* child_ctx = dynamic_cast<blackbirdParser::SignLabelContext*>(ctx);
            if (child_ctx->PLUS()) {
                T val = _expression(V, child_ctx->expression(), value);
                return val;
            }
            else if (child_ctx->MINUS()) {
                T val = -_expression(V, child_ctx->expression(), value);
                return val;
            }
        }
        else if (is_type<blackbirdParser::AddLabelContext>(ctx)) {
            blackbirdParser::AddLabelContext* child_ctx = dynamic_cast<blackbirdParser::AddLabelContext*>(ctx);
            std::vector<blackbirdParser::ExpressionContext*> vec = child_ctx->expression();
            if (child_ctx->PLUS()) {
                T val = _expression(V, vec[0], value) + _expression(V, vec[1], value);
                return val;
            }
            else if (child_ctx->MINUS()) {
                T val = _expression(V, vec[0], value) - _expression(V, vec[1], value);
                return val;
            }
        }
        else if (is_type<blackbirdParser::MulLabelContext>(ctx)) {
            blackbirdParser::MulLabelContext* child_ctx = dynamic_cast<blackbirdParser::MulLabelContext*>(ctx);
            std::vector<blackbirdParser::ExpressionContext*> vec = child_ctx->expression();
            if (child_ctx->TIMES()) {
                T val = _expression(V, vec[0], value) * _expression(V, vec[1], value);
                return val;
            }
            else if (child_ctx->DIVIDE()) {
                T val = _expression(V, vec[0], value) / _expression(V, vec[1], value);
                return val;
            }
        }
        else if (is_type<blackbirdParser::PowerLabelContext>(ctx)) {
            blackbirdParser::PowerLabelContext* child_ctx = dynamic_cast<blackbirdParser::PowerLabelContext*>(ctx);
            std::vector<blackbirdParser::ExpressionContext*> vec = child_ctx->expression();
            T val = pow(_expression(V, vec[0], value), _expression(V, vec[1], value));
            return val;
        }
        else if (is_type<blackbirdParser::FunctionLabelContext>(ctx)) {
            blackbirdParser::FunctionLabelContext* child_ctx = dynamic_cast<blackbirdParser::FunctionLabelContext*>(ctx);
            T val = _func(V, child_ctx, value);
            return val;
        }
    }

    /**
     * Once an expression variable context is entered, this begins
     * the recursive process of calling `_expression` to evaluate the
     * expression, followed by storing the variable value in `variable_map`.
     *
     * @param V the Blackbird visitor
     * @param ctx `ExpressionvarContext`
     * @param val a dummy template argument that corresponds to the expected
     *     type of the variable, as determined by the Blackbird type declarations.
     */
    template <typename T>
    void _set_expression_variable(Visitor* V, blackbirdParser::ExpressionvarContext *ctx, T val) {
        T result =  _expression(V, ctx->expression(), val);
        variable_map<T>::setVal(V, ctx->name()->getText(), result);
    }

    /**
     * Once an expression variable context is entered, this begins
     * the process of storing a non-numeric variable value, such as a
     * Blackbird `string` or `bool`.
     *
     * @param V the Blackbird visitor
     * @param ctx `ExpressionvarContext`
     * @param val a dummy template argument that corresponds to the expected
     *     type of the variable, as determined by the Blackbird type declarations.
     */
    template <typename T>
    void _set_non_numeric_variable(Visitor* V, blackbirdParser::ExpressionvarContext *ctx, T val) {
        std::string result = ctx->nonnumeric()->getText();
        variable_map<T>::setVal(V, ctx->name()->getText(), result);
    }

    /**
     * Defines what the visitor does when an `ExpressionvarContext` is visited.
     *
     * Here, it gets the variable name and the variable type, and starts the process
     * of extracting the variable based on the declared type.
     *
     * @param ctx `ExpressionvarContext`
     * @return returns 0 to indicate successful visitation
     */
    antlrcpp::Any Visitor::visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx) {
        // get var name
        var_name = ctx->name()->getText();

        // get array type
        var_type = ctx->vartype()->getText();

        if (var_type == "complex"){
            std::complex<double> value;
            _set_expression_variable(this, ctx, value);
        }
        else if (var_type == "float"){
            double value;
            _set_expression_variable(this, ctx, value);
        }
        else if (var_type == "int"){
            int value;
            _set_expression_variable(this, ctx, value);
        }
        else if (var_type == "str"){
            std::string value;
            _set_non_numeric_variable(this, ctx, value);
        }
        else if (var_type == "bool"){
            bool value;
            _set_non_numeric_variable(this, ctx, value);
        }
        else {
            throw std::invalid_argument("Unknown variable type " + var_type);
        }
        return 0;
    }


    /**
     * Defines what the visitor does when a `NumberContext` is visited.
     *
     * Here, it gets the string representing the number, and calls various
     * helper functions to convert Blackbird complex, float, and int to the
     * C++ equivalent.
     *
     * @param ctx `NumberContext`
     * @return returns the number literal
     */
    antlrcpp::Any Visitor::visitNumber(blackbirdParser::NumberContext *ctx) {
        // Visit a number, and convert it into the correct type
        std::string num_string = ctx->getText();

        if (var_type == "complex" and ctx->COMPLEX()) {
            std::complex<double> number = _complex(num_string);
            return number;
        }
        else if (var_type == "float" and ctx->FLOAT()){
            double number = _float(num_string);
            return number;
        }
        else if (var_type == "int" and ctx->INT()){
            int number = std::stoi(num_string);
            return number;
        }
        else if (ctx->PI()){
            return M_PI;
        }
        else {
            throw std::invalid_argument(var_name + " contains unknown number "
                + num_string + " with type " + var_type);
        }
    }


    // =========================
    // Array auxillary functions
    // =========================

    /**
     * Helper function for iterating through a Blackbird array,
     * and storing the result in a C++ vector container.
     *
     * @param V the Blackbird visitor
     * @param ctx `ArrayvarContext`
     * @param array empty vector to store the Blackbird array in
     * @return returns 0 to indicate successful visitation
     */
    template <typename T>
    T _array(Visitor *V, blackbirdParser::ArrayvarContext *ctx, T array) {
        std::vector<blackbirdParser::ArrayrowContext*> arrayrow = ctx->arrayval()->arrayrow();
        for (auto i : arrayrow) {
            array.push_back(V->visitArrayrow(i));
        }
        return array;
    }


    // =========================
    // Extract arrays
    // =========================

    /**
     * Defines what the visitor does when a `ArrayvarContext` is visited.
     *
     * Here, it gets the name and type of the array variable, initializes
     * a vector corresponding to the declared type, and stores it either in
     * the `complexmat_vars`, `floatmat_vars`, or `intmat_vars` dictionary.
     *
     * @param ctx `NumberContext`
     */
    antlrcpp::Any Visitor::visitArrayvar(blackbirdParser::ArrayvarContext *ctx) {
        // get array name
        var_name = ctx->name()->getText();

        // get array type
        var_type = ctx->vartype()->getText();

        // get array shape
        int rows;
        int cols;
        if(ctx->shape()){
            std::stringstream shape_string(ctx->shape()->getText());
            std::vector<int> shape;

            while(shape_string.good()) {
                std::string substr;
                getline(shape_string, substr, ',');
                int dimsize = std::stoi(substr);
                shape.push_back(dimsize);
            }
            rows = shape[0];
            cols = shape[1];
        }

        if (var_type == "complex"){
            complexmat array;
            array = _array(this, ctx, array);
            complexmat_vars[var_name] = array;
        }
        else if (var_type == "float") {
            floatmat array;
            array = _array(this, ctx, array);
            floatmat_vars[var_name] = array;
        }
        else if (var_type == "int") {
            intmat array;
            array = _array(this, ctx, array);
            intmat_vars[var_name] = array;
        }
    }


    /**
     * Defines what the visitor does when a `ArrayrowContext` is visited.
     *
     * Here, it extracts the column element values, and populates the row
     * by manually visiting each child element.
     *
     * @param ctx `ArrayrowContext`
     * @return the array row vector
     */
    antlrcpp::Any Visitor::visitArrayrow(blackbirdParser::ArrayrowContext *ctx) {
        std::vector<blackbirdParser::ExpressionContext*> col = ctx->expression();

        if (var_type == "complex"){
            complexvec row;
            for (auto i : col) {
                row.push_back(visitChildren(i));
            }
            return row;
        }
        else if (var_type == "float") {
            floatvec row;
            for (auto i : col) {
                row.push_back(visitChildren(i));
            }
            return row;
        }
        else if (var_type == "int") {
            intvec row;
            for (auto i : col) {
                row.push_back(visitChildren(i));
            }
            return row;
        }
    }

    // =======================
    // Quantum program parsing
    // =======================


    /**
     * Parse Blackbird function arguments with multiple expressions.
     *
     * @param V the Blackbird visitor
     * @param ctx `ArgumentsContext`
     * @param array vector to populate with each argument value
     * @param type a dummy template argument that corresponds to the expected
     *     type of the arguments, as determined by the Blackbird type declarations.
     * @return the vector of argument values
     */
    template <typename T, typename S>
    T _get_mult_expr_args(Visitor *V, blackbirdParser::ArgumentsContext *ctx, T array, S type) {
        std::vector<blackbirdParser::ValContext*> vals = ctx->val();
        for (auto i : vals) {
            if (i->expression()){
                S val;
                array.push_back(_expression(V, i->expression(), val));
            }
        }
        return array;
    }

    /**
     * Parse Blackbird function arguments to determine the number of arguments
     *
     * @param V the Blackbird visitor
     * @param ctx `ArgumentsContext`
     * @return the number of arguments present
     */
    int _get_num_args(Visitor *V, blackbirdParser::ArgumentsContext *ctx) {
        std::vector<blackbirdParser::ValContext*> vals = ctx->val();
        return vals.size();
    }

    /**
     * Factory function to create Blackbird operations corresponding
     * to those provided in the Blackbird script.
     *
     * @param ctx `ArgumentsContext`
     * @param modes `std::vector<int>` containing the modes the operation is applied to
     * @return the operation
     */
    template <class O>
    O* Visitor::_create_operation(blackbirdParser::ArgumentsContext *ctx, intvec modes) {
        if (var_type == "float") {
            floatvec args;
            double s;
            args = _get_mult_expr_args(this, ctx, args, s);
            O* op = new O(args, modes);
            return op;
        }
        else if (var_type == "complex") {
            complexvec args;
            std::complex<double> s;
            args = _get_mult_expr_args(this, ctx, args, s);
            O* op = new O(args, modes);
            return op;
        }
        else if (var_type == "int") {
            intvec args;
            int s;
            args = _get_mult_expr_args(this, ctx, args, s);
            O* op = new O(args, modes);
            return op;
        }
    }

    /**
     * Defines what to do as each quantum operation in the device context is visited.
     *
     * In general, this includes:
     *
     *   * Getting the number of modes the operation is applied to using `split_string_to_ints`
     *
     *   * If the statement is an operation:
     *
     *     - Get the number of arguments/types of the arguments
     *
     *     - Evaluate the arguments
     *
     *     - Use `_create_operation` template to create the new operation object, acting
     *
     *       on the specified number of modes, with the specified arguments
     *
     *     - Add this operation to the `program->operations` vector.
     *
     *   * Repeat the previous steps for any measurements.
     *
     * @param ctx `StatementContext`
     * @return 0 to specify correct visitation.
     */
    antlrcpp::Any Visitor::visitStatement(blackbirdParser::StatementContext *ctx) {
        intvec modes = split_string_to_ints(ctx->modes()->getText());

        if (ctx->operation()) {
            var_name = ctx->operation()->NAME()->getText();

            // state preparations
            if (var_name == "Vacuum" or var_name == "Vac") {
                Vacuum* op = new Vacuum(modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Coherent") {
                int num_args = _get_num_args(this, ctx->arguments());
                if (num_args == 2) {
                    var_type = "float";
                }
                else if (num_args == 1) {
                    var_type = "complex";
                }
                Coherent* op = _create_operation<Coherent>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Squeezed") {
                var_type = "float";
                Squeezed* op = _create_operation<Squeezed>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "DisplacedSqueezed") {
                std::vector<blackbirdParser::ValContext*> vals = ctx->arguments()->val();

                std::complex<double> alpha;
                double r;
                double p;

                if (vals.size() == 3) {
                    var_type = "complex";
                    alpha = _expression(this, vals[0]->expression(), alpha);
                    var_type = "float";
                    r = _expression(this, vals[1]->expression(), r);
                    p = _expression(this, vals[2]->expression(), p);
                }
                else {
                    throw std::invalid_argument("DisplacedSqueezed requires 3 arguments.");
                }

                floatvec sq_args = {r, p};
                Squeezed* op1 = new Squeezed(sq_args, modes);

                complexvec d_args = {alpha};
                Dgate* op2 = new Dgate(d_args, modes);

                program->operations.push_back(op1);
                program->operations.push_back(op2);
            }
            else if (var_name == "Thermal") {
                var_type = "float";
                Thermal* op = _create_operation<Thermal>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Fock") {
                var_type = "int";
                Fock* op = _create_operation<Fock>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Catstate") {
                std::vector<blackbirdParser::ValContext*> vals = ctx->arguments()->val();

                std::complex<double> alpha;
                double parity = 0.;

                if (vals.size() == 1) {
                    var_type = "complex";
                    alpha = _expression(this, vals[0]->expression(), alpha);
                }
                else if (vals.size() == 2) {
                    var_type = "complex";
                    alpha = _expression(this, vals[0]->expression(), alpha);
                    var_type = "float";
                    parity = _expression(this, vals[1]->expression(), parity);
                }
                else {
                    throw std::invalid_argument("Catstate requires 3 arguments.");
                }

                complexvec args = {alpha};
                Catstate* op = new Catstate(args, modes, parity);
                program->operations.push_back(op);
            }
            // gates
            else if (var_name == "Rgate") {
                var_type = "float";
                Rgate* op = _create_operation<Rgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Fouriergate") {
                var_type = "float";
                floatvec phi;
                phi.push_back(M_PI/2.0);
                Rgate* op = new Rgate(phi, modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Dgate") {
                int num_args = _get_num_args(this, ctx->arguments());
                if (num_args == 2) {
                    var_type = "float";
                }
                else if (num_args == 1) {
                    var_type = "complex";
                }
                Dgate* op = _create_operation<Dgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Sgate") {
                var_type = "float";
                Sgate* op = _create_operation<Sgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Xgate") {
                var_type = "float";
                Xgate* op = _create_operation<Xgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Zgate") {
                var_type = "float";
                Zgate* op = _create_operation<Zgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Pgate") {
                var_type = "float";
                Pgate* op = _create_operation<Pgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Vgate") {
                var_type = "float";
                Vgate* op = _create_operation<Vgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            // multi-mode gates
            else if (var_name == "BSgate") {
                var_type = "float";
                BSgate* op = _create_operation<BSgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "S2gate") {
                var_type = "float";
                S2gate* op = _create_operation<S2gate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "CXgate") {
                var_type = "float";
                CXgate* op = _create_operation<CXgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "CZgate") {
                var_type = "float";
                CZgate* op = _create_operation<CZgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "CKgate") {
                var_type = "float";
                CKgate* op = _create_operation<CKgate>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            // channels
            else if (var_name == "LossChannel") {
                var_type = "float";
                LossChannel* op = _create_operation<LossChannel>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "ThermalLossChannel") {
                var_type = "float";
                ThermalLossChannel* op = _create_operation<ThermalLossChannel>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            // decompositions
            else if (var_name == "Interferometer") {
                blackbirdParser::ExpressionContext *expr = ctx->arguments()->val()[0]->expression();
                blackbirdParser::VariableLabelContext *var = dynamic_cast<blackbirdParser::VariableLabelContext*>(expr);

                complexmat U = complexmat_vars[var->NAME()->getText()];

                Interferometer* op = new Interferometer(U, modes);
                program->operations.push_back(op);
            }
            else if (var_name == "GaussianTransform") {
                blackbirdParser::ExpressionContext *expr = ctx->arguments()->val()[0]->expression();
                blackbirdParser::VariableLabelContext *var = dynamic_cast<blackbirdParser::VariableLabelContext*>(expr);

                floatmat S = floatmat_vars[var->NAME()->getText()];

                GaussianTransform* op = new GaussianTransform(S, modes);
                program->operations.push_back(op);
            }
            else if (var_name == "Gaussian") {
                std::vector<blackbirdParser::ValContext*> vals = ctx->arguments()->val();

                floatmat S1;
                floatmat S2;

                if (vals.size() == 1) {
                    blackbirdParser::VariableLabelContext *var = dynamic_cast<blackbirdParser::VariableLabelContext*>(vals[0]->expression());
                    S1 = floatmat_vars[var->NAME()->getText()];
                    Gaussian* op = new Gaussian(S1, modes);
                    program->operations.push_back(op);
                }
                else if (vals.size() == 2) {
                    blackbirdParser::VariableLabelContext *var0 = dynamic_cast<blackbirdParser::VariableLabelContext*>(vals[0]->expression());
                    S1 = floatmat_vars[var0->NAME()->getText()];

                    blackbirdParser::VariableLabelContext *var1 = dynamic_cast<blackbirdParser::VariableLabelContext*>(vals[1]->expression());
                    S2 = floatmat_vars[var1->NAME()->getText()];

                    Gaussian* op = new Gaussian(S1, S2, modes);
                    program->operations.push_back(op);
                }
                else {
                    throw std::invalid_argument("Gaussian operation requires 1 or 2 arguments.");
                }
            }
            else {
                throw std::invalid_argument("Unknown operation: "+var_name);
            }
        }
        else if (ctx->measure()) {
            var_name = ctx->measure()->MEASURE()->getText();
            // Measurements
            if (var_name == "MeasureFock" or var_name == "Measure") {
                MeasureFock* op = new MeasureFock(modes);
                program->operations.push_back(op);
            }
            else if (var_name == "MeasureIntensity") {
                MeasureIntensity* op = new MeasureIntensity(modes);
                program->operations.push_back(op);
            }
            else if (var_name == "MeasureHeterodyne") {
                MeasureHeterodyne* op = new MeasureHeterodyne(modes);
                program->operations.push_back(op);
            }
            else if (var_name == "MeasureHomodyne") {
                var_type = "float";
                MeasureHomodyne* op = _create_operation<MeasureHomodyne>(ctx->arguments(), modes);
                program->operations.push_back(op);
            }
            else if (var_name == "MeasureX") {
                MeasureHomodyne* op = new MeasureHomodyne(modes);
                program->operations.push_back(op);
            }
            else if (var_name == "MeasureP") {
                floatvec args = {M_PI/2.0};
                MeasureHomodyne* op = new MeasureHomodyne(args, modes);
                program->operations.push_back(op);
            }
            else {
                throw std::invalid_argument("Unknown measurement: "+var_name);
            }
        }
        return 0;
    }


    /**
     * Defines what to do as each quantum operation in the device context is visited.
     *
     * In general, this includes:
     *
     *   * Getting the number of modes the operation is applied to using `split_string_to_ints`
     *
     *   * If the statement is an operation:
     *
     *     - Get the number of arguments/types of the arguments
     *
     *     - Evaluate the arguments
     *
     *     - Use `_create_operation` template to create the new operation object, acting
     *
     *       on the specified number of modes, with the specified arguments
     *
     *     - Add this operation to the `program->operations` vector.
     *
     *   * Repeat the previous steps for any measurements.
     *
     * @param ctx `StatementContext`
     * @return 0 to specify correct visitation.
     */
    antlrcpp::Any Visitor::visitProgram(blackbirdParser::ProgramContext *ctx) {
        // Visit the quantum program

        // get the device name
        std::string dev_name = ctx->device()->getText();

        if (dev_name == "Chip0") {
            static Chip0 prog;

            // get options
            std::vector<blackbirdParser::KwargContext*> kwargs = ctx->arguments()->kwarg();

            for (auto i : kwargs) {
                var_name = i->NAME()->getText();
                if (var_name == "shots") {
                    var_type = "int";
                    int s;
                    prog.shots = _expression(this, i->val()->expression(), s);
                }
                else {
                    throw std::invalid_argument("Unknown keyword argument "+var_name);
                }
            }

            program = &prog;
        }
        else if (dev_name == "gaussian") {
            static GaussianSimulator prog;

            // get options
            std::vector<blackbirdParser::KwargContext*> kwargs = ctx->arguments()->kwarg();

            for (auto i : kwargs) {
                var_name = i->NAME()->getText();
                if (var_name == "shots") {
                    var_type = "int";
                    prog.shots = _expression(this, i->val()->expression(), prog.shots);
                }
                else if (var_name == "hbar") {
                    var_type = "float";
                    prog.hb = _expression(this, i->val()->expression(), prog.hb);
                }
                else if (var_name == "num_subsystems") {
                    var_type = "int";
                    prog.ns = _expression(this, i->val()->expression(), prog.ns);
                }
                else {
                    throw std::invalid_argument("Unknown keyword argument "+var_name);
                }
            }

            program = &prog;
        }
        else if (dev_name == "fock") {
            static FockSimulator prog;

            // get options
            std::vector<blackbirdParser::KwargContext*> kwargs = ctx->arguments()->kwarg();

            for (auto i : kwargs) {
                var_name = i->NAME()->getText();
                if (var_name == "shots") {
                    var_type = "int";
                    prog.shots = _expression(this, i->val()->expression(), prog.shots);
                }
                else if (var_name == "hbar") {
                    var_type = "float";
                    prog.hb = _expression(this, i->val()->expression(), prog.hb);
                }
                else if (var_name == "num_subsystems") {
                    var_type = "int";
                    prog.ns = _expression(this, i->val()->expression(), prog.ns);
                }
                else if (var_name == "cutoff_dim") {
                    var_type = "int";
                    prog.cutoff = _expression(this, i->val()->expression(), prog.cutoff);
                }
                else {
                    throw std::invalid_argument("Unknown keyword argument "+var_name);
                }
            }

            program = &prog;
        }
        else {
            throw std::invalid_argument("Unknown device "+dev_name);
        }

        return visitChildren(ctx);
    }


    /**
     * Starts the visitation process of parsing the Blackbird code.
     *
     * @param ctx `StartContext`
     * @return returns the blackbird program, containing device information,
     * metadata, and the quantum program to run
     */
    antlrcpp::Any Visitor::visitStart(blackbirdParser::StartContext *ctx) {
        visitChildren(ctx);
        return program;
    }

}