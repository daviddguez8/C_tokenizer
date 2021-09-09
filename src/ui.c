#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

const char* ui() {
  printf("CHange to test github, with another change\n");
  printf("------------------------\n");
  printf("---The tokenizer v0.1---\n");
  printf("------------------------\n");

  printf("Enter input to be tokenized: ");
  
  char* input = malloc(MAX_SIZE+1);
  int i_input = 0;
  int current = getchar();
  
  while (current != '\n' && i_input < MAX_SIZE) {
    input[i_input] = current;
    ++i_input;
    printf("Putting character %c with %d int value into input string: %s \n", current, current, input);
    current = getchar();
  }

  printf("Final input string: %s \n", input);
  return input;
  
}

int main() {
  const char * user_input = ui();
  printf("%s was what the user entered, size of string: %d\n", user_input, sizeof(user_input));
  int size=0;
  const char* input_copy;
  
  for(input_copy = user_input; *input_copy!='\0'; input_copy++){
    size++;
    printf("Address: %x\n", input_copy);
    printf("Value: %c\n", *input_copy);
    
  }
  printf("%s is what just got copied, true size is: %d\n", input_copy, size);
  
}
