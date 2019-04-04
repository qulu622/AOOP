#ifndef __STACK_H__
#define __STACK_H__

typedef struct data {
  int num;
  struct data* next;
} Data;

struct stack {
  Data* top;
};

extern void push(struct stack* this, int x);
extern int pop(struct stack* this);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif
