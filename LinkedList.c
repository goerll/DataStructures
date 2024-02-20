#include <stdio.h>
#include <stdlib.h>

struct ListItem{
  int value;
  struct ListItem *next;
};

void printList(struct ListItem *item){
  printf("[%d, ", item->value);
  item = item->next;
  while(item->next != 0){
    printf("%d, ", item->value);
    item = item->next;
  }
  printf("%d]\n", item->value);
}

void initializeList(struct ListItem **item){
  *item = malloc(sizeof(int));
}

void insertItemEnd(struct ListItem *item, int value){
  while(item->next != 0){
    item = item->next;
  }
  struct ListItem *NewItem = malloc(sizeof(int));
  NewItem->value = value;
  item->next = NewItem;
}

int lenOfList(struct ListItem *item){
  int i = 1;
  while(item->next != 0){
    i++;
    item = item->next;
  }
  return i;
}

int listMax(struct ListItem *item){
  int max = item->value;
  while(item->next != 0){
    if(item->value > max)
      max = item->value;
    item = item->next;
  }
  return max;
}

int listMin(struct ListItem *item){
  int min = item->value;
  while(item->next != 0){
    if(item->value < min)
      min = item->value;
    item = item->next;
  }
  return min;
}

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
};
