#include <stdio.h>
#include <stdlib.h>

struct ListItem{
  int value;
  struct ListItem *next;
};

void printList(struct ListItem *item){
  while (item->next != 0){
    printf("Value = %d\n", item->value);
    printf("Next = %d (%p)\n", item->next->value, item->next);
    item = item->next;
  }
  printf("Value = %d\n", item->value);
  printf("Next = reached list end\n");
}

void initializeList(struct ListItem **item){
  *item = malloc(sizeof(int));
}

int main(){
  printf("Tá rodando\n");

  struct ListItem *item1;
  struct ListItem *item2;

  initializeList(&item1);

  item1->value = 1;
  item2->value = 2;

  item1->next = item2;
  item2->next = NULL;

  printList(item1);
};
