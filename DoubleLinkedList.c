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

void initializeList(struct list *list, int value){
  struct item* newItem = malloc(sizeof(struct item));
  list->head = newItem;
  list->tail = newItem;
  newItem->previous = NULL;
  newItem->next = NULL;
  newItem->value = value;
}

void insertItemEnd(struct list *list, int value){
  struct item *newItem = malloc(sizeof(struct item));

  newItem->value = value;
  newItem->previous = list->tail;
  newItem->next = NULL;

  list->tail->next = newItem;
  list->tail = newItem;
}

void insertItemStart(struct list *list, int value){
  struct item *newItem = malloc(sizeof(struct item));

  newItem->value = value;
  newItem->previous = NULL;
  newItem->next = list->head;

  list->head->previous = newItem;
  list->head = newItem;
}

void printList(struct list *list){
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
  initializeList(lista, 5);

  insertItemEnd(lista, 10);
  insertItemStart(lista, 10);

  printList(lista);
}
