#ifndef __DFORM_H__
#define __DFORM_H__

#include "Form.h"

#include <iostream>

using namespace std;

class Form;

struct DForm {
  const Form &f;
  double d;
  DForm(const Form &ff, double dd): f(ff), d(dd){
  }
  friend ostream &operator<<(ostream &o, const DForm &df);
};

#endif
