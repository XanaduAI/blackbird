#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <cmath>
#include <complex>
#include <stdexcept>
#include <unordered_map>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdBaseVisitor.h"

typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

typedef std::vector<std::vector<double>> floatmat;
typedef std::vector<double> floatvec;

typedef std::vector<std::vector<int>> intmat;
typedef std::vector<int> intvec;

class  Visitor : public blackbirdBaseVisitor {
public:
	std::unordered_map<std::string, std::string> var_types;
	std::unordered_map<std::string, complexmat> complexmat_vars;
	std::unordered_map<std::string, floatmat> floatmat_vars;
	std::unordered_map<std::string, intmat> intmat_vars;
	std::string array_type;
    antlrcpp::Any visitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext *ctx);
    antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext *ctx);
    antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext *ctx);
    antlrcpp::Any visitExpressionVariableLabel(blackbirdParser::ExpressionVariableLabelContext *ctx);
    antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx);
};
