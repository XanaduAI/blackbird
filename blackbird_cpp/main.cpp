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
    if (program->name == Device::Chip0) {
        Chip0* p = static_cast<Chip0*>(program);
        std::cout << "Device: Chip0" << std::endl;
        std::cout << "Shots: " << p->shots << std::endl;
    }
    std::cout << std::endl;

    // print operations;
    for (auto i : program->operations) {
        if (i->gate == Gate::Coherent) {
            // print state preparation
            Coherent* g = static_cast<Coherent*>(i);
            std::cout << "Coherent(" << g->a << ", " << g->p << ") | ";
            for (auto j : g->modes) {
                    std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        }
        else if (i->gate == Gate::Interferometer) {
            // print interferometer
            Interferometer* g = static_cast<Interferometer*>(i);
            std::cout << "Interferometer(" << std::endl;
            for (auto j : g->U) {
                for (auto k : j) {
                        std::cout << k << ',' << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << ") | ";
            for (auto j : g->modes) {
                    std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        }
        else if (i->gate == Gate::MeasureIntensity) {
            // print measurements
            MeasureIntensity* g = static_cast<MeasureIntensity*>(i);
            std::cout << "MeasureIntensity() | ";
            for (auto j : g->modes) {
                    std::cout << j << ',' << ' ';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
