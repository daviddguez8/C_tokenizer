#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_SIZE 100

void freeInputBuffer() {
  char current = getchar();
  while(current != '\n') {
    current = getchar();
  }
}

char* getInput() {
  printf("Enter input: ");
  
  char* input = malloc(MAX_SIZE+1);
  int i_input = 0;
  int current = getchar();
  
  while (current != '\n' && i_input < MAX_SIZE-1) {
    input[i_input] = current;
    ++i_input;
    current = getchar();
  }

  input[i_input] = '\0';
  //printf("Final input string: %s \n", input);
  return input;
}

char* ui() {
  List* history = init_history();
  
  printf("-----------------------------------------------\n");
  printf("--------------The tokenizer v0.1---------------\n");
  printf("-----------------------------------------------\n");
  printf("-Enter :3 to display history and select input--\n");
  printf("-Enter exit to exit the program----------------\n");
  printf("-----------------------------------------------\n\n\n");

  char* input = getInput();
  int newWord;
  while(strcmp(input, "exit") == 0) {
    newWord = 1;
    //if the input was \3, display history and allow user to select input from there
    if(strcmp(input, ":3") == 1) {
      print_history(history);
      printf("Select an id number from the previous list to select that input: ");
      int selection;
      scanf("%d", &selection);
      printf("Selected %d\n", selection);
      newWord = 0;
      input = get_history(history, selection);
      freeInputBuffer(); 
    }

    char ** tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);
    if(newWord == 1) {
      add_history(history, input);
    }
    input = getInput();
  }  
}

int main() {
  
  char * user_input = ui();
  
  char ** input_tokenized = tokenize(user_input);
  printf("TOKENIZED user input on address: %x, contains: ", *input_tokenized);
  print_tokens(input_tokenized);
}
