#include <regex>

#include "Visitor.h"


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


antlrcpp::Any Visitor::visitNumber(blackbirdParser::NumberContext *ctx) {
    // Visit a number, and convert it into the correct type
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


antlrcpp::Any Visitor::visitVarblock(blackbirdParser::VarblockContext *ctx) {
    // Visit the variable block
    visitChildren(ctx);

    // Extract all variables
    std::cout << "Variables: ";
    for (auto j : ctx->var_list) {
        // j->vartype() is a string
        std::cout << j->vartype()->getText() << " ";
        // j->name() is a string
        std::cout << j->name()->getText() << " ";
        if (j->expression()) {
            // j->expression() is an expression
            std::cout << j->expression()->getText() << " ";
        }
        else if (j->nonnumeric()) {
            // j->nonnumeric() is an string
            std::cout << j->nonnumeric()->getText() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;


    // Extract all arrays
    std::cout << "Arrays: ";
    for (auto i : ctx->array_list) {
        // i->vartype() is a string
        std::cout << i->vartype()->getText() << " ";
        // i->name() is a string
        std::cout << i->name()->getText() << std::endl;

        // get array name
        std::string array_name = i->name()->getText();

        // get array type
        std::string array_type = i->vartype()->getText();

        // get array shape
        int rows;
        int cols;
        if(i->shape()){
            std::vector<int> shape = split_string_to_ints(i->shape()->getText());
            rows = shape[0];
            cols = shape[1];
        }

        // get array elements
        if (array_type == "complex"){
            complexmat array;
            // get the rows of the array
            for (auto j : i->arrayval()->row_list) {
                complexvec row;
                std::vector<blackbirdParser::ExpressionContext*> col = j->expression();
                // get the elements of the row
                for (auto k : col) {
                    row.push_back(visitChildren(k));
                }
                array.push_back(row);
            }
            // print array
            for (auto i : array) {
                for (auto j : i) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            }
        }
        else if (array_type == "float") {
            floatmat array;
            // get the rows of the array
            for (auto j : i->arrayval()->row_list) {
                floatvec row;
                std::vector<blackbirdParser::ExpressionContext*> col = j->expression();
                // get the elements of the row
                for (auto k : col) {
                    row.push_back(visitChildren(k));
                }
                array.push_back(row);
            }
            // print array
            for (auto i : array) {
                for (auto j : i) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            }
        }
        else if (array_type == "int") {
            intmat array;
            // get the rows of the array
            for (auto j : i->arrayval()->row_list) {
                intvec row;
                std::vector<blackbirdParser::ExpressionContext*> col = j->expression();
                // get the elements of the row
                for (auto k : col) {
                    row.push_back(visitChildren(k));
                }
                array.push_back(row);
            }
            // print array
            for (auto i : array) {
                for (auto j : i) {
                    std::cout << j << ',' << ' ';
                }
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    return 0;
}


antlrcpp::Any Visitor::visitProgram(blackbirdParser::ProgramContext *ctx) {
    // Visit the quantum program
    visitChildren(ctx);

    // get device name
    std::cout << "Device: ";
    std::cout << ctx->device()->getText() << std::endl;

    // get device arguments
    std::cout << "Device parameters: ";
    for (auto i : ctx->arguments()->val_list) {
        // i is an expression
        std::cout << i->getText();
    }
    for (auto i : ctx->arguments()->kwarg_list) {
        // i->NAME() is the parameter name
        // i->val() is an expression
        std::cout << i->NAME()->getText() << ":" << i->val()->getText() << "; ";
    }
    std::cout << std::endl << std::endl;

    // get operations, parameters, and modes
    for (auto i : ctx->statement_list) {
        // get operation name
        std::cout << "Operation: " << i->operation()->getText() << std::endl;

        // get parameters
        std::cout << "Parameters: ";
        for (auto j : i->arguments()->val_list) {
            // j is an expression
            std::cout << j->getText() << "; ";
        }
        for (auto j : i->arguments()->kwarg_list) {
            // j->NAME() is the parameter name
            // j->val() is an expression
            std::cout << j->NAME()->getText() << ":" << j->val()->getText() << "; ";
        }
        std::cout << std::endl;

        // generate the vector of modes that the operation is applied to
        std::vector<int> modes = split_string_to_ints(i->modes()->getText());

        std::cout << "Modes: ";
        for (auto j : modes) {
            std::cout << j << "; ";
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}
