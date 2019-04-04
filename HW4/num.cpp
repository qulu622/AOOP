#include "num.h"
#include "tag.h"

Num::Num(int v): Token(Tag::NUM) {
  value = v;
}

string Num::toString() {
  stringstream ss;
  ss << value;
  return ss.str();
}
