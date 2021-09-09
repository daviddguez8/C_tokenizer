#include <stdio.h>

int countWords(const char * word) {
  const char * currPtr;
  int wordCt = 0;
  int multipleSpaceFlag = 1;
  int onWord = 0;
  for(currPtr=word; *currPtr != '\0'; currPtr++){
    putchar(*currPtr);
    if(*currPtr == '\t' || *currPtr == ' '){
      onWord = 0;
    } else {  
      //if we just entered to this word, count it
      if(onWord == 0) {
	wordCt++;
      }
      onWord = 1;
    }
    
    printf("Address: %x contains -> %c\n", currPtr, *currPtr);
  }
  return wordCt;
}

int main() {
  const char* word = "Hello world";
  printf("Returned: %d\n", countWords(word));
  
   
}
