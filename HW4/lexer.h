#ifndef __LEXER_H__
#define __LEXER_H__

#include "num.h"
#include "real.h"
#include "tag.h"
#include "token.h"
#include "type.h"
#include "word.h"

#include <map>
#include <ctype.h>

class Lexer {
public:
  int line;
  Lexer();
  Token scan();

private:
  char peek;
  map<string, Word> words;
  void reserve(Word w);
  void readch();
  bool readch(char c);
};

#endif
