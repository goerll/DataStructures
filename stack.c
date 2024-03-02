#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
  struct item* top;
} stack;

typedef struct item{
  int value;
  stack* below;
} item;

stack* init_stack(){
  stack* new_stack = malloc(sizeof(stack));
  new_stack->top = NULL;

  return new_stack;
}


