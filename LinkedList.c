#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

struct ListItem{
  // The value that the item will hold
  int value;
  // A pointer to the next item
  struct ListItem *next;
};

// Prints a ListItem and all the following items linked to it
// I.e.: "[1, 2, 3, 4, 5]"
void printList(struct ListItem *item){
  printf("[%d, ", item->value);
  item = item->next;
  while(item->next != 0){
    printf("%d, ", item->value);
    item = item->next;
  }
  printf("%d]\n", item->value);
}

// Allocates a memory adress to the first ListItem
void initializeList(struct ListItem **item){
  *item = malloc(sizeof(struct ListItem));
  (*item)->value = 0;
  (*item)->next = NULL;
}

// Inserts item at the end of the list
void insertItemEnd(struct ListItem *item, int value){
  while(item->next != 0){
    item = item->next;
  }
  struct ListItem *NewItem = malloc(sizeof(struct ListItem));
  NewItem->value = value;
  NewItem->next = NULL;
  item->next = NewItem;
}

// Inserts item at the start and redefines the list head to point to the new item adress
// Receives the list's first item's memory adress as first argument (I.e.: &ListItem)
void insertItemStart(struct ListItem **item, int value){
  struct ListItem *NewItem = malloc(sizeof(struct ListItem));
  NewItem->value = value;
  NewItem->next = *item;
  *item = NewItem;
}

// Returns the length of the list
int lenOfList(struct ListItem *item){
  int i = 1;
  while(item->next != 0){
    i++;
    item = item->next;
  }
  return i;
}

// Returns the highest number on the list
int listMax(struct ListItem *item){
  int max = item->value;
  while(item->next != 0){
    item = item->next;
    if(item->value > max)
      max = item->value;
  }

  return max;
}

// Returns the lowest number on the list
int listMin(struct ListItem *item){
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
int searchByIndex(struct ListItem *item, int index){
  if(index < 0){
    index = lenOfList(item) + index;
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
int searchByValue(struct ListItem *item, int value){
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
void destroyList(struct ListItem **list){
  struct ListItem *next = (*list)->next;
  while(next != 0){
    free(*list);
    *list = next;
    next = next->next;
  }
}

// Removes the last element of the list and returns it's value
int listPop(struct ListItem *list){
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

  struct ListItem *List1;
  initializeList(&List1);
  List1->value = 1;

  insertItemEnd(List1, 3);
  insertItemEnd(List1, 3);
  insertItemStart(&List1, 4);
  insertItemEnd(List1, 5);
  insertItemEnd(List1, 5);
  insertItemEnd(List1, 10);

  printList(List1);
  printf("Len: %d\n", lenOfList(List1));
  printf("Min: %d\n", listMin(List1));
  printf("Max: %d\n", listMax(List1));

  insertItemStart(&List1, 0);
  printList(List1);
  printf("%d\n", searchByIndex(List1, -2));
  printf("%d\n", searchByValue(List1, 3));
  printf("d\n");
  printf("%d\n", listPop(List1));
  printList(List1);
}
