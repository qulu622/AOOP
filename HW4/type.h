#ifndef __TYPE_H__
#define __TYPE_H__

#include "word.h"

class Type: public Word {
public:
  int width;
  Type(string s, int tag, int w);
  static bool numeric(Type p);
  static Type max(Type p1, Type p2);
  friend bool operator == (const Type & t1, const Type & t2);
};

static const Type Int("int", Tag::BASIC, 4),
                  Float("float", Tag::BASIC, 8),
                  Char("char", Tag::BASIC, 1),
                  Bool("bool", Tag::BASIC, 1),
                  Null("null", 0,0);

#endif
