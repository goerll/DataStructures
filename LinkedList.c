#include <stdio.h>
#include <stdlib.h>

struct ListItem{
  // The value that the item will hold
  int value;
  // A pointer to the next item
  struct ListItem *next;
};

// Prints a ListItem and all the following items linked to it
// I.e.: "[1, 2, 3, 4, 5,]"
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
  *item = malloc(sizeof(int));
}

// Inserts item at the end of the list
void insertItemEnd(struct ListItem *item, int value){
  while(item->next != 0){
    item = item->next;
  }
  struct ListItem *NewItem = malloc(sizeof(int));
  NewItem->value = value;
  item->next = NewItem;
}

// Inserts item at the start and redefines the list head to point to the new item adress
// Receives the list's first item's memory adress as first argument (I.e.: &ListItem)
void insertItemStart(struct ListItem **item, int value){
  struct ListItem *NewItem = malloc(sizeof(int));
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
    if(item->value > max)
      max = item->value;
    item = item->next;
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
// Will return -1 if the index is out of range
int searchByIndex(struct ListItem *item, int index){
  for(int i = 0; i < index; i++){
    item = item->next;
    if(item->next == 0 && i != index){
      return -1;
    }
  }
  return item->value;
}

/*
int *searchByValue(struct ListItem *item, int value){
  int ocurrences = 0;
  int indexes[0];

  while(item->next != 0){
    if(item->value == value){
      
      indexes = int indexes[ocurrences]
    }
  }
}
*/
// Testing all this madness
int main(){
  printf("Tá rodando\n");

  struct ListItem *List1;
  initializeList(&List1);
  List1->value = 1;

  insertItemEnd(List1, 2);
  insertItemEnd(List1, 3);
  insertItemEnd(List1, 4);
  insertItemEnd(List1, 5);

  printList(List1);
  printf("Len: %d\n", lenOfList(List1));
  printf("Min: %d\n", listMin(List1));
  printf("Max: %d\n", listMax(List1));

  insertItemStart(&List1, 0);
  printList(List1);
  printf("%d\n", searchByIndex(List1, -2));
};
