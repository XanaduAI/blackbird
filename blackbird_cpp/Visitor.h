#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <cmath>
#include <complex>
#include <stdexcept>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdBaseVisitor.h"

typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

class  Visitor : public blackbirdBaseVisitor {
public:
    antlrcpp::Any visitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext *ctx);
    antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext *ctx);
    antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext *ctx);
    antlrcpp::Any visitExpressionVariableLabel(blackbirdParser::ExpressionVariableLabelContext *ctx);
    antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx);
};
