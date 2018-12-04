#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "blackbirdLexer.h"
#include "blackbirdParser.h"
#include "blackbirdBaseListener.h"

#include "Visitor.h"


template <typename T>
void print_array_maps(T array_map) {
  for (auto v : array_map) {
    std::cout << v.first << std::endl;
    for (auto i : v.second) {
        for (auto j : i) {
            std::cout << j << ',' << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


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
  visitor.visitStart(tree);

  // print all variable names and types
  std::cout << "Variables" << std::endl;
  std::cout << "---------" << std::endl;
  for (auto v : visitor.complex_vars) {
    std::cout << v.first << ' ' << v.second << std::endl;
  }
  for (auto v : visitor.float_vars) {
    std::cout << v.first << ' ' << v.second << std::endl;
  }
  for (auto v : visitor.int_vars) {
    std::cout << v.first << ' ' << v.second << std::endl;
  }
  for (auto v : visitor.string_vars) {
    std::cout << v.first << ' ' << v.second << std::endl;
  }
  for (auto v : visitor.bool_vars) {
    std::cout << v.first << ' ' << v.second << std::endl;
  }
  std::cout << std::endl;

  // print all complex arrays
  std::cout << "Complex arrays" << std::endl;
  std::cout << "---------------" << std::endl;
  print_array_maps(visitor.complexmat_vars);

  // print all float arrays
  std::cout << "Float arrays" << std::endl;
  std::cout << "---------------" << std::endl;
  print_array_maps(visitor.floatmat_vars);

  // print all int arrays
  std::cout << "Int arrays" << std::endl;
  std::cout << "---------------" << std::endl;
  print_array_maps(visitor.intmat_vars);

  return 0;
}
