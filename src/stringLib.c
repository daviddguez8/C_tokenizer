#include <stdio.h>

int count_words(const char * word) {
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
      //indicate that you are inside an already counted word
      onWord = 1;
    }
    
    //printf("Address: %x contains -> %c\n", currPtr, *currPtr);
  }
  return wordCt;
}

//returns a pointer to the start of a word in words (inclusive)
const char * word_start(const char * words){
  const char * currPtr = words;
  
  //the word passed may have spaces at the beginning
  //we want to get to the START of the word
  while(*currPtr == ' ' || *currPtr == '\t') {
    currPtr++;
  }
  return currPtr;
}

//return pointer to the end of a word (exclusive)
const char * word_end(const char * words){
  const char * currPtr;

  //it is not the end of a word until -> ' ' or '\t' or '\0'
  for(currPtr = words; *currPtr != '\0'; currPtr++){
    if(*currPtr == '\t' || *currPtr == ' ') {
      return currPtr;
    }
  }

  return currPtr;
}

//uncomment to start run tests
/*
int main() {
  const char* word = "Test word";
  int wordCt = count_words(word);
  printf("Returned: %d, expecting: 2\n", wordCt);
  
  const char * start_pointer = word_start(word);
  printf("Returned: %x, char: %c, expecting: %x, char: T\n", start_pointer, *start_pointer, word);

  const char * end_pointer = word_end(word);
  printf("Returned: %x, char: %c, expecting char: ' '\n", end_pointer, *end_pointer);

  const char * next_start = word_start(end_pointer);
  printf("Returned: %x, char: %c, expecting char: 'w'\n", next_start, *next_start);

  const char * next_end = word_end(next_start);
  printf("Returned: %x, char: %c, expecting char: ^@\n", next_end, *next_end);
  } */
