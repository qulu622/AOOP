#include "token.h"

Token::Token(int t) {
  tag = t;
}

string Token::toString() {
  

  if (tag < 256 || tag > 275) {
    cout << "Token: " << left << setw(8) << string(1, (char)tag);
    return "(" + string(1, (char)tag) + ")";
  }

  switch(tag) {
    case 256:
      cout << "Token: " << left << setw(8) << "&&";
      return "(AND)" ;
    case 257:
      return "(BASIC)" ;
    case 258:
      return "(BREAK)" ;
    case 259:
      return "(DO)" ;
    case 260:
      return "(ELSE)" ;
    case 261:
      cout << "Token: " << left << setw(8) << "==";
      return "(EQ)" ;
    case 262:
      return "(FALSE)" ;
    case 263:
      cout << "Token: " << left << setw(8) << ">=";
      return "(GE)" ;
    case 264:
      return "(ID)" ;
    case 265:
      return "(IF)" ;
    case 266:
      return "(INDEX)" ;
    case 267:
      cout << "Token: " << left << setw(8) << "<=";
      return "(LE)" ;
    case 268:
      return "(MINUS)" ;
    case 269:
      cout << "Token: " << left << setw(8) << "!=";
      return "(NE)" ;
    case 270:
      return "(NUM)" ;
    case 271:
      cout << "Token: " << left << setw(8) << "||";
      return "(OR)" ;
    case 272:
      return "(REAL)" ;
    case 273:
      return "(TEMP)" ;
    case 274:
      return "(TRUE)" ;
    case 275:
      return "(WHILE)" ;
  }

  return "";
}
