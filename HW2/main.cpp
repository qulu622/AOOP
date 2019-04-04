#include "mytar.h"

int main(int argc, char *argv[] ) {
  Tar mytar(argv[1]);
  mytar.getTar();
  mytar.show();
  return 0;
}
