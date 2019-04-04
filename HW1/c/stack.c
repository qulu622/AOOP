#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(struct stack* this, int x) {
  Data* tmp = malloc(sizeof(Data));
  tmp->num = x;
  tmp->next = this->top;
  this->top = tmp;
}

int pop(struct stack* this) {
  if ( this->top != NULL ) {
    Data* tmp = this->top;
    int num = tmp->num;
    this->top = this->top->next;
    free(tmp);    
    return num;
  }

  printf("Stack is empty.\n");
  return -1;
}

struct stack* new_stack() {
  struct stack* tmp = malloc(sizeof(struct stack));
  tmp->top = NULL;
  return tmp;  
}

void delete_stack(struct stack* stk) {
  free(stk);
}
