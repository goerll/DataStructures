#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
  struct linked_item* head;
  struct linked_item* tail;
} linked_list;

typedef struct linked_item{
  struct linked_item* next;
  struct linked_item* previous;
  int value;
} linked_item;

linked_list* init_list(){
  linked_list* new_list = malloc(sizeof(linked_list));
  new_list->head = NULL;
  new_list->tail = NULL;

  return new_list;
}

void destroy_list(linked_list* list){
  linked_item* current = list->head;
  linked_item* next;

  while(next != 0){
    free(current);
    current = next;
    next = next->next;
  }

  free(current);
  free(list);
}

void print_list(linked_list* list){
  linked_item* current = list->head;

  printf("[%d", current->value);

  while(current->next != 0){
    current = current->next;
    printf(", %d", current->value);
  }

  printf("]\n");
}

void append(linked_list* list, int value){
  linked_item* new_item = malloc(sizeof(linked_item));

  new_item->value = value;
  new_item->previous = list->tail;
  new_item->next = NULL;

  list->tail = new_item;

  if(list->head == NULL){
    list->head = new_item;
  }
  else{
    list->tail->next = new_item;
  }
}

int main(){
  linked_list* lista = init_list();

  append(lista, 10);
  append(lista, 10);
  append(lista, 10);
  append(lista, 10);

  print_list(lista);

  destroy_list(lista);
}
