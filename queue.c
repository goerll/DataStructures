#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
} node;

typedef struct queue {
  node* first;
} queue;

node* initNode(int value){
  node* new = malloc(sizeof(node));
  new->value = value;
  new->next = NULL;

  return new;
}

queue* initQueue (int value) {
  queue* new = malloc(sizeof(queue));
  new->first = initNode(value);

  return new;
}

void printQueue (queue* queue) {
  node* current = queue->first;
  while (current) {
    printf("%d ", current->value);
    current = current->next;
  }
  puts("");
}

void enqueue (queue* queue, int value) {
  node* new = initNode(value);
  new->next = queue->first;
  queue->first = new;
}

int dequeue (queue* queue) {
  node* current = queue->first;

  while (current->next->next) {
    current = current->next;
  }

  int first_value = current->next->value;
  free(current->next);
  current->next = NULL;

  return first_value;
}

int main () {
  queue* my_queue = initQueue(5);
  printQueue(my_queue);
  enqueue(my_queue, 6);
  enqueue(my_queue, 5);
  enqueue(my_queue, 4);
  enqueue(my_queue, 3);
  enqueue(my_queue, 2);
  enqueue(my_queue, 1);
  printQueue(my_queue);
  dequeue(my_queue);
  dequeue(my_queue);
  dequeue(my_queue);
  dequeue(my_queue);
  printQueue(my_queue);
}
