#include <string>
#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdBaseVisitor.h"

class  Visitor : public blackbirdBaseVisitor {
public:
    antlrcpp::Any visitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext *ctx);
    antlrcpp::Any visitArrayrow(blackbirdParser::ArrayrowContext *ctx);
    antlrcpp::Any visitArrayval(blackbirdParser::ArrayvalContext *ctx);
};
