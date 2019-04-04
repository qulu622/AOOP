#ifndef __REAL_H__
#define __REAL_H__

#include "token.h"

class Real: public Token {
public:
  float value;
  Real(float v);
  string toString();
};

#endif
