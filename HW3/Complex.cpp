#include "Complex.h"
#include <cmath>

using namespace std;

Complex::Complex(const double re, const double im) {
  this->real = re;
  this->imag = im;
}

Complex::Complex(const Complex &c) {
  this->real = c.real;
  this->imag = c.imag;
}

Complex &Complex::operator=(const Complex &c) {
  this->real = c.real;
  this->imag = c.imag;
  return *this;
}

Complex Complex::Polar(const double leng, const double arg) {
  this->real = leng * cos(arg);
  this->imag = leng * sin(arg);
  return *this;
}

double Complex::Real() {
  return this->real;
}

double Complex::Imag() {
  return this->imag;
}

double Complex::Norm() {
  return this->real * this->real + this->imag * this->imag;
}

double Complex::Abs() {
  return sqrt(this->Norm());
}

double Complex::Arg() {
  return atan(this->imag/this->real);
}

Complex Complex::operator++() {
  this->real++;
  this->imag++;
  return *this;
}

Complex Complex::operator++(int) {
  Complex tmp(*this);
  ++*this;
  return tmp;
}

Complex Complex::operator--() {
  this->real--;
  this->imag--;
  return *this;
}

Complex Complex::operator--(int) {
  Complex tmp(*this);
  --*this;
  return tmp;
}

Complex::~Complex() {
}

Complex Polar(const double leng, const double arg) {
  return Complex(leng*cos(arg),leng*sin(arg));
}

double Norm(const Complex &x) {
  return x.real * x.real + x.imag * x.imag;
}

double Abs(const Complex &x) {
  return sqrt(Norm(x));
}

double Arg(const Complex &x) {
  return atan(x.imag/x.real);
}

Complex operator+(const Complex &x, const Complex &y) {
  return Complex(x.real+y.real,x.imag+y.imag);
}

Complex operator-(const Complex &x, const Complex &y) {
  return Complex(x.real-y.real,x.imag-y.imag);
}

Complex operator*(const Complex &x, const Complex &y) {
  return Complex(x.real*y.real-x.imag*y.imag,x.real*y.imag+y.real*x.imag);
}

Complex operator/(const Complex &x, const Complex &y) {
  return Complex((x.real*y.real+x.imag*y.imag)/Norm(y),(x.imag*y.real-x.real*y.imag)/Norm(y));
}

Complex operator+=(Complex &x, const Complex &y) {
  x = x+y;
  return x;
}

Complex operator-=(Complex &x, const Complex &y) {
  x = x-y;
  return x;
}

Complex operator*=(Complex &x, const Complex &y) {
  x = x*y;
  return x;
}

Complex operator/=(Complex &x, const Complex &y) {
  x = x/y;
  return x;
}

bool operator==(const Complex &x, const Complex &y) {
  return (x.real == y.real && x.imag == y.imag);
}

bool operator!=(const Complex &x, const Complex &y) {
  return !(x == y);
}

ostream &operator<<(ostream &o, const Complex &x) {
  o << '(' << x.real << ',' << x.imag << ')';
  return o;
}
