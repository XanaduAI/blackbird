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


antlrcpp::Any Visitor::visitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext *ctx) {
    // get array name
    std::string array_name = ctx->name()->getText();
    std::cout << array_name << std::endl;

    // get array type
    std::string array_type = ctx->vartype()->getText();

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
    else {
        throw std::invalid_argument("Must specify array shapes when using the Blackbird C++ parser");
    }

    complexmat array;

    std::vector<blackbirdParser::ArrayrowContext*> arrayrow = ctx->arrayval()->arrayrow();
    for (auto i : arrayrow) {
        array.push_back(visitArrayrow(i));
    }

    for (auto i : array) {
        for (auto j : i) {
            std::cout << j << ',' << ' ';
        }
        std::cout << std::endl;
    }
}


antlrcpp::Any Visitor::visitArrayrow(blackbirdParser::ArrayrowContext *ctx) {
    // if(ctx->getText() != ","){
    //     std::cout << ctx->expression() << std::endl;
    // }
    complexvec row;

    std::vector<blackbirdParser::ExpressionContext*> col = ctx->expression();

    for (auto i : col) {
        row.push_back(visitChildren(i));
    }
    return row;
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
        return 0;
    }
}
