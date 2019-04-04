#include "word.h"

Word::Word(string s, int tag): Token(tag) {
  lexeme = s;
}

string Word::toString() {
  return lexeme;
}
