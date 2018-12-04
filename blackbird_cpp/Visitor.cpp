#include <regex>

#include "Visitor.h"

template<typename T>
struct variable_map;

template <class DstType, class SrcType>
bool is_type(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}


// ===========================
// Define the variable maps
// ===========================


template<>
struct variable_map<int>
{
    static int getVal(Visitor *V, std::string key) {
        auto iter1 = V->int_vars.find(key);
        auto iter2 = V->float_vars.find(key);
        auto iter3 = V->complex_vars.find(key);

        int val;

        if (iter1 != V->int_vars.end()) {
            val = iter1->second;
        }
        else if (iter2 != V->float_vars.end()) {
            val = iter2->second;
        }
        else if (iter3 != V->complex_vars.end()) {
            std::invalid_argument("Cannot convert a complex variable to an int");
        }

        return val;
    }
    static int setVal(Visitor *V, std::string key, int val) {
        V->int_vars[key] = val;
        return 0;
    }
};

template<>
struct variable_map<double>
{
    static double getVal(Visitor *V, std::string key) {
        auto iter1 = V->float_vars.find(key);
        auto iter2 = V->int_vars.find(key);
        auto iter3 = V->complex_vars.find(key);

        double val;

        if (iter1 != V->float_vars.end()) {
            val = iter1->second;
        }
        else if (iter2 != V->int_vars.end()) {
            val = iter2->second;
        }
        else if (iter3 != V->complex_vars.end()) {
            std::invalid_argument("Cannot convert a complex variable to an float");
        }

        return val;
    }
    static double setVal(Visitor *V, std::string key, double val) {
        V->float_vars[key] = val;
        return 0;
    }
};


template<>
struct variable_map<std::complex<double>>
{
    static std::complex<double> getVal(Visitor *V, std::string key) {
        auto iter1 = V->complex_vars.find(key);
        auto iter2 = V->int_vars.find(key);
        auto iter3 = V->float_vars.find(key);

        std::complex<double> val;

        if (iter1 != V->complex_vars.end()) {
            val = iter1->second;
        }
        else if (iter2 != V->int_vars.end()) {
            val = iter2->second;
        }
        else if (iter3 != V->float_vars.end()) {
            val = iter3->second;
        }

        return val;
    }
    static std::complex<double> setVal(Visitor *V, std::string key, std::complex<double> val) {
        V->complex_vars[key] = val;
        return 0;
    }
};



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
        std::invalid_argument("Unkown function: "+func->getText());
    }
}

template <typename T>
T _expression(Visitor *V, blackbirdParser::ExpressionContext *ctx, T value) {

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

antlrcpp::Any Visitor::visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx) {
    // get var name
    var_name = ctx->name()->getText();

    // get array type
    var_type = ctx->vartype()->getText();

    if (ctx->expression()) {
        if (var_type == "complex"){
            std::complex<double> value;
            value = _expression(this, ctx->expression(), value);
            complex_vars[var_name] = value;
            var_types[var_name] = "complex";
        }
        else if (var_type == "float"){
            double value;
            value = _expression(this, ctx->expression(), value);
            float_vars[var_name] = value;
            var_types[var_name] = "float";
        }
        else if (var_type == "int"){
            int value;
            value = _expression(this, ctx->expression(), value);
            int_vars[var_name] = value;
            var_types[var_name] = "int";
        }
    }
    else if (ctx->nonnumeric()) {
        if (var_type == "str" and ctx->nonnumeric()->STR()){
            std::string value = ctx->nonnumeric()->getText();
            string_vars[var_name] = value;
            var_types[var_name] = "string";
        } else if (var_type == "bool" and ctx->nonnumeric()->BOOL()){
            std::string value = ctx->nonnumeric()->getText();
            var_types[var_name] = "bool";
            if (value == "True") {
                bool_vars[var_name] = true;
            } else if (value == "False") {
                bool_vars[var_name] = false;
            }
        }
    }
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
        var_types[var_name] = "complexmat";
    }
    else if (var_type == "float") {
        floatmat array;
        array = _array(this, ctx, array);
        floatmat_vars[var_name] = array;
        var_types[var_name] = "floatmat";
    }
    else if (var_type == "int") {
        intmat array;
        array = _array(this, ctx, array);
        intmat_vars[var_name] = array;
        var_types[var_name] = "intmat";
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


antlrcpp::Any Visitor::visitArrayval(blackbirdParser::ArrayvalContext *ctx) {
    return visitChildren(ctx);
}

// =======================
// Quantum program parsing
// =======================


template <typename T, typename S>
T _get_arguments(Visitor *V, blackbirdParser::ArgumentsContext *ctx, T array, S type) {
    std::vector<blackbirdParser::ValContext*> vals = ctx->val();
    for (auto i : vals) {
        if (i->expression()){
            S val;
            array.push_back(_expression(V, i->expression(), val));
        }
        // else if (i->nonnumeric()) {
        //     if (V->var_type == "str" and i->nonnumeric()->STR()){
        //         array.push_back(i->nonnumeric()->getText());
        //     }
        //     else if (V->var_type == "bool" and i->nonnumeric()->BOOL()){
        //         std::string value = i->nonnumeric()->getText();
        //         if (value == "True") {
        //             array.push_back(1);
        //         } else if (value == "False") {
        //             array.push_back(0);
        //         }
        //     }
        // }
    }
    return array;
}

antlrcpp::Any Visitor::visitStatement(blackbirdParser::StatementContext *ctx) {
    if (ctx->operation()) {
        var_name = ctx->operation()->NAME()->getText();
        if (var_name == "Coherent") {
            var_type = "float";
            double s;

            floatvec args;
            args = _get_arguments(this, ctx->arguments(), args, s);
            intvec modes = split_string_to_ints(ctx->modes()->getText());

            std::cout << var_name << "(";
            for (auto i : args) {
                std::cout << i << ',' << ' ';
            }
            std::cout << ") | ";
            for (auto i : modes) {
                std::cout << i << ',' << ' ';
            }
            std::cout << std::endl;
        }
        else if (var_name == "Interferometer") {
            var_type = "complex";
            std::complex<double> s;

            blackbirdParser::ExpressionContext *expr = ctx->arguments()->val()[0]->expression();
            blackbirdParser::VariableLabelContext *var = dynamic_cast<blackbirdParser::VariableLabelContext*>(expr);

            complexmat U = complexmat_vars[var->NAME()->getText()];
            intvec modes = split_string_to_ints(ctx->modes()->getText());

            std::cout << var_name << "(";
            for (auto i : U) {
                for (auto j : i) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << ") | ";
            for (auto i : modes) {
                std::cout << i << ',' << ' ';
            }
            std::cout << std::endl;
        }
        else {
            std::invalid_argument("Unknown operation "+var_name);
        }
    }
    return 0;
}


antlrcpp::Any Visitor::visitVarblock(blackbirdParser::VarblockContext *ctx) {
    // Visit the variable block
    visitChildren(ctx);

    // // Extract all variables
    // std::cout << "Variables: ";
    // for (auto j : ctx->var_list) {
    //     // j->vartype() is a string
    //     std::cout << j->vartype()->getText() << " ";
    //     // j->name() is a string
    //     std::cout << j->name()->getText() << " ";
    //     if (j->expression()) {
    //         // j->expression() is an expression
    //         std::cout << j->expression()->getText() << " ";
    //     }
    //     else if (j->nonnumeric()) {
    //         // j->nonnumeric() is an string
    //         std::cout << j->nonnumeric()->getText() << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl << std::endl;


    // // Extract all arrays
    // std::cout << "Arrays: ";
    // for (auto i : ctx->array_list) {
    //     // i->vartype() is a string
    //     std::cout << i->vartype()->getText() << " ";
    //     // i->name() is a string
    //     std::cout << i->name()->getText() << std::endl;

    //     // get array name
    //     std::string var_name = i->name()->getText();

    //     // get array type
    //     std::string var_type = i->vartype()->getText();

    //     // get array shape
    //     int rows;
    //     int cols;
    //     if(i->shape()){
    //         std::vector<int> shape = split_string_to_ints(i->shape()->getText());
    //         rows = shape[0];
    //         cols = shape[1];
    //     }

    //     // get array elements
    //     if (var_type == "complex"){
    //         complexmat array;
    //         // get the rows of the array
    //         for (auto j : i->arrayval()->row_list) {
    //             complexvec row;
    //             std::vector<blackbirdParser::ExpressionContext*> col = j->expression();
    //             // get the elements of the row
    //             for (auto k : col) {
    //                 row.push_back(visitChildren(k));
    //             }
    //             array.push_back(row);
    //         }
    //         // print array
    //         for (auto i : array) {
    //             for (auto j : i) {
    //                 std::cout << j << ',' << ' ';
    //             }
    //             std::cout << std::endl;
    //         }
    //     }
    //     else if (var_type == "float") {
    //         floatmat array;
    //         // get the rows of the array
    //         for (auto j : i->arrayval()->row_list) {
    //             floatvec row;
    //             std::vector<blackbirdParser::ExpressionContext*> col = j->expression();
    //             // get the elements of the row
    //             for (auto k : col) {
    //                 row.push_back(visitChildren(k));
    //             }
    //             array.push_back(row);
    //         }
    //         // print array
    //         for (auto i : array) {
    //             for (auto j : i) {
    //                 std::cout << j << ',' << ' ';
    //             }
    //             std::cout << std::endl;
    //         }
    //     }
    //     else if (var_type == "int") {
    //         intmat array;
    //         // get the rows of the array
    //         for (auto j : i->arrayval()->row_list) {
    //             intvec row;
    //             std::vector<blackbirdParser::ExpressionContext*> col = j->expression();
    //             // get the elements of the row
    //             for (auto k : col) {
    //                 row.push_back(visitChildren(k));
    //             }
    //             array.push_back(row);
    //         }
    //         // print array
    //         for (auto i : array) {
    //             for (auto j : i) {
    //                 std::cout << j << ',' << ' ';
    //             }
    //             std::cout << std::endl;
    //         }
    //     }

    //     std::cout << std::endl;
    // }
    // std::cout << std::endl << std::endl;

    return 0;
}


antlrcpp::Any Visitor::visitProgram(blackbirdParser::ProgramContext *ctx) {
    // Visit the quantum program
    var_name = "None";
    var_type = "str";
    visitChildren(ctx);

    // get device name
    // std::cout << "Device: ";
    // std::cout << ctx->device()->getText() << std::endl;

    // // get device arguments
    // std::cout << "Device parameters: ";
    // for (auto i : ctx->arguments()->val_list) {
    //     // i is an expression
    //     std::cout << i->getText();
    // }
    // for (auto i : ctx->arguments()->kwarg_list) {
    //     // i->NAME() is the parameter name
    //     // i->val() is an expression
    //     std::cout << i->NAME()->getText() << ":" << i->val()->getText() << "; ";
    // }
    // std::cout << std::endl << std::endl;

    // // get operations, parameters, and modes
    // for (auto i : ctx->statement_list) {
    //     // get operation name
    //     std::cout << "Operation: " << i->operation()->getText() << std::endl;

    //     // get parameters
    //     std::cout << "Parameters: ";
    //     for (auto j : i->arguments()->val_list) {
    //         // j is an expression
    //         std::cout << j->getText() << "; ";
    //     }
    //     for (auto j : i->arguments()->kwarg_list) {
    //         // j->NAME() is the parameter name
    //         // j->val() is an expression
    //         std::cout << j->NAME()->getText() << ":" << j->val()->getText() << "; ";
    //     }
    //     std::cout << std::endl;

    //     // generate the vector of modes that the operation is applied to
    //     std::vector<int> modes = split_string_to_ints(i->modes()->getText());

    //     std::cout << "Modes: ";
    //     for (auto j : modes) {
    //         std::cout << j << "; ";
    //     }
    //     std::cout << std::endl << std::endl;
    // }

    return 0;
}
