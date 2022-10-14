
// Generated from blackbird.g4 by ANTLR 4.11.1


#include "blackbirdVisitor.h"

#include "blackbirdParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct BlackbirdParserStaticData final {
  BlackbirdParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BlackbirdParserStaticData(const BlackbirdParserStaticData&) = delete;
  BlackbirdParserStaticData(BlackbirdParserStaticData&&) = delete;
  BlackbirdParserStaticData& operator=(const BlackbirdParserStaticData&) = delete;
  BlackbirdParserStaticData& operator=(BlackbirdParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag blackbirdParserOnceFlag;
BlackbirdParserStaticData *blackbirdParserStaticData = nullptr;

void blackbirdParserInitialize() {
  assert(blackbirdParserStaticData == nullptr);
  auto staticData = std::make_unique<BlackbirdParserStaticData>(
    std::vector<std::string>{
      "start", "metadatablock", "declarename", "programname", "version", 
      "versionnumber", "target", "device", "declaretype", "programtype", 
      "include", "program", "expressionvar", "arrayvar", "name", "invalid", 
      "reserved", "vartype", "nonnumeric", "shape", "arrayval", "arrayrow", 
      "statement", "operation", "measure", "forloop", "arguments", "kwarg", 
      "val", "vallist", "rangeval", "expression", "parameter", "number", 
      "function"
    },
    std::vector<std::string>{
      "", "'+'", "'-'", "'*'", "'/'", "'**'", "'='", "'for'", "'in'", "", 
      "", "", "", "", "", "'pi'", "", "", "", "'name'", "'version'", "'target'", 
      "'type'", "'include'", "'sqrt'", "'sin'", "'cos'", "'tan'", "'arcsin'", 
      "'arccos'", "'arctan'", "'sinh'", "'cosh'", "'tanh'", "'arcsinh'", 
      "'arccosh'", "'arctanh'", "'exp'", "'log'", "'.'", "','", "':'", "'\"'", 
      "'('", "')'", "'['", "']'", "'{'", "'}'", "'|'", "'array'", "'float'", 
      "'complex'", "'int'", "'str'", "'bool'"
    },
    std::vector<std::string>{
      "", "PLUS", "MINUS", "TIMES", "DIVIDE", "PWR", "ASSIGN", "FOR", "IN", 
      "INT", "FLOAT", "COMPLEX", "STR", "BOOL", "SEQUENCE", "PI", "NEWLINE", 
      "TAB", "SPACE", "PROGNAME", "VERSION", "TARGET", "PROGTYPE", "INCLUDE", 
      "SQRT", "SIN", "COS", "TAN", "ARCSIN", "ARCCOS", "ARCTAN", "SINH", 
      "COSH", "TANH", "ARCSINH", "ARCCOSH", "ARCTANH", "EXP", "LOG", "PERIOD", 
      "COMMA", "COLON", "QUOTE", "LBRAC", "RBRAC", "LSQBRAC", "RSQBRAC", 
      "LBRACE", "RBRACE", "APPLY", "TYPE_ARRAY", "TYPE_FLOAT", "TYPE_COMPLEX", 
      "TYPE_INT", "TYPE_STR", "TYPE_BOOL", "REGREF", "MEASURE", "NAME", 
      "DEVICE", "COMMENT", "ANY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,61,366,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,5,
  	0,72,8,0,10,0,12,0,75,9,0,1,0,1,0,5,0,79,8,0,10,0,12,0,82,9,0,1,0,1,0,
  	5,0,86,8,0,10,0,12,0,89,9,0,1,0,1,0,1,1,1,1,4,1,95,8,1,11,1,12,1,96,1,
  	1,1,1,4,1,101,8,1,11,1,12,1,102,1,1,3,1,106,8,1,1,1,4,1,109,8,1,11,1,
  	12,1,110,1,1,3,1,114,8,1,1,1,1,1,5,1,118,8,1,10,1,12,1,121,9,1,1,2,1,
  	2,1,2,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,6,3,6,136,8,6,1,7,1,7,1,8,
  	1,8,1,8,3,8,143,8,8,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,5,
  	11,155,8,11,10,11,12,11,158,9,11,1,12,1,12,1,12,1,12,1,12,3,12,165,8,
  	12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,174,8,13,1,13,1,13,1,13,1,
  	13,3,13,180,8,13,1,14,1,14,3,14,184,8,14,1,15,1,15,3,15,188,8,15,1,16,
  	1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,5,19,199,8,19,10,19,12,19,202,
  	9,19,1,20,1,20,1,20,1,20,5,20,208,8,20,10,20,12,20,211,9,20,1,21,1,21,
  	1,21,5,21,216,8,21,10,21,12,21,219,9,21,1,22,1,22,3,22,223,8,22,1,22,
  	3,22,226,8,22,1,22,1,22,3,22,230,8,22,1,22,1,22,3,22,234,8,22,1,22,5,
  	22,237,8,22,10,22,12,22,240,9,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,
  	25,1,25,1,25,3,25,252,8,25,1,25,1,25,3,25,256,8,25,3,25,258,8,25,1,25,
  	1,25,1,25,4,25,263,8,25,11,25,12,25,264,1,26,1,26,1,26,1,26,5,26,271,
  	8,26,10,26,12,26,274,9,26,3,26,276,8,26,1,26,3,26,279,8,26,1,26,1,26,
  	1,26,5,26,284,8,26,10,26,12,26,287,9,26,3,26,289,8,26,1,26,1,26,1,27,
  	1,27,1,27,1,27,1,27,3,27,298,8,27,1,27,3,27,301,8,27,1,28,1,28,3,28,305,
  	8,28,1,29,1,29,1,29,5,29,310,8,29,10,29,12,29,313,9,29,1,30,1,30,1,30,
  	1,30,1,30,3,30,320,8,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,
  	1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,3,31,342,8,31,
  	1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,5,31,353,8,31,10,31,12,31,
  	356,9,31,1,32,1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,34,0,1,62,35,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,
  	54,56,58,60,62,64,66,68,0,11,1,0,58,59,1,0,19,22,1,0,50,55,1,0,12,13,
  	2,0,43,43,45,45,2,0,44,44,46,46,1,0,1,2,2,0,56,56,58,58,1,0,3,4,2,0,9,
  	11,15,15,1,0,24,38,383,0,73,1,0,0,0,2,92,1,0,0,0,4,122,1,0,0,0,6,125,
  	1,0,0,0,8,127,1,0,0,0,10,130,1,0,0,0,12,132,1,0,0,0,14,137,1,0,0,0,16,
  	139,1,0,0,0,18,144,1,0,0,0,20,146,1,0,0,0,22,156,1,0,0,0,24,159,1,0,0,
  	0,26,166,1,0,0,0,28,183,1,0,0,0,30,187,1,0,0,0,32,189,1,0,0,0,34,191,
  	1,0,0,0,36,193,1,0,0,0,38,195,1,0,0,0,40,209,1,0,0,0,42,212,1,0,0,0,44,
  	222,1,0,0,0,46,241,1,0,0,0,48,243,1,0,0,0,50,245,1,0,0,0,52,266,1,0,0,
  	0,54,292,1,0,0,0,56,304,1,0,0,0,58,306,1,0,0,0,60,314,1,0,0,0,62,341,
  	1,0,0,0,64,357,1,0,0,0,66,361,1,0,0,0,68,363,1,0,0,0,70,72,5,16,0,0,71,
  	70,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,76,1,0,0,0,75,
  	73,1,0,0,0,76,80,3,2,1,0,77,79,5,16,0,0,78,77,1,0,0,0,79,82,1,0,0,0,80,
  	78,1,0,0,0,80,81,1,0,0,0,81,83,1,0,0,0,82,80,1,0,0,0,83,87,3,22,11,0,
  	84,86,5,16,0,0,85,84,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,
  	0,88,90,1,0,0,0,89,87,1,0,0,0,90,91,5,0,0,1,91,1,1,0,0,0,92,94,3,4,2,
  	0,93,95,5,16,0,0,94,93,1,0,0,0,95,96,1,0,0,0,96,94,1,0,0,0,96,97,1,0,
  	0,0,97,98,1,0,0,0,98,105,3,8,4,0,99,101,5,16,0,0,100,99,1,0,0,0,101,102,
  	1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,106,3,12,
  	6,0,105,100,1,0,0,0,105,106,1,0,0,0,106,113,1,0,0,0,107,109,5,16,0,0,
  	108,107,1,0,0,0,109,110,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,112,
  	1,0,0,0,112,114,3,16,8,0,113,108,1,0,0,0,113,114,1,0,0,0,114,119,1,0,
  	0,0,115,118,5,16,0,0,116,118,3,20,10,0,117,115,1,0,0,0,117,116,1,0,0,
  	0,118,121,1,0,0,0,119,117,1,0,0,0,119,120,1,0,0,0,120,3,1,0,0,0,121,119,
  	1,0,0,0,122,123,5,19,0,0,123,124,3,6,3,0,124,5,1,0,0,0,125,126,5,58,0,
  	0,126,7,1,0,0,0,127,128,5,20,0,0,128,129,3,10,5,0,129,9,1,0,0,0,130,131,
  	5,10,0,0,131,11,1,0,0,0,132,133,5,21,0,0,133,135,3,14,7,0,134,136,3,52,
  	26,0,135,134,1,0,0,0,135,136,1,0,0,0,136,13,1,0,0,0,137,138,7,0,0,0,138,
  	15,1,0,0,0,139,140,5,22,0,0,140,142,3,18,9,0,141,143,3,52,26,0,142,141,
  	1,0,0,0,142,143,1,0,0,0,143,17,1,0,0,0,144,145,5,58,0,0,145,19,1,0,0,
  	0,146,147,5,23,0,0,147,148,5,12,0,0,148,21,1,0,0,0,149,155,5,16,0,0,150,
  	155,3,50,25,0,151,155,3,24,12,0,152,155,3,26,13,0,153,155,3,44,22,0,154,
  	149,1,0,0,0,154,150,1,0,0,0,154,151,1,0,0,0,154,152,1,0,0,0,154,153,1,
  	0,0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,23,1,0,0,0,
  	158,156,1,0,0,0,159,160,3,34,17,0,160,161,3,28,14,0,161,164,5,6,0,0,162,
  	165,3,62,31,0,163,165,3,36,18,0,164,162,1,0,0,0,164,163,1,0,0,0,165,25,
  	1,0,0,0,166,167,3,34,17,0,167,168,5,50,0,0,168,173,3,28,14,0,169,170,
  	5,45,0,0,170,171,3,38,19,0,171,172,5,46,0,0,172,174,1,0,0,0,173,169,1,
  	0,0,0,173,174,1,0,0,0,174,175,1,0,0,0,175,176,5,6,0,0,176,179,5,16,0,
  	0,177,180,3,40,20,0,178,180,3,64,32,0,179,177,1,0,0,0,179,178,1,0,0,0,
  	180,27,1,0,0,0,181,184,3,30,15,0,182,184,5,58,0,0,183,181,1,0,0,0,183,
  	182,1,0,0,0,184,29,1,0,0,0,185,188,5,56,0,0,186,188,3,32,16,0,187,185,
  	1,0,0,0,187,186,1,0,0,0,188,31,1,0,0,0,189,190,7,1,0,0,190,33,1,0,0,0,
  	191,192,7,2,0,0,192,35,1,0,0,0,193,194,7,3,0,0,194,37,1,0,0,0,195,200,
  	5,9,0,0,196,197,5,40,0,0,197,199,5,9,0,0,198,196,1,0,0,0,199,202,1,0,
  	0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,39,1,0,0,0,202,200,1,0,0,0,203,
  	204,5,17,0,0,204,205,3,42,21,0,205,206,5,16,0,0,206,208,1,0,0,0,207,203,
  	1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,41,1,0,0,
  	0,211,209,1,0,0,0,212,217,3,62,31,0,213,214,5,40,0,0,214,216,3,62,31,
  	0,215,213,1,0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,
  	43,1,0,0,0,219,217,1,0,0,0,220,223,3,46,23,0,221,223,3,48,24,0,222,220,
  	1,0,0,0,222,221,1,0,0,0,223,225,1,0,0,0,224,226,3,52,26,0,225,224,1,0,
  	0,0,225,226,1,0,0,0,226,227,1,0,0,0,227,229,5,49,0,0,228,230,7,4,0,0,
  	229,228,1,0,0,0,229,230,1,0,0,0,230,231,1,0,0,0,231,233,3,42,21,0,232,
  	234,7,5,0,0,233,232,1,0,0,0,233,234,1,0,0,0,234,238,1,0,0,0,235,237,5,
  	16,0,0,236,235,1,0,0,0,237,240,1,0,0,0,238,236,1,0,0,0,238,239,1,0,0,
  	0,239,45,1,0,0,0,240,238,1,0,0,0,241,242,5,58,0,0,242,47,1,0,0,0,243,
  	244,5,57,0,0,244,49,1,0,0,0,245,246,5,7,0,0,246,247,3,34,17,0,247,248,
  	5,58,0,0,248,257,5,8,0,0,249,258,3,60,30,0,250,252,7,4,0,0,251,250,1,
  	0,0,0,251,252,1,0,0,0,252,253,1,0,0,0,253,255,3,58,29,0,254,256,7,5,0,
  	0,255,254,1,0,0,0,255,256,1,0,0,0,256,258,1,0,0,0,257,249,1,0,0,0,257,
  	251,1,0,0,0,258,262,1,0,0,0,259,260,5,16,0,0,260,261,5,17,0,0,261,263,
  	3,44,22,0,262,259,1,0,0,0,263,264,1,0,0,0,264,262,1,0,0,0,264,265,1,0,
  	0,0,265,51,1,0,0,0,266,275,5,43,0,0,267,272,3,56,28,0,268,269,5,40,0,
  	0,269,271,3,56,28,0,270,268,1,0,0,0,271,274,1,0,0,0,272,270,1,0,0,0,272,
  	273,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,275,267,1,0,0,0,275,276,1,
  	0,0,0,276,278,1,0,0,0,277,279,5,40,0,0,278,277,1,0,0,0,278,279,1,0,0,
  	0,279,288,1,0,0,0,280,285,3,54,27,0,281,282,5,40,0,0,282,284,3,54,27,
  	0,283,281,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,
  	289,1,0,0,0,287,285,1,0,0,0,288,280,1,0,0,0,288,289,1,0,0,0,289,290,1,
  	0,0,0,290,291,5,44,0,0,291,53,1,0,0,0,292,293,5,58,0,0,293,300,5,6,0,
  	0,294,301,3,56,28,0,295,297,5,45,0,0,296,298,3,58,29,0,297,296,1,0,0,
  	0,297,298,1,0,0,0,298,299,1,0,0,0,299,301,5,46,0,0,300,294,1,0,0,0,300,
  	295,1,0,0,0,301,55,1,0,0,0,302,305,3,36,18,0,303,305,3,62,31,0,304,302,
  	1,0,0,0,304,303,1,0,0,0,305,57,1,0,0,0,306,311,3,56,28,0,307,308,5,40,
  	0,0,308,310,3,56,28,0,309,307,1,0,0,0,310,313,1,0,0,0,311,309,1,0,0,0,
  	311,312,1,0,0,0,312,59,1,0,0,0,313,311,1,0,0,0,314,315,5,9,0,0,315,316,
  	5,41,0,0,316,319,5,9,0,0,317,318,5,41,0,0,318,320,5,9,0,0,319,317,1,0,
  	0,0,319,320,1,0,0,0,320,61,1,0,0,0,321,322,6,31,-1,0,322,323,5,43,0,0,
  	323,324,3,62,31,0,324,325,5,44,0,0,325,342,1,0,0,0,326,327,7,6,0,0,327,
  	342,3,62,31,9,328,329,3,68,34,0,329,330,5,43,0,0,330,331,3,62,31,0,331,
  	332,5,44,0,0,332,342,1,0,0,0,333,342,3,66,33,0,334,342,7,7,0,0,335,336,
  	5,58,0,0,336,337,5,45,0,0,337,338,3,62,31,0,338,339,5,46,0,0,339,342,
  	1,0,0,0,340,342,3,64,32,0,341,321,1,0,0,0,341,326,1,0,0,0,341,328,1,0,
  	0,0,341,333,1,0,0,0,341,334,1,0,0,0,341,335,1,0,0,0,341,340,1,0,0,0,342,
  	354,1,0,0,0,343,344,10,8,0,0,344,345,5,5,0,0,345,353,3,62,31,8,346,347,
  	10,7,0,0,347,348,7,8,0,0,348,353,3,62,31,8,349,350,10,6,0,0,350,351,7,
  	6,0,0,351,353,3,62,31,7,352,343,1,0,0,0,352,346,1,0,0,0,352,349,1,0,0,
  	0,353,356,1,0,0,0,354,352,1,0,0,0,354,355,1,0,0,0,355,63,1,0,0,0,356,
  	354,1,0,0,0,357,358,5,47,0,0,358,359,5,58,0,0,359,360,5,48,0,0,360,65,
  	1,0,0,0,361,362,7,9,0,0,362,67,1,0,0,0,363,364,7,10,0,0,364,69,1,0,0,
  	0,44,73,80,87,96,102,105,110,113,117,119,135,142,154,156,164,173,179,
  	183,187,200,209,217,222,225,229,233,238,251,255,257,264,272,275,278,285,
  	288,297,300,304,311,319,341,352,354
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  blackbirdParserStaticData = staticData.release();
}

}

blackbirdParser::blackbirdParser(TokenStream *input) : blackbirdParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

blackbirdParser::blackbirdParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  blackbirdParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *blackbirdParserStaticData->atn, blackbirdParserStaticData->decisionToDFA, blackbirdParserStaticData->sharedContextCache, options);
}

blackbirdParser::~blackbirdParser() {
  delete _interpreter;
}

const atn::ATN& blackbirdParser::getATN() const {
  return *blackbirdParserStaticData->atn;
}

std::string blackbirdParser::getGrammarFileName() const {
  return "blackbird.g4";
}

const std::vector<std::string>& blackbirdParser::getRuleNames() const {
  return blackbirdParserStaticData->ruleNames;
}

const dfa::Vocabulary& blackbirdParser::getVocabulary() const {
  return blackbirdParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView blackbirdParser::getSerializedATN() const {
  return blackbirdParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

blackbirdParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::MetadatablockContext* blackbirdParser::StartContext::metadatablock() {
  return getRuleContext<blackbirdParser::MetadatablockContext>(0);
}

blackbirdParser::ProgramContext* blackbirdParser::StartContext::program() {
  return getRuleContext<blackbirdParser::ProgramContext>(0);
}

tree::TerminalNode* blackbirdParser::StartContext::EOF() {
  return getToken(blackbirdParser::EOF, 0);
}

std::vector<tree::TerminalNode *> blackbirdParser::StartContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::StartContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}


size_t blackbirdParser::StartContext::getRuleIndex() const {
  return blackbirdParser::RuleStart;
}


std::any blackbirdParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::StartContext* blackbirdParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, blackbirdParser::RuleStart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::NEWLINE) {
      setState(70);
      match(blackbirdParser::NEWLINE);
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    metadatablock();
    setState(80);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(77);
        match(blackbirdParser::NEWLINE); 
      }
      setState(82);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(83);
    program();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::NEWLINE) {
      setState(84);
      match(blackbirdParser::NEWLINE);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(blackbirdParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MetadatablockContext ------------------------------------------------------------------

blackbirdParser::MetadatablockContext::MetadatablockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::DeclarenameContext* blackbirdParser::MetadatablockContext::declarename() {
  return getRuleContext<blackbirdParser::DeclarenameContext>(0);
}

blackbirdParser::VersionContext* blackbirdParser::MetadatablockContext::version() {
  return getRuleContext<blackbirdParser::VersionContext>(0);
}

std::vector<tree::TerminalNode *> blackbirdParser::MetadatablockContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::MetadatablockContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

blackbirdParser::TargetContext* blackbirdParser::MetadatablockContext::target() {
  return getRuleContext<blackbirdParser::TargetContext>(0);
}

blackbirdParser::DeclaretypeContext* blackbirdParser::MetadatablockContext::declaretype() {
  return getRuleContext<blackbirdParser::DeclaretypeContext>(0);
}

std::vector<blackbirdParser::IncludeContext *> blackbirdParser::MetadatablockContext::include() {
  return getRuleContexts<blackbirdParser::IncludeContext>();
}

blackbirdParser::IncludeContext* blackbirdParser::MetadatablockContext::include(size_t i) {
  return getRuleContext<blackbirdParser::IncludeContext>(i);
}


size_t blackbirdParser::MetadatablockContext::getRuleIndex() const {
  return blackbirdParser::RuleMetadatablock;
}


std::any blackbirdParser::MetadatablockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMetadatablock(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::MetadatablockContext* blackbirdParser::metadatablock() {
  MetadatablockContext *_localctx = _tracker.createInstance<MetadatablockContext>(_ctx, getState());
  enterRule(_localctx, 2, blackbirdParser::RuleMetadatablock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(92);
    declarename();
    setState(94); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(93);
      match(blackbirdParser::NEWLINE);
      setState(96); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == blackbirdParser::NEWLINE);
    setState(98);
    version();
    setState(105);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(100); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(99);
        match(blackbirdParser::NEWLINE);
        setState(102); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == blackbirdParser::NEWLINE);
      setState(104);
      target();
      break;
    }

    default:
      break;
    }
    setState(113);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(108); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(107);
        match(blackbirdParser::NEWLINE);
        setState(110); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == blackbirdParser::NEWLINE);
      setState(112);
      declaretype();
      break;
    }

    default:
      break;
    }
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(117);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case blackbirdParser::NEWLINE: {
            setState(115);
            match(blackbirdParser::NEWLINE);
            break;
          }

          case blackbirdParser::INCLUDE: {
            setState(116);
            antlrcpp::downCast<MetadatablockContext *>(_localctx)->includeContext = include();
            antlrcpp::downCast<MetadatablockContext *>(_localctx)->include_list.push_back(antlrcpp::downCast<MetadatablockContext *>(_localctx)->includeContext);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarenameContext ------------------------------------------------------------------

blackbirdParser::DeclarenameContext::DeclarenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::DeclarenameContext::PROGNAME() {
  return getToken(blackbirdParser::PROGNAME, 0);
}

blackbirdParser::ProgramnameContext* blackbirdParser::DeclarenameContext::programname() {
  return getRuleContext<blackbirdParser::ProgramnameContext>(0);
}


size_t blackbirdParser::DeclarenameContext::getRuleIndex() const {
  return blackbirdParser::RuleDeclarename;
}


std::any blackbirdParser::DeclarenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDeclarename(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeclarenameContext* blackbirdParser::declarename() {
  DeclarenameContext *_localctx = _tracker.createInstance<DeclarenameContext>(_ctx, getState());
  enterRule(_localctx, 4, blackbirdParser::RuleDeclarename);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(blackbirdParser::PROGNAME);
    setState(123);
    programname();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramnameContext ------------------------------------------------------------------

blackbirdParser::ProgramnameContext::ProgramnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ProgramnameContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::ProgramnameContext::getRuleIndex() const {
  return blackbirdParser::RuleProgramname;
}


std::any blackbirdParser::ProgramnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgramname(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramnameContext* blackbirdParser::programname() {
  ProgramnameContext *_localctx = _tracker.createInstance<ProgramnameContext>(_ctx, getState());
  enterRule(_localctx, 6, blackbirdParser::RuleProgramname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

blackbirdParser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::VersionContext::VERSION() {
  return getToken(blackbirdParser::VERSION, 0);
}

blackbirdParser::VersionnumberContext* blackbirdParser::VersionContext::versionnumber() {
  return getRuleContext<blackbirdParser::VersionnumberContext>(0);
}


size_t blackbirdParser::VersionContext::getRuleIndex() const {
  return blackbirdParser::RuleVersion;
}


std::any blackbirdParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VersionContext* blackbirdParser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 8, blackbirdParser::RuleVersion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(blackbirdParser::VERSION);
    setState(128);
    versionnumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionnumberContext ------------------------------------------------------------------

blackbirdParser::VersionnumberContext::VersionnumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::VersionnumberContext::FLOAT() {
  return getToken(blackbirdParser::FLOAT, 0);
}


size_t blackbirdParser::VersionnumberContext::getRuleIndex() const {
  return blackbirdParser::RuleVersionnumber;
}


std::any blackbirdParser::VersionnumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVersionnumber(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VersionnumberContext* blackbirdParser::versionnumber() {
  VersionnumberContext *_localctx = _tracker.createInstance<VersionnumberContext>(_ctx, getState());
  enterRule(_localctx, 10, blackbirdParser::RuleVersionnumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(blackbirdParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

blackbirdParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::TargetContext::TARGET() {
  return getToken(blackbirdParser::TARGET, 0);
}

blackbirdParser::DeviceContext* blackbirdParser::TargetContext::device() {
  return getRuleContext<blackbirdParser::DeviceContext>(0);
}

blackbirdParser::ArgumentsContext* blackbirdParser::TargetContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}


size_t blackbirdParser::TargetContext::getRuleIndex() const {
  return blackbirdParser::RuleTarget;
}


std::any blackbirdParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::TargetContext* blackbirdParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 12, blackbirdParser::RuleTarget);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(blackbirdParser::TARGET);
    setState(133);
    device();
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(134);
      arguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeviceContext ------------------------------------------------------------------

blackbirdParser::DeviceContext::DeviceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::DeviceContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::DeviceContext::DEVICE() {
  return getToken(blackbirdParser::DEVICE, 0);
}


size_t blackbirdParser::DeviceContext::getRuleIndex() const {
  return blackbirdParser::RuleDevice;
}


std::any blackbirdParser::DeviceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDevice(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeviceContext* blackbirdParser::device() {
  DeviceContext *_localctx = _tracker.createInstance<DeviceContext>(_ctx, getState());
  enterRule(_localctx, 14, blackbirdParser::RuleDevice);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _la = _input->LA(1);
    if (!(_la == blackbirdParser::NAME

    || _la == blackbirdParser::DEVICE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaretypeContext ------------------------------------------------------------------

blackbirdParser::DeclaretypeContext::DeclaretypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::DeclaretypeContext::PROGTYPE() {
  return getToken(blackbirdParser::PROGTYPE, 0);
}

blackbirdParser::ProgramtypeContext* blackbirdParser::DeclaretypeContext::programtype() {
  return getRuleContext<blackbirdParser::ProgramtypeContext>(0);
}

blackbirdParser::ArgumentsContext* blackbirdParser::DeclaretypeContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}


size_t blackbirdParser::DeclaretypeContext::getRuleIndex() const {
  return blackbirdParser::RuleDeclaretype;
}


std::any blackbirdParser::DeclaretypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitDeclaretype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::DeclaretypeContext* blackbirdParser::declaretype() {
  DeclaretypeContext *_localctx = _tracker.createInstance<DeclaretypeContext>(_ctx, getState());
  enterRule(_localctx, 16, blackbirdParser::RuleDeclaretype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(blackbirdParser::PROGTYPE);
    setState(140);
    programtype();
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(141);
      arguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramtypeContext ------------------------------------------------------------------

blackbirdParser::ProgramtypeContext::ProgramtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ProgramtypeContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::ProgramtypeContext::getRuleIndex() const {
  return blackbirdParser::RuleProgramtype;
}


std::any blackbirdParser::ProgramtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgramtype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramtypeContext* blackbirdParser::programtype() {
  ProgramtypeContext *_localctx = _tracker.createInstance<ProgramtypeContext>(_ctx, getState());
  enterRule(_localctx, 18, blackbirdParser::RuleProgramtype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

blackbirdParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::IncludeContext::INCLUDE() {
  return getToken(blackbirdParser::INCLUDE, 0);
}

tree::TerminalNode* blackbirdParser::IncludeContext::STR() {
  return getToken(blackbirdParser::STR, 0);
}


size_t blackbirdParser::IncludeContext::getRuleIndex() const {
  return blackbirdParser::RuleInclude;
}


std::any blackbirdParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::IncludeContext* blackbirdParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 20, blackbirdParser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(blackbirdParser::INCLUDE);
    setState(147);
    match(blackbirdParser::STR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

blackbirdParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::ProgramContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<blackbirdParser::ForloopContext *> blackbirdParser::ProgramContext::forloop() {
  return getRuleContexts<blackbirdParser::ForloopContext>();
}

blackbirdParser::ForloopContext* blackbirdParser::ProgramContext::forloop(size_t i) {
  return getRuleContext<blackbirdParser::ForloopContext>(i);
}

std::vector<blackbirdParser::ExpressionvarContext *> blackbirdParser::ProgramContext::expressionvar() {
  return getRuleContexts<blackbirdParser::ExpressionvarContext>();
}

blackbirdParser::ExpressionvarContext* blackbirdParser::ProgramContext::expressionvar(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionvarContext>(i);
}

std::vector<blackbirdParser::ArrayvarContext *> blackbirdParser::ProgramContext::arrayvar() {
  return getRuleContexts<blackbirdParser::ArrayvarContext>();
}

blackbirdParser::ArrayvarContext* blackbirdParser::ProgramContext::arrayvar(size_t i) {
  return getRuleContext<blackbirdParser::ArrayvarContext>(i);
}

std::vector<blackbirdParser::StatementContext *> blackbirdParser::ProgramContext::statement() {
  return getRuleContexts<blackbirdParser::StatementContext>();
}

blackbirdParser::StatementContext* blackbirdParser::ProgramContext::statement(size_t i) {
  return getRuleContext<blackbirdParser::StatementContext>(i);
}


size_t blackbirdParser::ProgramContext::getRuleIndex() const {
  return blackbirdParser::RuleProgram;
}


std::any blackbirdParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ProgramContext* blackbirdParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 22, blackbirdParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(154);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(149);
          match(blackbirdParser::NEWLINE);
          break;
        }

        case 2: {
          setState(150);
          antlrcpp::downCast<ProgramContext *>(_localctx)->forloopContext = forloop();
          antlrcpp::downCast<ProgramContext *>(_localctx)->for_list.push_back(antlrcpp::downCast<ProgramContext *>(_localctx)->forloopContext);
          break;
        }

        case 3: {
          setState(151);
          antlrcpp::downCast<ProgramContext *>(_localctx)->expressionvarContext = expressionvar();
          antlrcpp::downCast<ProgramContext *>(_localctx)->var_list.push_back(antlrcpp::downCast<ProgramContext *>(_localctx)->expressionvarContext);
          break;
        }

        case 4: {
          setState(152);
          antlrcpp::downCast<ProgramContext *>(_localctx)->arrayvarContext = arrayvar();
          antlrcpp::downCast<ProgramContext *>(_localctx)->array_list.push_back(antlrcpp::downCast<ProgramContext *>(_localctx)->arrayvarContext);
          break;
        }

        case 5: {
          setState(153);
          antlrcpp::downCast<ProgramContext *>(_localctx)->statementContext = statement();
          antlrcpp::downCast<ProgramContext *>(_localctx)->statement_list.push_back(antlrcpp::downCast<ProgramContext *>(_localctx)->statementContext);
          break;
        }

        default:
          break;
        } 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionvarContext ------------------------------------------------------------------

blackbirdParser::ExpressionvarContext::ExpressionvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::VartypeContext* blackbirdParser::ExpressionvarContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

blackbirdParser::NameContext* blackbirdParser::ExpressionvarContext::name() {
  return getRuleContext<blackbirdParser::NameContext>(0);
}

tree::TerminalNode* blackbirdParser::ExpressionvarContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ExpressionvarContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

blackbirdParser::NonnumericContext* blackbirdParser::ExpressionvarContext::nonnumeric() {
  return getRuleContext<blackbirdParser::NonnumericContext>(0);
}


size_t blackbirdParser::ExpressionvarContext::getRuleIndex() const {
  return blackbirdParser::RuleExpressionvar;
}


std::any blackbirdParser::ExpressionvarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitExpressionvar(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ExpressionvarContext* blackbirdParser::expressionvar() {
  ExpressionvarContext *_localctx = _tracker.createInstance<ExpressionvarContext>(_ctx, getState());
  enterRule(_localctx, 24, blackbirdParser::RuleExpressionvar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    vartype();
    setState(160);
    name();
    setState(161);
    match(blackbirdParser::ASSIGN);
    setState(164);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS:
      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::PI:
      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::TAN:
      case blackbirdParser::ARCSIN:
      case blackbirdParser::ARCCOS:
      case blackbirdParser::ARCTAN:
      case blackbirdParser::SINH:
      case blackbirdParser::COSH:
      case blackbirdParser::TANH:
      case blackbirdParser::ARCSINH:
      case blackbirdParser::ARCCOSH:
      case blackbirdParser::ARCTANH:
      case blackbirdParser::EXP:
      case blackbirdParser::LOG:
      case blackbirdParser::LBRAC:
      case blackbirdParser::LBRACE:
      case blackbirdParser::REGREF:
      case blackbirdParser::NAME: {
        setState(162);
        expression(0);
        break;
      }

      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(163);
        nonnumeric();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayvarContext ------------------------------------------------------------------

blackbirdParser::ArrayvarContext::ArrayvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::VartypeContext* blackbirdParser::ArrayvarContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::TYPE_ARRAY() {
  return getToken(blackbirdParser::TYPE_ARRAY, 0);
}

blackbirdParser::NameContext* blackbirdParser::ArrayvarContext::name() {
  return getRuleContext<blackbirdParser::NameContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::NEWLINE() {
  return getToken(blackbirdParser::NEWLINE, 0);
}

blackbirdParser::ArrayvalContext* blackbirdParser::ArrayvarContext::arrayval() {
  return getRuleContext<blackbirdParser::ArrayvalContext>(0);
}

blackbirdParser::ParameterContext* blackbirdParser::ArrayvarContext::parameter() {
  return getRuleContext<blackbirdParser::ParameterContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

blackbirdParser::ShapeContext* blackbirdParser::ArrayvarContext::shape() {
  return getRuleContext<blackbirdParser::ShapeContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayvarContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}


size_t blackbirdParser::ArrayvarContext::getRuleIndex() const {
  return blackbirdParser::RuleArrayvar;
}


std::any blackbirdParser::ArrayvarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayvar(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayvarContext* blackbirdParser::arrayvar() {
  ArrayvarContext *_localctx = _tracker.createInstance<ArrayvarContext>(_ctx, getState());
  enterRule(_localctx, 26, blackbirdParser::RuleArrayvar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    vartype();
    setState(167);
    match(blackbirdParser::TYPE_ARRAY);
    setState(168);
    name();
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LSQBRAC) {
      setState(169);
      match(blackbirdParser::LSQBRAC);
      setState(170);
      shape();
      setState(171);
      match(blackbirdParser::RSQBRAC);
    }
    setState(175);
    match(blackbirdParser::ASSIGN);
    setState(176);
    match(blackbirdParser::NEWLINE);
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::EOF:
      case blackbirdParser::FOR:
      case blackbirdParser::NEWLINE:
      case blackbirdParser::TAB:
      case blackbirdParser::TYPE_ARRAY:
      case blackbirdParser::TYPE_FLOAT:
      case blackbirdParser::TYPE_COMPLEX:
      case blackbirdParser::TYPE_INT:
      case blackbirdParser::TYPE_STR:
      case blackbirdParser::TYPE_BOOL:
      case blackbirdParser::MEASURE:
      case blackbirdParser::NAME: {
        setState(177);
        arrayval();
        break;
      }

      case blackbirdParser::LBRACE: {
        setState(178);
        parameter();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

blackbirdParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::InvalidContext* blackbirdParser::NameContext::invalid() {
  return getRuleContext<blackbirdParser::InvalidContext>(0);
}

tree::TerminalNode* blackbirdParser::NameContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::NameContext::getRuleIndex() const {
  return blackbirdParser::RuleName;
}


std::any blackbirdParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NameContext* blackbirdParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 28, blackbirdParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::PROGNAME:
      case blackbirdParser::VERSION:
      case blackbirdParser::TARGET:
      case blackbirdParser::PROGTYPE:
      case blackbirdParser::REGREF: {
        setState(181);
        invalid();
        break;
      }

      case blackbirdParser::NAME: {
        setState(182);
        match(blackbirdParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvalidContext ------------------------------------------------------------------

blackbirdParser::InvalidContext::InvalidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::InvalidContext::REGREF() {
  return getToken(blackbirdParser::REGREF, 0);
}

blackbirdParser::ReservedContext* blackbirdParser::InvalidContext::reserved() {
  return getRuleContext<blackbirdParser::ReservedContext>(0);
}


size_t blackbirdParser::InvalidContext::getRuleIndex() const {
  return blackbirdParser::RuleInvalid;
}


std::any blackbirdParser::InvalidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitInvalid(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::InvalidContext* blackbirdParser::invalid() {
  InvalidContext *_localctx = _tracker.createInstance<InvalidContext>(_ctx, getState());
  enterRule(_localctx, 30, blackbirdParser::RuleInvalid);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::REGREF: {
        setState(185);
        match(blackbirdParser::REGREF);
        break;
      }

      case blackbirdParser::PROGNAME:
      case blackbirdParser::VERSION:
      case blackbirdParser::TARGET:
      case blackbirdParser::PROGTYPE: {
        setState(186);
        reserved();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReservedContext ------------------------------------------------------------------

blackbirdParser::ReservedContext::ReservedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ReservedContext::PROGNAME() {
  return getToken(blackbirdParser::PROGNAME, 0);
}

tree::TerminalNode* blackbirdParser::ReservedContext::VERSION() {
  return getToken(blackbirdParser::VERSION, 0);
}

tree::TerminalNode* blackbirdParser::ReservedContext::TARGET() {
  return getToken(blackbirdParser::TARGET, 0);
}

tree::TerminalNode* blackbirdParser::ReservedContext::PROGTYPE() {
  return getToken(blackbirdParser::PROGTYPE, 0);
}


size_t blackbirdParser::ReservedContext::getRuleIndex() const {
  return blackbirdParser::RuleReserved;
}


std::any blackbirdParser::ReservedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitReserved(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ReservedContext* blackbirdParser::reserved() {
  ReservedContext *_localctx = _tracker.createInstance<ReservedContext>(_ctx, getState());
  enterRule(_localctx, 32, blackbirdParser::RuleReserved);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7864320) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

blackbirdParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_ARRAY() {
  return getToken(blackbirdParser::TYPE_ARRAY, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_FLOAT() {
  return getToken(blackbirdParser::TYPE_FLOAT, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_COMPLEX() {
  return getToken(blackbirdParser::TYPE_COMPLEX, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_INT() {
  return getToken(blackbirdParser::TYPE_INT, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_STR() {
  return getToken(blackbirdParser::TYPE_STR, 0);
}

tree::TerminalNode* blackbirdParser::VartypeContext::TYPE_BOOL() {
  return getToken(blackbirdParser::TYPE_BOOL, 0);
}


size_t blackbirdParser::VartypeContext::getRuleIndex() const {
  return blackbirdParser::RuleVartype;
}


std::any blackbirdParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VartypeContext* blackbirdParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 34, blackbirdParser::RuleVartype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 70931694131085312) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonnumericContext ------------------------------------------------------------------

blackbirdParser::NonnumericContext::NonnumericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::NonnumericContext::STR() {
  return getToken(blackbirdParser::STR, 0);
}

tree::TerminalNode* blackbirdParser::NonnumericContext::BOOL() {
  return getToken(blackbirdParser::BOOL, 0);
}


size_t blackbirdParser::NonnumericContext::getRuleIndex() const {
  return blackbirdParser::RuleNonnumeric;
}


std::any blackbirdParser::NonnumericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNonnumeric(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NonnumericContext* blackbirdParser::nonnumeric() {
  NonnumericContext *_localctx = _tracker.createInstance<NonnumericContext>(_ctx, getState());
  enterRule(_localctx, 36, blackbirdParser::RuleNonnumeric);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    _la = _input->LA(1);
    if (!(_la == blackbirdParser::STR

    || _la == blackbirdParser::BOOL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShapeContext ------------------------------------------------------------------

blackbirdParser::ShapeContext::ShapeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::ShapeContext::INT() {
  return getTokens(blackbirdParser::INT);
}

tree::TerminalNode* blackbirdParser::ShapeContext::INT(size_t i) {
  return getToken(blackbirdParser::INT, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ShapeContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ShapeContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::ShapeContext::getRuleIndex() const {
  return blackbirdParser::RuleShape;
}


std::any blackbirdParser::ShapeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitShape(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ShapeContext* blackbirdParser::shape() {
  ShapeContext *_localctx = _tracker.createInstance<ShapeContext>(_ctx, getState());
  enterRule(_localctx, 38, blackbirdParser::RuleShape);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(blackbirdParser::INT);
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(196);
      match(blackbirdParser::COMMA);
      setState(197);
      match(blackbirdParser::INT);
      setState(202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayvalContext ------------------------------------------------------------------

blackbirdParser::ArrayvalContext::ArrayvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::ArrayvalContext::TAB() {
  return getTokens(blackbirdParser::TAB);
}

tree::TerminalNode* blackbirdParser::ArrayvalContext::TAB(size_t i) {
  return getToken(blackbirdParser::TAB, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ArrayvalContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ArrayvalContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<blackbirdParser::ArrayrowContext *> blackbirdParser::ArrayvalContext::arrayrow() {
  return getRuleContexts<blackbirdParser::ArrayrowContext>();
}

blackbirdParser::ArrayrowContext* blackbirdParser::ArrayvalContext::arrayrow(size_t i) {
  return getRuleContext<blackbirdParser::ArrayrowContext>(i);
}


size_t blackbirdParser::ArrayvalContext::getRuleIndex() const {
  return blackbirdParser::RuleArrayval;
}


std::any blackbirdParser::ArrayvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayval(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayvalContext* blackbirdParser::arrayval() {
  ArrayvalContext *_localctx = _tracker.createInstance<ArrayvalContext>(_ctx, getState());
  enterRule(_localctx, 40, blackbirdParser::RuleArrayval);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::TAB) {
      setState(203);
      match(blackbirdParser::TAB);
      setState(204);
      antlrcpp::downCast<ArrayvalContext *>(_localctx)->arrayrowContext = arrayrow();
      antlrcpp::downCast<ArrayvalContext *>(_localctx)->row_list.push_back(antlrcpp::downCast<ArrayvalContext *>(_localctx)->arrayrowContext);
      setState(205);
      match(blackbirdParser::NEWLINE);
      setState(211);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayrowContext ------------------------------------------------------------------

blackbirdParser::ArrayrowContext::ArrayrowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::ArrayrowContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::ArrayrowContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ArrayrowContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ArrayrowContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::ArrayrowContext::getRuleIndex() const {
  return blackbirdParser::RuleArrayrow;
}


std::any blackbirdParser::ArrayrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayrow(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArrayrowContext* blackbirdParser::arrayrow() {
  ArrayrowContext *_localctx = _tracker.createInstance<ArrayrowContext>(_ctx, getState());
  enterRule(_localctx, 42, blackbirdParser::RuleArrayrow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    expression(0);
    setState(217);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(213);
      match(blackbirdParser::COMMA);
      setState(214);
      expression(0);
      setState(219);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

blackbirdParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::StatementContext::APPLY() {
  return getToken(blackbirdParser::APPLY, 0);
}

blackbirdParser::ArrayrowContext* blackbirdParser::StatementContext::arrayrow() {
  return getRuleContext<blackbirdParser::ArrayrowContext>(0);
}

blackbirdParser::OperationContext* blackbirdParser::StatementContext::operation() {
  return getRuleContext<blackbirdParser::OperationContext>(0);
}

blackbirdParser::MeasureContext* blackbirdParser::StatementContext::measure() {
  return getRuleContext<blackbirdParser::MeasureContext>(0);
}

blackbirdParser::ArgumentsContext* blackbirdParser::StatementContext::arguments() {
  return getRuleContext<blackbirdParser::ArgumentsContext>(0);
}

std::vector<tree::TerminalNode *> blackbirdParser::StatementContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::StatementContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

tree::TerminalNode* blackbirdParser::StatementContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

tree::TerminalNode* blackbirdParser::StatementContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}


size_t blackbirdParser::StatementContext::getRuleIndex() const {
  return blackbirdParser::RuleStatement;
}


std::any blackbirdParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::StatementContext* blackbirdParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 44, blackbirdParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::NAME: {
        setState(220);
        operation();
        break;
      }

      case blackbirdParser::MEASURE: {
        setState(221);
        measure();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::LBRAC) {
      setState(224);
      arguments();
    }
    setState(227);
    match(blackbirdParser::APPLY);
    setState(229);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(228);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::LBRAC

      || _la == blackbirdParser::LSQBRAC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    default:
      break;
    }
    setState(231);
    arrayrow();
    setState(233);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::RBRAC

    || _la == blackbirdParser::RSQBRAC) {
      setState(232);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::RBRAC

      || _la == blackbirdParser::RSQBRAC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(238);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(235);
        match(blackbirdParser::NEWLINE); 
      }
      setState(240);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

blackbirdParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::OperationContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}


size_t blackbirdParser::OperationContext::getRuleIndex() const {
  return blackbirdParser::RuleOperation;
}


std::any blackbirdParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::OperationContext* blackbirdParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 46, blackbirdParser::RuleOperation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(blackbirdParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureContext ------------------------------------------------------------------

blackbirdParser::MeasureContext::MeasureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::MeasureContext::MEASURE() {
  return getToken(blackbirdParser::MEASURE, 0);
}


size_t blackbirdParser::MeasureContext::getRuleIndex() const {
  return blackbirdParser::RuleMeasure;
}


std::any blackbirdParser::MeasureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMeasure(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::MeasureContext* blackbirdParser::measure() {
  MeasureContext *_localctx = _tracker.createInstance<MeasureContext>(_ctx, getState());
  enterRule(_localctx, 48, blackbirdParser::RuleMeasure);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(blackbirdParser::MEASURE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForloopContext ------------------------------------------------------------------

blackbirdParser::ForloopContext::ForloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ForloopContext::FOR() {
  return getToken(blackbirdParser::FOR, 0);
}

blackbirdParser::VartypeContext* blackbirdParser::ForloopContext::vartype() {
  return getRuleContext<blackbirdParser::VartypeContext>(0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::IN() {
  return getToken(blackbirdParser::IN, 0);
}

blackbirdParser::RangevalContext* blackbirdParser::ForloopContext::rangeval() {
  return getRuleContext<blackbirdParser::RangevalContext>(0);
}

blackbirdParser::VallistContext* blackbirdParser::ForloopContext::vallist() {
  return getRuleContext<blackbirdParser::VallistContext>(0);
}

std::vector<tree::TerminalNode *> blackbirdParser::ForloopContext::NEWLINE() {
  return getTokens(blackbirdParser::NEWLINE);
}

tree::TerminalNode* blackbirdParser::ForloopContext::NEWLINE(size_t i) {
  return getToken(blackbirdParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::ForloopContext::TAB() {
  return getTokens(blackbirdParser::TAB);
}

tree::TerminalNode* blackbirdParser::ForloopContext::TAB(size_t i) {
  return getToken(blackbirdParser::TAB, i);
}

std::vector<blackbirdParser::StatementContext *> blackbirdParser::ForloopContext::statement() {
  return getRuleContexts<blackbirdParser::StatementContext>();
}

blackbirdParser::StatementContext* blackbirdParser::ForloopContext::statement(size_t i) {
  return getRuleContext<blackbirdParser::StatementContext>(i);
}

tree::TerminalNode* blackbirdParser::ForloopContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ForloopContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}


size_t blackbirdParser::ForloopContext::getRuleIndex() const {
  return blackbirdParser::RuleForloop;
}


std::any blackbirdParser::ForloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitForloop(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ForloopContext* blackbirdParser::forloop() {
  ForloopContext *_localctx = _tracker.createInstance<ForloopContext>(_ctx, getState());
  enterRule(_localctx, 50, blackbirdParser::RuleForloop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(blackbirdParser::FOR);
    setState(246);
    vartype();
    setState(247);
    match(blackbirdParser::NAME);
    setState(248);
    match(blackbirdParser::IN);
    setState(257);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(249);
      rangeval();
      break;
    }

    case 2: {
      setState(251);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
      case 1: {
        setState(250);
        _la = _input->LA(1);
        if (!(_la == blackbirdParser::LBRAC

        || _la == blackbirdParser::LSQBRAC)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      default:
        break;
      }
      setState(253);
      vallist();
      setState(255);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == blackbirdParser::RBRAC

      || _la == blackbirdParser::RSQBRAC) {
        setState(254);
        _la = _input->LA(1);
        if (!(_la == blackbirdParser::RBRAC

        || _la == blackbirdParser::RSQBRAC)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      break;
    }

    default:
      break;
    }
    setState(262); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(259);
              match(blackbirdParser::NEWLINE);
              setState(260);
              match(blackbirdParser::TAB);
              setState(261);
              antlrcpp::downCast<ForloopContext *>(_localctx)->statementContext = statement();
              antlrcpp::downCast<ForloopContext *>(_localctx)->statement_list.push_back(antlrcpp::downCast<ForloopContext *>(_localctx)->statementContext);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(264); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

blackbirdParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

std::vector<tree::TerminalNode *> blackbirdParser::ArgumentsContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}

std::vector<blackbirdParser::ValContext *> blackbirdParser::ArgumentsContext::val() {
  return getRuleContexts<blackbirdParser::ValContext>();
}

blackbirdParser::ValContext* blackbirdParser::ArgumentsContext::val(size_t i) {
  return getRuleContext<blackbirdParser::ValContext>(i);
}

std::vector<blackbirdParser::KwargContext *> blackbirdParser::ArgumentsContext::kwarg() {
  return getRuleContexts<blackbirdParser::KwargContext>();
}

blackbirdParser::KwargContext* blackbirdParser::ArgumentsContext::kwarg(size_t i) {
  return getRuleContext<blackbirdParser::KwargContext>(i);
}


size_t blackbirdParser::ArgumentsContext::getRuleIndex() const {
  return blackbirdParser::RuleArguments;
}


std::any blackbirdParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ArgumentsContext* blackbirdParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 52, blackbirdParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(blackbirdParser::LBRAC);
    setState(275);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(267);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->valContext = val();
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->val_list.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->valContext);
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(268);
          match(blackbirdParser::COMMA);
          setState(269);
          antlrcpp::downCast<ArgumentsContext *>(_localctx)->valContext = val();
          antlrcpp::downCast<ArgumentsContext *>(_localctx)->val_list.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->valContext); 
        }
        setState(274);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }
      break;
    }

    default:
      break;
    }
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::COMMA) {
      setState(277);
      match(blackbirdParser::COMMA);
    }
    setState(288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::NAME) {
      setState(280);
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->kwargContext = kwarg();
      antlrcpp::downCast<ArgumentsContext *>(_localctx)->kwarg_list.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->kwargContext);
      setState(285);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == blackbirdParser::COMMA) {
        setState(281);
        match(blackbirdParser::COMMA);
        setState(282);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->kwargContext = kwarg();
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->kwarg_list.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->kwargContext);
        setState(287);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(290);
    match(blackbirdParser::RBRAC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KwargContext ------------------------------------------------------------------

blackbirdParser::KwargContext::KwargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::KwargContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::KwargContext::ASSIGN() {
  return getToken(blackbirdParser::ASSIGN, 0);
}

blackbirdParser::ValContext* blackbirdParser::KwargContext::val() {
  return getRuleContext<blackbirdParser::ValContext>(0);
}

tree::TerminalNode* blackbirdParser::KwargContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

tree::TerminalNode* blackbirdParser::KwargContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}

blackbirdParser::VallistContext* blackbirdParser::KwargContext::vallist() {
  return getRuleContext<blackbirdParser::VallistContext>(0);
}


size_t blackbirdParser::KwargContext::getRuleIndex() const {
  return blackbirdParser::RuleKwarg;
}


std::any blackbirdParser::KwargContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitKwarg(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::KwargContext* blackbirdParser::kwarg() {
  KwargContext *_localctx = _tracker.createInstance<KwargContext>(_ctx, getState());
  enterRule(_localctx, 54, blackbirdParser::RuleKwarg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(blackbirdParser::NAME);
    setState(293);
    match(blackbirdParser::ASSIGN);
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS:
      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::STR:
      case blackbirdParser::BOOL:
      case blackbirdParser::PI:
      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::TAN:
      case blackbirdParser::ARCSIN:
      case blackbirdParser::ARCCOS:
      case blackbirdParser::ARCTAN:
      case blackbirdParser::SINH:
      case blackbirdParser::COSH:
      case blackbirdParser::TANH:
      case blackbirdParser::ARCSINH:
      case blackbirdParser::ARCCOSH:
      case blackbirdParser::ARCTANH:
      case blackbirdParser::EXP:
      case blackbirdParser::LOG:
      case blackbirdParser::LBRAC:
      case blackbirdParser::LBRACE:
      case blackbirdParser::REGREF:
      case blackbirdParser::NAME: {
        setState(294);
        val();
        break;
      }

      case blackbirdParser::LSQBRAC: {
        setState(295);
        match(blackbirdParser::LSQBRAC);
        setState(297);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 360438053510102534) != 0) {
          setState(296);
          vallist();
        }
        setState(299);
        match(blackbirdParser::RSQBRAC);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValContext ------------------------------------------------------------------

blackbirdParser::ValContext::ValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

blackbirdParser::NonnumericContext* blackbirdParser::ValContext::nonnumeric() {
  return getRuleContext<blackbirdParser::NonnumericContext>(0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ValContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}


size_t blackbirdParser::ValContext::getRuleIndex() const {
  return blackbirdParser::RuleVal;
}


std::any blackbirdParser::ValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVal(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ValContext* blackbirdParser::val() {
  ValContext *_localctx = _tracker.createInstance<ValContext>(_ctx, getState());
  enterRule(_localctx, 56, blackbirdParser::RuleVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case blackbirdParser::STR:
      case blackbirdParser::BOOL: {
        setState(302);
        nonnumeric();
        break;
      }

      case blackbirdParser::PLUS:
      case blackbirdParser::MINUS:
      case blackbirdParser::INT:
      case blackbirdParser::FLOAT:
      case blackbirdParser::COMPLEX:
      case blackbirdParser::PI:
      case blackbirdParser::SQRT:
      case blackbirdParser::SIN:
      case blackbirdParser::COS:
      case blackbirdParser::TAN:
      case blackbirdParser::ARCSIN:
      case blackbirdParser::ARCCOS:
      case blackbirdParser::ARCTAN:
      case blackbirdParser::SINH:
      case blackbirdParser::COSH:
      case blackbirdParser::TANH:
      case blackbirdParser::ARCSINH:
      case blackbirdParser::ARCCOSH:
      case blackbirdParser::ARCTANH:
      case blackbirdParser::EXP:
      case blackbirdParser::LOG:
      case blackbirdParser::LBRAC:
      case blackbirdParser::LBRACE:
      case blackbirdParser::REGREF:
      case blackbirdParser::NAME: {
        setState(303);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VallistContext ------------------------------------------------------------------

blackbirdParser::VallistContext::VallistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<blackbirdParser::ValContext *> blackbirdParser::VallistContext::val() {
  return getRuleContexts<blackbirdParser::ValContext>();
}

blackbirdParser::ValContext* blackbirdParser::VallistContext::val(size_t i) {
  return getRuleContext<blackbirdParser::ValContext>(i);
}

std::vector<tree::TerminalNode *> blackbirdParser::VallistContext::COMMA() {
  return getTokens(blackbirdParser::COMMA);
}

tree::TerminalNode* blackbirdParser::VallistContext::COMMA(size_t i) {
  return getToken(blackbirdParser::COMMA, i);
}


size_t blackbirdParser::VallistContext::getRuleIndex() const {
  return blackbirdParser::RuleVallist;
}


std::any blackbirdParser::VallistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVallist(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::VallistContext* blackbirdParser::vallist() {
  VallistContext *_localctx = _tracker.createInstance<VallistContext>(_ctx, getState());
  enterRule(_localctx, 58, blackbirdParser::RuleVallist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    val();
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == blackbirdParser::COMMA) {
      setState(307);
      match(blackbirdParser::COMMA);
      setState(308);
      val();
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangevalContext ------------------------------------------------------------------

blackbirdParser::RangevalContext::RangevalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> blackbirdParser::RangevalContext::INT() {
  return getTokens(blackbirdParser::INT);
}

tree::TerminalNode* blackbirdParser::RangevalContext::INT(size_t i) {
  return getToken(blackbirdParser::INT, i);
}

std::vector<tree::TerminalNode *> blackbirdParser::RangevalContext::COLON() {
  return getTokens(blackbirdParser::COLON);
}

tree::TerminalNode* blackbirdParser::RangevalContext::COLON(size_t i) {
  return getToken(blackbirdParser::COLON, i);
}


size_t blackbirdParser::RangevalContext::getRuleIndex() const {
  return blackbirdParser::RuleRangeval;
}


std::any blackbirdParser::RangevalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitRangeval(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::RangevalContext* blackbirdParser::rangeval() {
  RangevalContext *_localctx = _tracker.createInstance<RangevalContext>(_ctx, getState());
  enterRule(_localctx, 60, blackbirdParser::RuleRangeval);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    match(blackbirdParser::INT);
    setState(315);
    match(blackbirdParser::COLON);
    setState(316);
    match(blackbirdParser::INT);
    setState(319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == blackbirdParser::COLON) {
      setState(317);
      match(blackbirdParser::COLON);
      setState(318);
      match(blackbirdParser::INT);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

blackbirdParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t blackbirdParser::ExpressionContext::getRuleIndex() const {
  return blackbirdParser::RuleExpression;
}

void blackbirdParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParameterLabelContext ------------------------------------------------------------------

blackbirdParser::ParameterContext* blackbirdParser::ParameterLabelContext::parameter() {
  return getRuleContext<blackbirdParser::ParameterContext>(0);
}

blackbirdParser::ParameterLabelContext::ParameterLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::ParameterLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitParameterLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracketsLabelContext ------------------------------------------------------------------

tree::TerminalNode* blackbirdParser::BracketsLabelContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::BracketsLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::BracketsLabelContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

blackbirdParser::BracketsLabelContext::BracketsLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::BracketsLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitBracketsLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignLabelContext ------------------------------------------------------------------

blackbirdParser::ExpressionContext* blackbirdParser::SignLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::SignLabelContext::PLUS() {
  return getToken(blackbirdParser::PLUS, 0);
}

tree::TerminalNode* blackbirdParser::SignLabelContext::MINUS() {
  return getToken(blackbirdParser::MINUS, 0);
}

blackbirdParser::SignLabelContext::SignLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::SignLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitSignLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerLabelContext ------------------------------------------------------------------

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::PowerLabelContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::PowerLabelContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

tree::TerminalNode* blackbirdParser::PowerLabelContext::PWR() {
  return getToken(blackbirdParser::PWR, 0);
}

blackbirdParser::PowerLabelContext::PowerLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::PowerLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitPowerLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberLabelContext ------------------------------------------------------------------

blackbirdParser::NumberContext* blackbirdParser::NumberLabelContext::number() {
  return getRuleContext<blackbirdParser::NumberContext>(0);
}

blackbirdParser::NumberLabelContext::NumberLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::NumberLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNumberLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableLabelContext ------------------------------------------------------------------

tree::TerminalNode* blackbirdParser::VariableLabelContext::REGREF() {
  return getToken(blackbirdParser::REGREF, 0);
}

tree::TerminalNode* blackbirdParser::VariableLabelContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

blackbirdParser::VariableLabelContext::VariableLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::VariableLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitVariableLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayIdxLabelContext ------------------------------------------------------------------

tree::TerminalNode* blackbirdParser::ArrayIdxLabelContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::ArrayIdxLabelContext::LSQBRAC() {
  return getToken(blackbirdParser::LSQBRAC, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::ArrayIdxLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::ArrayIdxLabelContext::RSQBRAC() {
  return getToken(blackbirdParser::RSQBRAC, 0);
}

blackbirdParser::ArrayIdxLabelContext::ArrayIdxLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::ArrayIdxLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitArrayIdxLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulLabelContext ------------------------------------------------------------------

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::MulLabelContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::MulLabelContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

tree::TerminalNode* blackbirdParser::MulLabelContext::TIMES() {
  return getToken(blackbirdParser::TIMES, 0);
}

tree::TerminalNode* blackbirdParser::MulLabelContext::DIVIDE() {
  return getToken(blackbirdParser::DIVIDE, 0);
}

blackbirdParser::MulLabelContext::MulLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::MulLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitMulLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionLabelContext ------------------------------------------------------------------

blackbirdParser::FunctionContext* blackbirdParser::FunctionLabelContext::function() {
  return getRuleContext<blackbirdParser::FunctionContext>(0);
}

tree::TerminalNode* blackbirdParser::FunctionLabelContext::LBRAC() {
  return getToken(blackbirdParser::LBRAC, 0);
}

blackbirdParser::ExpressionContext* blackbirdParser::FunctionLabelContext::expression() {
  return getRuleContext<blackbirdParser::ExpressionContext>(0);
}

tree::TerminalNode* blackbirdParser::FunctionLabelContext::RBRAC() {
  return getToken(blackbirdParser::RBRAC, 0);
}

blackbirdParser::FunctionLabelContext::FunctionLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::FunctionLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitFunctionLabel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddLabelContext ------------------------------------------------------------------

std::vector<blackbirdParser::ExpressionContext *> blackbirdParser::AddLabelContext::expression() {
  return getRuleContexts<blackbirdParser::ExpressionContext>();
}

blackbirdParser::ExpressionContext* blackbirdParser::AddLabelContext::expression(size_t i) {
  return getRuleContext<blackbirdParser::ExpressionContext>(i);
}

tree::TerminalNode* blackbirdParser::AddLabelContext::PLUS() {
  return getToken(blackbirdParser::PLUS, 0);
}

tree::TerminalNode* blackbirdParser::AddLabelContext::MINUS() {
  return getToken(blackbirdParser::MINUS, 0);
}

blackbirdParser::AddLabelContext::AddLabelContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any blackbirdParser::AddLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitAddLabel(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ExpressionContext* blackbirdParser::expression() {
   return expression(0);
}

blackbirdParser::ExpressionContext* blackbirdParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  blackbirdParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  blackbirdParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, blackbirdParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BracketsLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(322);
      match(blackbirdParser::LBRAC);
      setState(323);
      expression(0);
      setState(324);
      match(blackbirdParser::RBRAC);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SignLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(326);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::PLUS

      || _la == blackbirdParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(327);
      expression(9);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(328);
      function();
      setState(329);
      match(blackbirdParser::LBRAC);
      setState(330);
      expression(0);
      setState(331);
      match(blackbirdParser::RBRAC);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NumberLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(333);
      number();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VariableLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(334);
      _la = _input->LA(1);
      if (!(_la == blackbirdParser::REGREF

      || _la == blackbirdParser::NAME)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ArrayIdxLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(335);
      match(blackbirdParser::NAME);
      setState(336);
      match(blackbirdParser::LSQBRAC);
      setState(337);
      expression(0);
      setState(338);
      match(blackbirdParser::RSQBRAC);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParameterLabelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(340);
      parameter();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(354);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(352);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(343);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(344);
          match(blackbirdParser::PWR);
          setState(345);
          expression(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(346);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(347);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::TIMES

          || _la == blackbirdParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(348);
          expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddLabelContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(349);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(350);
          _la = _input->LA(1);
          if (!(_la == blackbirdParser::PLUS

          || _la == blackbirdParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(351);
          expression(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(356);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

blackbirdParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::ParameterContext::LBRACE() {
  return getToken(blackbirdParser::LBRACE, 0);
}

tree::TerminalNode* blackbirdParser::ParameterContext::NAME() {
  return getToken(blackbirdParser::NAME, 0);
}

tree::TerminalNode* blackbirdParser::ParameterContext::RBRACE() {
  return getToken(blackbirdParser::RBRACE, 0);
}


size_t blackbirdParser::ParameterContext::getRuleIndex() const {
  return blackbirdParser::RuleParameter;
}


std::any blackbirdParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::ParameterContext* blackbirdParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 64, blackbirdParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(blackbirdParser::LBRACE);
    setState(358);
    match(blackbirdParser::NAME);
    setState(359);
    match(blackbirdParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

blackbirdParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::NumberContext::INT() {
  return getToken(blackbirdParser::INT, 0);
}

tree::TerminalNode* blackbirdParser::NumberContext::FLOAT() {
  return getToken(blackbirdParser::FLOAT, 0);
}

tree::TerminalNode* blackbirdParser::NumberContext::COMPLEX() {
  return getToken(blackbirdParser::COMPLEX, 0);
}

tree::TerminalNode* blackbirdParser::NumberContext::PI() {
  return getToken(blackbirdParser::PI, 0);
}


size_t blackbirdParser::NumberContext::getRuleIndex() const {
  return blackbirdParser::RuleNumber;
}


std::any blackbirdParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::NumberContext* blackbirdParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 66, blackbirdParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 36352) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

blackbirdParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* blackbirdParser::FunctionContext::SIN() {
  return getToken(blackbirdParser::SIN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::COS() {
  return getToken(blackbirdParser::COS, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::TAN() {
  return getToken(blackbirdParser::TAN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCSIN() {
  return getToken(blackbirdParser::ARCSIN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCCOS() {
  return getToken(blackbirdParser::ARCCOS, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCTAN() {
  return getToken(blackbirdParser::ARCTAN, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::SINH() {
  return getToken(blackbirdParser::SINH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::COSH() {
  return getToken(blackbirdParser::COSH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::TANH() {
  return getToken(blackbirdParser::TANH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCSINH() {
  return getToken(blackbirdParser::ARCSINH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCCOSH() {
  return getToken(blackbirdParser::ARCCOSH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::ARCTANH() {
  return getToken(blackbirdParser::ARCTANH, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::SQRT() {
  return getToken(blackbirdParser::SQRT, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::LOG() {
  return getToken(blackbirdParser::LOG, 0);
}

tree::TerminalNode* blackbirdParser::FunctionContext::EXP() {
  return getToken(blackbirdParser::EXP, 0);
}


size_t blackbirdParser::FunctionContext::getRuleIndex() const {
  return blackbirdParser::RuleFunction;
}


std::any blackbirdParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<blackbirdVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

blackbirdParser::FunctionContext* blackbirdParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 68, blackbirdParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 549739036672) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool blackbirdParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 31: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool blackbirdParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void blackbirdParser::initialize() {
  ::antlr4::internal::call_once(blackbirdParserOnceFlag, blackbirdParserInitialize);
}
