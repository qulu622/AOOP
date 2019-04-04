#include "type.h"

Type::Type(string s, int tag, int w): Word(s, tag) {
  width = w;
}

bool Type::numeric(Type p) {
  if (p == Char || p == Int || p == Float)
    return true;
  else
    return false;
}

Type Type::max(Type p1, Type p2) {
  if (!numeric(p1) || !numeric(p2))
    return Null;
  else if (p1 == Float || p2 == Float)
    return Float;
  else if (p1 == Int || p2 == Int)
    return Int;
  else
    return Char;
}

bool operator == (const Type & t1, const Type & t2) {
  if (t1.tag == t2.tag && t1.lexeme == t2.lexeme && t1.width == t2.width)
    return true;
  else
    return false;
}
