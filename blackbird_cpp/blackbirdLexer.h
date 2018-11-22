
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  blackbirdLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, FLOAT = 2, COMPLEX = 3, STR = 4, BOOL = 5, SEQUENCE = 6, PI = 7, 
    NEWLINE = 8, TAB = 9, SPACE = 10, WITH = 11, SQRT = 12, SIN = 13, COS = 14, 
    EXP = 15, PLUS = 16, MINUS = 17, TIMES = 18, DIVIDE = 19, PWR = 20, 
    ASSIGN = 21, PERIOD = 22, COMMA = 23, COLON = 24, QUOTE = 25, LBRAC = 26, 
    RBRAC = 27, LSQBRAC = 28, RSQBRAC = 29, APPLY = 30, TYPE_ARRAY = 31, 
    TYPE_FLOAT = 32, TYPE_COMPLEX = 33, TYPE_INT = 34, TYPE_STR = 35, TYPE_BOOL = 36, 
    MEASURE = 37, OPERATION = 38, NAME = 39, DEVICE = 40, COMMENT = 41, 
    ANY = 42
  };

  blackbirdLexer(antlr4::CharStream *input);
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

