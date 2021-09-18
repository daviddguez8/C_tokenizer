#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX_SIZE 100

char* ui() {
  printf("------------------------\n");
  printf("---The tokenizer v0.1---\n");
  printf("------------------------\n");

  printf("Enter input to be tokenized: ");
  
  char* input = malloc(MAX_SIZE+1);
  int i_input = 0;
  int current = getchar();
  
  while (current != '\n' && i_input < MAX_SIZE-1) {
    input[i_input] = current;
    ++i_input;
    //printf("Putting character %c with %d int value into input string: %s \n", current, current, input);
    current = getchar();
  }

  input[i_input] = '\0';
  //printf("Final input string: %s \n", input);
  return input;
}

int main() {
  char * user_input = ui();

  char ** input_tokenized = tokenize(user_input);

  printf("TOKENIZED user input on address: %x, contains: ", *input_tokenized);
  print_tokens(input_tokenized);
}
