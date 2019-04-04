#include "lexer.h"

int main() {
  Lexer lexer;

  try {
    while (true) {
      Token t = lexer.scan();
      cout << t.toString() << endl;
    }
  } 
  catch (int num) { // throw -1 for EOF
    cout << "End of file reached" << endl;
  }
}
