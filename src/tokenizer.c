#include <stdio.h>


int space_char(char c){
  if (c == ' ' || c =='\t' || c == '\n'){
    return 1;
  }
  return 0;
}

int non_space_char(char c) {
  if (c == ' ' || c =='\t' || c == '\n'){
    return 0;
  }
  return 1;
}

int count_words(char * word) {
  const char * currPtr;
  int wordCt = 0;
  int multipleSpaceFlag = 1;
  int onWord = 0;
  for(currPtr=word; *currPtr != '\0'; currPtr++){
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
const char * word_start(char * words){
  printf("-----word_start with words: %s\n", words);
  const char * currPtr = words;
  
  //the word passed may have spaces at the beginning
  //we want to get to the START of the word
  while (space_char(*currPtr) == 1 && *currPtr != '\0') {
    printf("updating since it is a space_char\n");
    currPtr++;
  }
  printf("Returning pointer: %x, with value:  %c\n\n",
	 currPtr, *currPtr);
  return currPtr;
}


//returns pointer to the first space_character after first word in words
const char * word_end(char * words){
  printf("-----word_end with words: %s\n", words);
  const char * currPtr = word_start(words);
  printf("-----found word starts at %x with char: %c\n", currPtr, *currPtr);
  
  //it is not the end of a word until -> ' ' or '\t' or '\0'
  while (non_space_char(*currPtr) == 1 && *currPtr != '\0'){
    printf("Character is non_space, updating\n");
    ++currPtr;
  }
  printf("Word_end returning pointer: %x, with value:  %c\n\n",
	 currPtr, *currPtr);
  return currPtr;
}



//tests
int test_count_words(){
  printf("TESTING COUNT_WORDS()******************\n");
  char word[] = "   Test word";
  int wordCt = count_words(word);
  printf("Returned: %d, expecting: 2\n", wordCt);
  printf("End of test ****************************\n");
}

int test_word_start() {
  printf("TESTING word_start()*******************\n");
  char test1[] = "singleWord";
  char test2[] = "    space in front";
  char test3[] = "\ttab in front";
  char test4[] = "\t tab-space in front";
  char test5[] = "\nnew-line in front";

  const char* result1 = word_start(test1);
  const char* result2 = word_start(test2);
  const char* result3 = word_start(test3);
  const char* result4 = word_start(test4);
  const char* result5 = word_start(test5);

  printf("Test 1 returned address: %x, containing: %c, expecting: 's'\n", result1, *result1);
  printf("Test 2 returned address: %x, containing: %c, expecting: 's'\n", result2, *result2);
  printf("Test 3 returned address: %x, containing: %c, expecting: 't'\n", result3, *result3);
  printf("Test 4 returned address: %x, containing: %c, expecting: 't'\n", result4, *result4);
  printf("Test 5 returned address: %x, containing: %c, expecting: 'n'\n", result5, *result5);

  printf("end of test *************************************\n");
}

int test_word_end() {
  printf("TESTING word_end()*******************\n");
  char test1[] = "singleWord";
  char test2[] = "    space in front";
  char test3[] = "\ttab in front";
  char test4[] = "\t tab-space in front";
  char test5[] = "\nnew-line\n in front";
  char test6[] = "ends_on_newline\n";
  char test7[] = "ends_on_tab\t";
  char test8[] = "ends_on_space  ";

  const char* result1 = word_end(test1);
  const char* result2 = word_end(test2);
  const char* result3 = word_end(test3);
  const char* result4 = word_end(test4);
  const char* result5 = word_end(test5);
  const char* result6 = word_end(test6);
  const char* result7 = word_end(test7);
  const char* result8 = word_end(test8);
  
  printf("Test 1 returned address: %x, containing: '%c', expecting: '^0'\n", result1, *result1);
  printf("Test 2 returned address: %x, containing: '%c', expecting: ' '\n", result2, *result2);
  printf("Test 3 returned address: %x, containing: '%c', expecting: ' '\n", result3, *result3);
  printf("Test 4 returned address: %x, containing: '%c', expecting: ' '\n", result4, *result4);
  printf("Test 5 returned address: %x, containing: '%c', expecting: '\n'\n", result5, *result5);
  printf("Test 6 returned address: %x, containing: '%c', expecting: '\n'\n", result6, *result6);
  printf("Test 7 returned address: %x, containing: '%c', expecting: '\t'\n", result7, *result7);
  printf("Test 8 returned address: %x, containing: '%c', expecting: ' '\n", result8, *result8);
  printf("****end of test*******************\n");
}

/*
int main() {
  //test_count_words();
  //test_word_start();
  test_word_end();
  } 
*/
