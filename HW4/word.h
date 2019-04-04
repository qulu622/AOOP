#ifndef __WORD_H__
#define __WORD_H__

#include "token.h"
#include "tag.h"

class Word: public Token {
public:
  string lexeme;
  Word(string s, int tag);
  string toString();

 
};

static const Word AND("&&", Tag::AND),
                  OR("||", Tag::OR),
                  eq("==", Tag::EQ),
                  ne("!=", Tag::NE),
                  le("<=", Tag::LE),
                  ge(">=", Tag::GE),
                  minus("minus", Tag::MINUS),
                  True("true", Tag::TRUE),
                  False("false", Tag::FALSE),
                  temp("t", Tag::TEMP);

#endif
