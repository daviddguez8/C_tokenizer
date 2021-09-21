#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  List* newList = malloc(sizeof(List));  
  return newList;
}

void add_history(List* list, char*str) {
  //list is empty
  if(list->root == 0) {
    list->root = malloc(sizeof(Item));
    list->root->id = 0;
    list->root->str = str;
    return;
  }
  
  int count = 1;
  Item* currItem = list->root;
    
  while(currItem->next != 0) {
    currItem = currItem->next;
    ++count;
  }

  //allocate memory for this new node
  currItem->next = malloc(sizeof(Item));
  currItem = currItem->next;
  //initialize attributes
  currItem->id = count;
  currItem->str = str; 
}

char* get_history(List* list, int id) {
  Item* currItem = list->root;
  
  while(currItem != 0) {
    if(currItem->id == id) {
      return currItem->str;
    }
    currItem = currItem->next;
  }
  printf("Id not found\n");
  return 0;
}

void print_history(List* list) {
  Item* currItem = list->root;
  int count = 0;
  
  while(currItem != 0) {
    printf("Item %d: %s\n", currItem->id, currItem->str);
    currItem = currItem->next;
  }
}

void free_items(Item* item) {
  if(item->next != 0) {
    free_items(item->next);
  }
  printf("Freeing item: %s on address %x\n", item->str, item);
  free(item);
}

void free_history(List* list) {
  if(list->root != 0) {
    free_items(list->root);
  }
  free(list);
}



int main() {
  List* list = init_history();
  
  char* s = "Hello";
  add_history(list, s);
  print_history(list);

  char*s2 = "world";
  add_history(list, s2);
  print_history(list);

  printf("%s, expecting Hello\n", get_history(list, 0));
  printf("%s, expecting world\n", get_history(list, 1));
  printf("%s, expecting (null)\n", get_history(list,2));

  free_history(list);
  printf("%x, not freed\n", list);
  printf("%x, freed?\n", list);
  
}
