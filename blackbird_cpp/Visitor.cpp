#include <regex>

#include "Visitor.h"
#include "Variables.h"

// ===========================
// Number auxillary functions
// ===========================

std::vector<int> split_string_to_ints(std::string string_list) {
    // Split a string of the form "0, 6, 2, 1"
    // into a list of integers
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


std::complex<double> _complex(std::string num_string) {
    // Convert a string containing a Blackbird-style complex
    // number to a C++ complex double.
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


double _float(std::string num_string) {
    // Convert a string containing a Blackbird-style real
    // number to a C++ complex double.
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

template <typename T>
void _set_expression_variable(Visitor* V, blackbirdParser::ExpressionvarContext *ctx, T val) {
    T result =  _expression(V, ctx->expression(), val);
    variable_map<T>::setVal(V, ctx->name()->getText(), result);
}

template <typename T>
void _set_non_numeric_variable(Visitor* V, blackbirdParser::ExpressionvarContext *ctx, T val) {
    std::string result = ctx->nonnumeric()->getText();
    variable_map<T>::setVal(V, ctx->name()->getText(), result);
}

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

// Extract array values
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


antlrcpp::Any Visitor::visitStatement(blackbirdParser::StatementContext *ctx) {
    intvec modes = split_string_to_ints(ctx->modes()->getText());

    if (ctx->operation()) {
        var_name = ctx->operation()->NAME()->getText();
        if (var_name == "Coherent") {
            var_type = "float";

            floatvec args;
            double s;

            args = _get_mult_expr_args(this, ctx->arguments(), args, s);

            Coherent* op = new Coherent(args[0], args[1], modes);
            program->operations.push_back(op);
        }
        else if (var_name == "Interferometer") {
            var_type = "complex";
            std::complex<double> s;

            blackbirdParser::ExpressionContext *expr = ctx->arguments()->val()[0]->expression();
            blackbirdParser::VariableLabelContext *var = dynamic_cast<blackbirdParser::VariableLabelContext*>(expr);

            complexmat U = complexmat_vars[var->NAME()->getText()];

            Interferometer* op = new Interferometer(U, modes);
            program->operations.push_back(op);
        }
        else if (var_name == "MeasureIntensity") {
            MeasureIntensity* op = new MeasureIntensity(modes);
            program->operations.push_back(op);
        }
        else {
            throw std::invalid_argument("Unknown operation "+var_name);
        }
    }
    return 0;
}


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
    else {
        throw std::invalid_argument("Unknown device "+dev_name);
    }

    return visitChildren(ctx);
}


antlrcpp::Any Visitor::visitStart(blackbirdParser::StartContext *ctx) {
    visitChildren(ctx);
    return program;
}
