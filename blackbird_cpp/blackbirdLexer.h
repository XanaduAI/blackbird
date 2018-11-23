
// Generated from blackbird.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  blackbirdLexer : public antlr4::Lexer {
public:
  enum {
    PLUS = 1, MINUS = 2, TIMES = 3, DIVIDE = 4, PWR = 5, ASSIGN = 6, INT = 7, 
    FLOAT = 8, COMPLEX = 9, STR = 10, BOOL = 11, SEQUENCE = 12, PI = 13, 
    NEWLINE = 14, TAB = 15, SPACE = 16, WITH = 17, SQRT = 18, SIN = 19, 
    COS = 20, EXP = 21, PERIOD = 22, COMMA = 23, COLON = 24, QUOTE = 25, 
    LBRAC = 26, RBRAC = 27, LSQBRAC = 28, RSQBRAC = 29, APPLY = 30, TYPE_ARRAY = 31, 
    TYPE_FLOAT = 32, TYPE_COMPLEX = 33, TYPE_INT = 34, TYPE_STR = 35, TYPE_BOOL = 36, 
    MEASURE = 37, NAME = 38, DEVICE = 39, COMMENT = 40, ANY = 41
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

