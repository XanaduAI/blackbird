#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdLexer.h"
#include "blackbirdParser.h"

#include "Visitor.h"


int main(int argc, const char* argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);

    antlr4::ANTLRInputStream input(stream);
    blackbirdLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    blackbirdParser parser(&tokens);

    blackbirdParser::StartContext* tree = parser.start();
    Visitor visitor;
    Program* program = visitor.visitStart(tree);

    // print device info
    std::cout << std::endl;
    program->print_device_info();
    std::cout << std::endl;
    program->print_operations();

    return 0;
}
