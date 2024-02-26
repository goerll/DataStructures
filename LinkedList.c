#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

struct item{
  // The value that the item will hold
  int value;
  // A pointer to the next item
  struct item *next;
};

// Prints a item and all the following items linked to it
// I.e.: "[1, 2, 3, 4, 5]"
void print_list(struct item *item){
  printf("[%d", item->value);
  while(item->next != 0){
    item = item->next;
    printf(", %d", item->value);
  }
  printf("]\n");
}

// Allocates a memory adress to the first item
void initialize_list(struct item **item){
  *item = malloc(sizeof(struct item));
  (*item)->value = 0;
  (*item)->next = NULL;
}

// Inserts item at the end of the list
void append(struct item *item, int value){
  while(item->next != 0){
    item = item->next;
  }
  struct item *NewItem = malloc(sizeof(struct item));
  NewItem->value = value;
  NewItem->next = NULL;
  item->next = NewItem;
}

// Inserts item at the start and redefines the list head to point to the new item adress
// Receives the list's first item's memory adress as first argument (I.e.: &item)
void prepend(struct item **item, int value){
  struct item *NewItem = malloc(sizeof(struct item));
  NewItem->value = value;
  NewItem->next = *item;
  *item = NewItem;
}

// Returns the length of the list
int len(struct item *item){
  int i = 1;
  while(item->next != 0){
    i++;
    item = item->next;
  }
  return i;
}

// Returns the highest number on the list
int max(struct item *item){
  int max = item->value;
  while(item->next != 0){
    item = item->next;
    if(item->value > max)
      max = item->value;
  }

  return max;
}

// Returns the lowest number on the list
int min(struct item *item){
  int min = item->value;
  while(item->next != 0){
    if(item->value < min)
      min = item->value;
    item = item->next;
  }
  return min;
}

// Receives a number and returns the value at that index on the list
// Will return -1 if the index is higher than range, indexes lower than 0 work backwards
int search_index(struct item *item, int index){
  if(index < 0){
    index = len(item) + index;
  }
  for(int i = 0; i < index; i++){
    item = item->next;
    if(item->next == 0 && i != index){
      return -1;
    }
  }
  return item->value;
}

// Returns the index of the first ocurrence of the value it receives
int search_value(struct item *item, int value){
  int i = 0;

  while(item->next != 0){
    if(item->value == value){
      return i;
    }
    item = item->next;
    i++;
  }
  return -1;
}

// KILLS the list
void destroy_list(struct item **list){
  struct item *next = (*list)->next;
  while(next != 0){
    free(*list);
    *list = next;
    next = next->next;
  }
}

// Removes the last element of the list and returns it's value
int pop(struct item *list){
  int i;

  while(list->next->next != 0){
    list = list->next;
  }
  i = list->next->value;
  free(list->next);
  list->next = NULL;

  return i;
}

// Testing all this madness
int main(){
  printf("Tá rodando\n");

  struct item *List1;
  initialize_list(&List1);
  List1->value = 1;

  append(List1, 3);
  append(List1, 3);
  prepend(&List1, 4);
  append(List1, 5);
  append(List1, 5);
  append(List1, 10);

  print_list(List1);
  printf("Len: %d\n", len(List1));
  printf("Min: %d\n", min(List1));
  printf("Max: %d\n", max(List1));

  prepend(&List1, 0);
  print_list(List1);
  printf("%d\n", search_index(List1, -2));
  printf("%d\n", search_value(List1, 3));
  printf("d\n");
  printf("%d\n", pop(List1));
  print_list(List1);
}
