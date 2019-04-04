#ifndef __MYTAR_H__
#define __MYTAR_H__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct TarHeader {
  char filename[100];
  char filemode[8];
  char userid[8];
  char groupid[8];
  char filesize[12];
  char mtime[12];
  char checksum[8];
  char type[1];
  char lname[100];

  // Ustar Section
  char USTAR_id[6];
  char USTAR_ver[2];
  char username[32];
  char groupname[32];
  char devmajor[8];
  char devminor[8];
  char prefix[155];
  char pad[12];
}; //total 512 bytes

class Tar{
public:
  Tar(const char *fName);
  ~Tar();
  void getTar();
  void show();
private:
  ifstream fin;
  int fLength;
  vector <TarHeader> vec;
  void type(int num);
  void mod(int mode);
  int transOctal(char filesize[12]);
};

#endif
