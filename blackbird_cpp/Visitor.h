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
    antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx);
	antlrcpp::Any visitVarblock(blackbirdParser::VarblockContext *ctx);
    antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *ctx);
};
