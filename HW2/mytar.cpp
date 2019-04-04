#include "mytar.h"

Tar::Tar(const char *fName) {
  fin.open(fName, ifstream::in | ifstream::binary);

  if (!fin.good()) {
    cout << "Not a ustar file." << endl << "File opening error." << endl;
    exit(0);
  }

  fin.seekg(0, ios::end);
  fLength = fin.tellg();

  if (fLength % 512 != 0) {
    cout << "Not a ustar file." << endl << "File opening error." << endl;
    exit(0);
  }

  // indicator -> ustar at byte 257
  char tmp[6];
  fin.seekg(257, ios::beg);
  fin.read(tmp,6);
  tmp[5] = '\0';

  if (strcmp(tmp,"ustar") != 0) {
    cout << "Not a ustar file." << endl << "File opening error." << endl;
    exit(0);
  }
}

Tar::~Tar() {
  fin.close();
}

void Tar::getTar() {
  fin.seekg(0, ios::beg);
  int count = 0;

  while( fLength > 0 ) {
    TarHeader tar;
    
    fin.seekg(count, ios::beg);
    // filename
    fin.seekg(0, ios::cur);
    fin.read(tar.filename,100);

    fin.seekg(count, ios::beg);
    // filemode
    fin.seekg(100, ios::cur);
    fin.read(tar.filemode,8);

    fin.seekg(count, ios::beg);
    // filesize
    fin.seekg(124, ios::cur);
    fin.read(tar.filesize,12);

    fin.seekg(count, ios::beg);
    // type
    fin.seekg(156, ios::cur);
    fin.read(tar.type,1);

    fin.seekg(count, ios::beg);
    // username
    fin.seekg(265, ios::cur);
    fin.read(tar.username,32);

    fin.seekg(count, ios::beg);
    // groupname
    fin.seekg(297, ios::cur);
    fin.read(tar.groupname,32);

    // length is rounded up to a multiple of 512 bytes
    int size = transOctal(tar.filesize);
    int num = 1;
    if (size != 0)
      num = size/512+1;
    if (size % 512 != 0)
      ++num;
    
    count += (512*num);
    fLength -= (512*num);

    if (fLength > 0)
      vec.push_back(tar);       
  }
}

void Tar::show() {
  cout << "total " << vec.size() << " files" << endl;

  for ( int i = 0; i < int(vec.size()); i++) {
    type(vec[i].type[0] - '0');
    mod(vec[i].filemode[4] - '0'); // owner
    mod(vec[i].filemode[5] - '0'); // group
    mod(vec[i].filemode[6] - '0'); // other

    cout << " " << left << setw(10) << vec[i].username
         << left << setw(10) << vec[i].groupname
         << right << setw(5) << transOctal(vec[i].filesize)
         << " " << vec[i].filename << endl;
  }

  fin.close();
}

void Tar::type(int num) {
  switch(num) {
    case 0:
      cout << "-";
      break;
    case 1:
      cout << "l";
      break;
    case 2:
      cout << "l";
      break;
    case 3:
      cout << "c";
      break;
    case 4:
      cout << "b";
      break;
    case 5:
      cout << "d";
      break;
    case 6:
      cout << "f";
      break;
    default:
      cout << "-" << endl;
      break;
  }
}

void Tar::mod(int mode) {
  switch(mode) {
    case 0:
      cout << "---";
      break;
    case 1:
      cout << "--x";
      break;
    case 2:
      cout << "-w-";
      break;
    case 3:
      cout << "-wx";
      break;
    case 4:
      cout << "r--";
      break;
    case 5:
      cout << "r-x";
      break;
    case 6:
      cout << "rw-";
      break;
    case 7:
      cout << "rwx";
      break;
    default:
      cout << "Mode is wrong!" << endl;
      break;
  }
}

int Tar::transOctal(char filesize[12]) {
  int ans = 0;
  for (int i = 0; i < 11; i++)
    ans += (filesize[i] - '0') * pow(8,10-i);

  return ans;
}
