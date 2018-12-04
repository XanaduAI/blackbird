#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <cmath>
#include <complex>
#include <stdexcept>
#include <unordered_map>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdBaseVisitor.h"
#include "Operations.h"

typedef std::vector<std::vector<std::complex<double>>> complexmat;
typedef std::vector<std::complex<double>> complexvec;

typedef std::vector<std::vector<double>> floatmat;
typedef std::vector<double> floatvec;

typedef std::vector<std::vector<int>> intmat;
typedef std::vector<int> intvec;


template <class DstType, class SrcType>
bool is_type(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}


class  Visitor : public blackbirdBaseVisitor {
private:
    std::string var_type;
    std::string var_name;
public:
    std::unordered_map<std::string, std::complex<double>> complex_vars;
    std::unordered_map<std::string, double> float_vars;
    std::unordered_map<std::string, int> int_vars;
    std::unordered_map<std::string, std::string> str_vars;
    std::unordered_map<std::string, bool> bool_vars;

    std::unordered_map<std::string, complexmat> complexmat_vars;
    std::unordered_map<std::string, floatmat> floatmat_vars;
    std::unordered_map<std::string, intmat> intmat_vars;

    std::vector<Operation> operations;

    antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx);
    antlrcpp::Any visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx);

    antlrcpp::Any visitArrayvar(blackbirdParser::ArrayvarContext *ctx);
    antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext*);
    antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext*);

    antlrcpp::Any visitStatement(blackbirdParser::StatementContext *ctx);

    antlrcpp::Any visitVarblock(blackbirdParser::VarblockContext *ctx);
    antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *ctx);
    antlrcpp::Any visitStart(blackbirdParser::StartContext *ctx);
};
