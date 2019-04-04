#ifndef __STACK_H__
#define __STACK_H__

// c++ by default -> private

class Data {
  friend class Stack; // to access private
  int num;
  Data* next;
};

class Stack {
  Data* top;
  
public:
  Stack(); // constructor

  void push(int x);
  int pop();
};

#endif
