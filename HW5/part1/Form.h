#ifndef __FORM_H__
#define __FORM_H__

#include "DForm.h"

#include <iostream>
#include <sstream>

using namespace std;

class DForm;

class Form {
public:
  explicit Form(int p) {
    prc = p;
    frm = 0;
  }

  DForm operator() (double d);

  Form &scientific() {
    frm = ios_base::scientific;
    return *this;
  }

  Form &fixed() {
    frm = ios_base::fixed;
    return *this;
  }

  Form &precision(int p) {
    prc = p;
    return *this;
  }

  int prc;
  int frm;
};

#endif
