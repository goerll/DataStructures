#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
  struct item* top;
} stack;

typedef struct item{
  int value;
  struct item* below;
} item;

stack* init_stack(){
  stack* new_stack = malloc(sizeof(stack));
  new_stack->top = NULL;

  return new_stack;
}

void print_stack(stack* stack){
  struct item* item = stack->top;
  printf("[%d", item->value);
  while(item->below != 0){
    item = item->below;
    printf(", %d", item->value);
  }
  printf("]\n");
}

void push(stack* stack, int value){
  item* new_item = malloc(sizeof(item));

  new_item->value = value;
  new_item->below = stack->top;

  stack->top = new_item;
}

int pop(stack* stack){
  item* popped_item = stack->top;
  int popped_value = popped_item->value;

  stack->top = stack->top->below;
  free(popped_item);

  return popped_value;
}

int main(){
  stack* stack1 = init_stack();
  push(stack1, 10);
  push(stack1, 10);
  push(stack1, 10);
  push(stack1, 10);
  pop(stack1);
  print_stack(stack1);
}
