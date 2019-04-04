#include "DForm.h"

ostream &operator<<(ostream &o, const DForm &df) {
    ostringstream os;
    os.precision(df.f.prc);
    os.setf((ios_base::fmtflags)df.f.frm, ios_base::floatfield);
    os << df.d;
    return o << os.str();
}
