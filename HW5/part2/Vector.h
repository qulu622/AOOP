#ifndef __VECTOR_H__
#define __VECTOR_H__

#define __TRACE__

#include "Trace.h"

#include <string>
#include <vector>

using namespace std;

static int count = 1;

template<typename T>
class Vector {
public:
  Vector( int size ) {
    TRACE(tmp, "vector<T>::vector(int)");
    cout << "  count = " << count << endl;
    this->size = size;
    vec = new T[size];
  }

  ~Vector() {
    TRACE(tmp, "vector<T>::~vector");
    cout << "  count = " << count << endl;
    delete [] vec;
  }

  T &elem(int index) {
    return vec[index];
  }

  T &operator[](int index) {
    return vec[index];
  }

private:
  T *vec;
  int size;
};

template<>
class Vector<void *> {
public:
  Vector( int size ) {
    TRACE(tmp, "vector<void*>::vector(int)");
    cout << "  count = " << count << endl;
    this->size = size;
    ptr = new void*[size];
  }

  ~Vector() {
    TRACE(tmp, "vector<void*>::~vector");
    cout << "  count = " << count << endl;
    delete [] ptr;
  }

  void *&elem(int index) {
    return ptr[index];
  }

  void *&operator[](int index) {
    return ptr[index];
  }

private:
  void **ptr;
  int size;
};

template<typename T>
class Vector<T *>: public Vector<void *> {
public:
  typedef Vector<void *> Base;
  Vector( int size ): Base(size) {
    TRACE(tmp, "vector<T*>::vector(int)");
    count++;
    this->size = size;
    ptr = new void*[size];
  }

  ~Vector() {
    TRACE(tmp, "vector<T*>::~vector");
    count--;
    delete [] ptr;
  }

  T *&elem(int index) {
    return reinterpret_cast<T *&>( ptr[index]);
  }

  T *&operator[](int index) {
    return reinterpret_cast<T *&>( ptr[index]);
  }

private:
  void **ptr;
  int size;
};

#endif
