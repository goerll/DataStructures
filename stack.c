#include <stdio.h>

typedef struct stack{
  int value;
  struct stack* below;
} stack;
