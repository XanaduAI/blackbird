
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  blackbirdLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, FLOAT = 2, COMPLEX = 3, STR = 4, BOOL = 5, SEQUENCE = 6, PI = 7, 
    NEWLINE = 8, TAB = 9, SPACE = 10, WITH = 11, MEASURE = 12, OPERATION = 13, 
    SQRT = 14, SIN = 15, COS = 16, EXP = 17, PLUS = 18, MINUS = 19, TIMES = 20, 
    DIVIDE = 21, PWR = 22, ASSIGN = 23, PERIOD = 24, COMMA = 25, COLON = 26, 
    QUOTE = 27, LBRAC = 28, RBRAC = 29, LSQBRAC = 30, RSQBRAC = 31, APPLY = 32, 
    TYPE_ARRAY = 33, TYPE_FLOAT = 34, TYPE_COMPLEX = 35, TYPE_INT = 36, 
    TYPE_STR = 37, TYPE_BOOL = 38, COMMENT = 39, NAME = 40, ANY = 41
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

