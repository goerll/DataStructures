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

void initialize_list(struct list* list, int value){
  struct item* new_item = malloc(sizeof(struct item));

  list->head = new_item;
  list->tail = new_item;

  new_item->previous = NULL;
  new_item->next = NULL;
  new_item->value = value;
}

void print_list(struct list* list){
  struct item* item = list->head;
  printf("[%d", item->value);
  while(item->next != 0){
    item = item->next;
    printf(", %d", item->value);
  }
  printf("]\n");
  printf("Head: %d\n", list->head->value);
  printf("Tail: %d\n", list->tail->value);
}

void append(struct list* list, int value){
  struct item* new_item = malloc(sizeof(struct item));

  new_item->value = value;
  new_item->previous = list->tail;
  new_item->next = NULL;

  list->tail->next = new_item;
  list->tail = new_item;
}

void prepend(struct list* list, int value){
  struct item* new_item = malloc(sizeof(struct item));

  new_item->value = value;
  new_item->previous = NULL;
  new_item->next = list->head;

  list->head->previous = new_item;
  list->head = new_item;
}

int len(struct list* list){
  int i = 1;
  struct item* item = list->head;

  while(item->next != 0){
    i++;
    item = item->next;
  }

  return i;
}

int min(struct list* list){
  struct item* item = list->head;
  int min = item->value;

  while(item->next != 0){
    if(item->value < min){
      min = item->value;
    }
  }

  return min;
}

int max(struct list* list){
  struct item* item = list->head;
  int max = item->value;

  while(item->next != 0){
    if(item->value > max){
      max = item->value;
    }
  }

  return max;
}

int search_index(struct list* list, int index){
  if(index < 0){
    int i = -1;
    struct item* item = list->tail;

    while(i != index){
      i--;
      item = item->previous;
    }

    return item->value;
  }
  else{
    int i = 0;
    struct item* item = list->head;

    while(i != index){
      item = item->next;
      i++;
    }

    return item->value;
  }
}

int search_value(struct list* list, int value){
  struct item* item = list->head;
  int i = 0;

  while(item->next != 0){
    if(item->value == value){
      return i;
    }
    i++;
    item = item->next;
  }

  return -1;
}

int main(){
  struct list* lista;
  initialize_list(lista, 5);

  append(lista, 10);
  prepend(lista, 10);

  print_list(lista);
  printf("%d\n",len(lista));

  printf("%d\n", search_index(lista, -2));
 
  printf("%d\n", search_value(lista, 10));
}
