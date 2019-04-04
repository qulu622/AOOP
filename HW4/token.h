#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Token {
public:
  int tag;
  Token(int t);
  string toString();
};

#endif
