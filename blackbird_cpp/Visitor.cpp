#include <string>
#include <iostream>

#include "Visitor.h"

antlrcpp::Any Visitor::visitArrayVariableLabel(blackbirdParser::ArrayVariableLabelContext *ctx) {
    std::cout << ctx->name()->getText() << std::endl;
    if(ctx->shape()){
    	std::cout << ctx->shape()->getText() << std::endl;
    }
	return visitChildren(ctx);
}


antlrcpp::Any Visitor::visitArrayrow(blackbirdParser::ArrayrowContext *ctx) {
	return visitChildren(ctx);
}


antlrcpp::Any Visitor::visitArrayval(blackbirdParser::ArrayvalContext *ctx) {
	visitChildren(ctx);
	if(ctx->getText() != ","){
    	std::cout << ctx->getText() << std::endl;
    }
}