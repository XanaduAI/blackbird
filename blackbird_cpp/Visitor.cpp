#include <regex>

#include "Visitor.h"


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


complexmat _array(Visitor *V, blackbirdParser::ArrayVariableLabelContext *ctx, std::complex<double> t) {
    complexmat array;

    std::vector<blackbirdParser::ArrayrowContext*> arrayrow = ctx->arrayval()->arrayrow();
    for (auto i : arrayrow) {
        array.push_back(V->visitArrayrow(i));
    }

    return array;
}

floatmat _array(Visitor *V, blackbirdParser::ArrayVariableLabelContext *ctx, double t) {
    floatmat array;

    std::vector<blackbirdParser::ArrayrowContext*> arrayrow = ctx->arrayval()->arrayrow();
    for (auto i : arrayrow) {
        array.push_back(V->visitArrayrow(i));
    }

    return array;
}

intmat _array(Visitor *V, blackbirdParser::ArrayVariableLabelContext *ctx, int t) {
    intmat array;

    std::vector<blackbirdParser::ArrayrowContext*> arrayrow = ctx->arrayval()->arrayrow();
    for (auto i : arrayrow) {
        array.push_back(V->visitArrayrow(i));
    }

    return array;
}



antlrcpp::Any Visitor::visitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext *ctx) {
    // get array name
    std::string array_name = ctx->name()->getText();

    // get array type
    array_type = ctx->vartype()->getText();

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

    if (array_type == "complex"){
        std::complex<double> t;
        complexmat array;
        array = _array(this, ctx, t);
        complexmat_vars[array_name] = array;
        var_types[array_name] = "complexmat";
    }
    else if (array_type == "float") {
        double t;
        floatmat array;
        array = _array(this, ctx, t);
        floatmat_vars[array_name] = array;
        var_types[array_name] = "floatmat";
    }
    else if (array_type == "int") {
        int t;
        intmat array;
        array = _array(this, ctx, t);
        intmat_vars[array_name] = array;
        var_types[array_name] = "intmat";
    }
}


antlrcpp::Any Visitor::visitArrayrow(blackbirdParser::ArrayrowContext *ctx) {
    std::vector<blackbirdParser::ExpressionContext*> col = ctx->expression();

    if (array_type == "complex"){
        complexvec row;
        for (auto i : col) {
            row.push_back(visitChildren(i));
        }
        return row;
    }
    else if (array_type == "float") {
        floatvec row;
        for (auto i : col) {
            row.push_back(visitChildren(i));
        }
        return row;
    }
    else if (array_type == "int") {
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

antlrcpp::Any Visitor::visitExpressionVariableLabel(blackbirdParser::ExpressionVariableLabelContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitNumber(blackbirdParser::NumberContext *ctx) {
    visitChildren(ctx);

    std::string num_string = ctx->getText();

    if (ctx->COMPLEX()) {
        std::complex<double> number = _complex(num_string);
        return number;
    }
    else if (ctx->FLOAT()){
        double number = _float(num_string);
        return number;
    }
    else if (ctx->INT()){
        int number = std::stoi(num_string);
        return number;
    }
    else if (ctx->PI()){
        return M_PI;
    }
    else {
        throw std::invalid_argument("Unknown number");
    }
}
