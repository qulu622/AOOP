#include "real.h"
#include "tag.h"

Real::Real(float v): Token(Tag::REAL) {
  value = v;
}

string Real::toString() {
  stringstream ss;
  ss << value;
  return ss.str();
}
