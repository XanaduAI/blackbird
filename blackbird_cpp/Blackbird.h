#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <cmath>
#include <complex>
#include <stdexcept>
#include <unordered_map>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdLexer.h"
#include "blackbirdParser.h"
#include "blackbirdBaseVisitor.h"

#include "BlackbirdProgram.h"

namespace blackbird {

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

        Program* program;

        template <class O>
        O* _create_operation(blackbirdParser::ArgumentsContext *ctx, intvec modes);

        antlrcpp::Any visitNumber(blackbirdParser::NumberContext *ctx);
        antlrcpp::Any visitExpressionvar(blackbirdParser::ExpressionvarContext *ctx);

        antlrcpp::Any visitArrayvar(blackbirdParser::ArrayvarContext *ctx);
        antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext*);

        antlrcpp::Any visitStatement(blackbirdParser::StatementContext *ctx);
        antlrcpp::Any visitProgram(blackbirdParser::ProgramContext *ctx);

        antlrcpp::Any visitStart(blackbirdParser::StartContext *ctx);
    };

    Program* parse(std::ifstream &stream);
    Program* parse(std::string &s_input);
}
