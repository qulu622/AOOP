#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Stack::Stack() {
  top = NULL;
}

void Stack::push(int x) {
  Data* tmp = (Data*)malloc(sizeof(Data)); // c++ need typecast
  tmp->num = x;
  tmp->next = top;
  top = tmp;
}

int Stack::pop() {
  if ( top != NULL ) {
    Data* tmp = top;
    int num = tmp->num;
    top = top->next;
    free(tmp);
    return num;    
  }

  cout << "Stack is empty." << endl;
  return -1;
}
