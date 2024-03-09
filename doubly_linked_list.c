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
  linked_item* next = NULL;

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

  if(list->head == NULL){
    list->head = new_item;
  }
  else{
    list->tail->next = new_item;
  }

  list->tail = new_item;
}

void prepend(linked_list* list, int value){
  linked_item* new_item = malloc(sizeof(linked_item));

  new_item->value = value;
  new_item->previous = NULL;
  new_item->next = list->head;

  if(list->tail == NULL){
    list->tail = new_item;
  }
  else{
    list->head->previous = new_item;
  }

  list->head = new_item;
}

int len(linked_list* list){
  int i = 1;
  linked_item* item = list->head;

  while(item->next != 0){
    i++;
    item = item->next;
  }

  return i;
}

int min(linked_list* list){
  linked_item* item = list->head;
  int min = item->value;

  while(item->next != 0){
    if(item->value < min){
      min = item->value;
    }
  }

  return min;
}

int max(linked_list* list){
  linked_item* item = list->head;
  int max = item->value;

  while(item->next != 0){
    if(item->value > max){
      max = item->value;
    }
  }

  return max;
}

linked_item* search_item(linked_list* list, int index){
  if(index < 0){
    int i = -1;
    linked_item* item = list->tail;

    while(i != index){
      i--;
      item = item->previous;
    }

    return item;
  }
  else{
    int i = 0;
    linked_item* item = list->head;

    while(i != index){
      item = item->next;
      i++;
    }

    return item;
  }
}

int search_index(linked_list* list, int index){
  if(index < 0){
    int i = -1;
    linked_item* item = list->tail;

    while(i != index){
      i--;
      item = item->previous;
    }

    return item->value;
  }
  else{
    int i = 0;
    linked_item* item = list->head;

    while(i != index){
      item = item->next;
      i++;
    }

    return item->value;
  }
}

int search_value(linked_list* list, int value){
  linked_item* item = list->head;
  int i = 0;

  while(item->value != value){
    i++;
    item = item->next;
  }

  return i;
}

void insert(linked_list* list, int index, int value){
  linked_item* new_item = malloc(sizeof(linked_item));
  linked_item* current_item = search_item(list, index-1);

  new_item->value = value;
  new_item->previous = current_item;
  new_item->next = current_item->next;
  current_item->next->previous = current_item;
  current_item->next = new_item;
}

int main(){
  linked_list* lista = init_list();

  append(lista, 10);
  append(lista, 10);
  append(lista, 10);
  append(lista, 10);
  prepend(lista, 5);
  insert(lista, 3, 13);
  print_list(lista);
  printf("%d\n", search_value(lista, 10));
  printf("%d\n", search_index(lista, 0));
  destroy_list(lista);
}
