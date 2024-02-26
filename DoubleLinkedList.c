#include <stdio.h>
#include <stdlib.h>

struct item{
  struct item* previous;
  struct item* next;
  int value;
};

struct list{
  struct item* head;
  struct item* tail;
};

void initialize_list(struct list *list, int value){
  struct item* new_item = malloc(sizeof(struct item));
  list->head = new_item;
  list->tail = new_item;
  new_item->previous = NULL;
  new_item->next = NULL;
  new_item->value = value;
}

void append(struct list *list, int value){
  struct item *new_item = malloc(sizeof(struct item));

  new_item->value = value;
  new_item->previous = list->tail;
  new_item->next = NULL;

  list->tail->next = new_item;
  list->tail = new_item;
}

void prepend(struct list *list, int value){
  struct item *new_item = malloc(sizeof(struct item));

  new_item->value = value;
  new_item->previous = NULL;
  new_item->next = list->head;

  list->head->previous = new_item;
  list->head = new_item;
}

void print_list(struct list *list){
  struct item *item = list->head;
  printf("[%d", item->value);
  while(item->next != 0){
    item = item->next;
    printf(", %d", item->value);
  }
  printf("]\n");
  printf("Head: %d\n", list->head->value);
  printf("Tail: %d\n", list->tail->value);
}

int main(){
  struct list *lista;
  initialize_list(lista, 5);

  append(lista, 10);
  prepend(lista, 10);

  print_list(lista);
}
