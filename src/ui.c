include <stdio.h>

#define MAX_INPUT 100

const char* ui() {
  printf("CHange to test github\n");
  printf("------------------------\n");
  printf("---The tokenizer v0.1---\n");
  printf("------------------------\n");

  printf("Enter input to be tokenized: ");
  
  char input[100];
  int i_input = 0;
  int current = getchar();
  
  while (current != '\n' && i_input < MAX_INPUT) {
    input[i_input] = current;
    ++i_input;
    printf("Putting character %c with %d int value into input string: %s \n", current, current, input);
    current = getchar();
  }

  printf("Final input string: %s \n", input);
  return input
}

int main() {
  
  printf("%s was what the user entered\n", ui());
  
  
}
