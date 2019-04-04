#ifndef __NUM_H__
#define __NUM_H__

#include "token.h"

class Num: public Token {
public:
  int value;
  Num(int v);
  string toString();
};

#endif
