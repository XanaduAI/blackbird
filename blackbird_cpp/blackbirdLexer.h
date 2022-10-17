
// Generated from blackbird.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  blackbirdLexer : public antlr4::Lexer {
public:
  enum {
    PLUS = 1, MINUS = 2, TIMES = 3, DIVIDE = 4, PWR = 5, ASSIGN = 6, FOR = 7, 
    IN = 8, INT = 9, FLOAT = 10, COMPLEX = 11, STR = 12, BOOL = 13, SEQUENCE = 14, 
    PI = 15, NEWLINE = 16, TAB = 17, SPACE = 18, PROGNAME = 19, VERSION = 20, 
    TARGET = 21, PROGTYPE = 22, INCLUDE = 23, SQRT = 24, SIN = 25, COS = 26, 
    TAN = 27, ARCSIN = 28, ARCCOS = 29, ARCTAN = 30, SINH = 31, COSH = 32, 
    TANH = 33, ARCSINH = 34, ARCCOSH = 35, ARCTANH = 36, EXP = 37, LOG = 38, 
    PERIOD = 39, COMMA = 40, COLON = 41, QUOTE = 42, LBRAC = 43, RBRAC = 44, 
    LSQBRAC = 45, RSQBRAC = 46, LBRACE = 47, RBRACE = 48, APPLY = 49, TYPE_ARRAY = 50, 
    TYPE_FLOAT = 51, TYPE_COMPLEX = 52, TYPE_INT = 53, TYPE_STR = 54, TYPE_BOOL = 55, 
    REGREF = 56, MEASURE = 57, NAME = 58, DEVICE = 59, COMMENT = 60, ANY = 61
  };

  explicit blackbirdLexer(antlr4::CharStream *input);
  ~blackbirdLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

