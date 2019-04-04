#include "Form.h"

DForm Form::operator() (double d) {
  return DForm(*this,d);
}


