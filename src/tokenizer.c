#include <stdio.h>
#include <stdlib.h>

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
      //indicates that we are inside an already counted word
      onWord = 1;
    }
  }
  
  return wordCt;
}

//returns a pointer to the start of a word in words (inclusive)
char * word_start(char * words){
  char * currPtr = words;
  
  //the word passed may have spaces at the beginning
  //we want to get to the START of the word
  while (space_char(*currPtr) == 1 && *currPtr != '\0') {
    currPtr++;
  }
  
  return currPtr;
}


//returns pointer to the first space_character after first word in words
char * word_end(char * words){
  //just to be sure that this points to the start of a word
  char * currPtr = word_start(words);
   
  //it is not the end of a word until -> ' ' or '\t' or '\0'
  while (non_space_char(*currPtr) == 1 && *currPtr != '\0'){
    ++currPtr;
  }
  return currPtr;
}

char * copy_str(char *str, short len){
  char* retStr = malloc(len+1);
  char* retIdx = retStr;
  char* strPtr = str;
  
  while(len>0 && *strPtr!='\0') {
    *retIdx = *strPtr;
    retIdx++;
    strPtr++;
    len--;
  }

  *retIdx = '\0';
  return retStr;
}

char ** tokenize(char* words){
  int wordCt = count_words(words);
  char ** tokens = malloc(sizeof(char*) * (wordCt+1));
  char ** currToken = tokens;
  
  //for each word in words we want to:
  // 1. Get the next pointer to the start of a word
  // 2. Get the pointer to the end of that word
  // 3. Get the length by subtracting pointers
  // 4. Call copy string with that start and length
  // 5. Store the returned allocated word in tokens
  while (wordCt > 0) {
    char * startPtr = word_start(words);
    char * endPtr = word_end(words);
    int length = endPtr - startPtr;
    
    char * allocatedStr = copy_str(startPtr, length);
    *currToken = allocatedStr;
    //printf("String starts on %x and is %s\n", allocatedStr, allocatedStr);
    //printf("CurrToken contains ptr address %x, pointing to string starting on %x, str: %s\n",
    //currToken, *currToken, *currToken);

    words = endPtr;
    ++currToken;
    --wordCt;
  }
  *currToken = NULL;
  
  return tokens;
}

void print_tokens(char** tokens){
  char **curr = tokens;
  
  while(*curr != NULL) {
    printf("Word allocated at : %x: \"%s\"\n", *curr, *curr);
    ++curr;
  }
  printf("\n");
}

char* get_token(char** tokens, int id) {
  char** curr = tokens;
  while (id > 0 && *curr != NULL){
    curr++;
    id--;
  }
  return *curr;
}

void free_tokens(char** tokens) {
  char** curr = tokens;

  while(*curr != 0) {
    printf("Freeing word \"%s\"\n", *curr);
    free(*curr);
    curr++;
  }
  free(tokens);
  printf("\n\n");
}

//returns 1 if str1 == str2
int strequals(char* str1, char* str2) {
  if(str1 == str2) { return 1; }
  
  int flag = 1;
  while(*str1 != '\0' || *str2 != '\0') {
    
    if(*str1 != *str2) {
      flag = 0;
      break;
    }
    str1++;
    str2++;
  }
  return flag;
}


//tests
/* 
void test_space_char(){
  printf("TESTING SPACE_CHAR()******************\n");
  char space = ' ';
  char new_line = '\n';
  char tab = '\t';
  char c = 'c';

  printf("Returned %d, expecting 1\n", space_char(space));
  printf("Returned %d, expecting 1\n", space_char(new_line));
  printf("Returned %d, expecting 1\n", space_char(tab));
  printf("Returned %d, expecting 0\n", space_char(c));
  printf("End of test ****************************\n");
}

void test_non_space_char(){
  printf("TESTING SPACE_CHAR()******************\n");
  char space = ' ';
  char new_line = '\n';
  char tab = '\t';
  char c = 'c';

  printf("Returned %d, expecting 0\n", non_space_char(space));
  printf("Returned %d, expecting 0\n", non_space_char(new_line));
  printf("Returned %d, expecting 0\n", non_space_char(tab));
  printf("Returned %d, expecting 1\n", non_space_char(c));
  printf("End of test ****************************\n");
}

void test_count_words(){
  printf("TESTING COUNT_WORDS()******************\n");
  char word[] = "   Test word";
  int wordCt = count_words(word);
  printf("Returned: %d, expecting: 2\n", wordCt);
  printf("End of test ****************************\n");
}

void test_word_start() {
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

void test_word_end() {
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
  printf("Test 7 returned address: %x, containing: '%c', expecting: '<tab>'\n", result7, *result7);
  printf("Test 8 returned address: %x, containing: '%c', expecting: ' '\n", result8, *result8);
  printf("****end of test*******************\n");
}

void test_copy_str() {
  char str1[] = {'t','e','s','t','i','n','g','\0'};
  
  char* result1 = copy_str(str1, 0); //copying 0 elements from str
  char* result2 = copy_str(str1, 2); //copying a generic amount of chars
  char* result3 = copy_str(str1, 8); //copying more than the elements in str
  
  printf("Test 1 returned: %s, with address %x,\n  expecting: '^0 or null' and different address %x\n",
	 result1, result1, &str1);
  
  printf("Test 2 returned: %s, with address %x,\n  expecting: 'te' and different address %x\n",
	 result2, result2, &str1);

  printf("Test 3 returned: %s, with address %x,\n  expecting: %s and different address %x\n",
	 result3, result3, str1, &str1);
	 
}

void test_tokenize() {
  printf("TEST1\n");
  char* words = "Hello world";
  char** tokens = tokenize(words);
  char ** currToken = tokens;
  printf("Print tokens: ");
  print_tokens(tokens);
  
  printf("%s, expecting to be Hello\n", *currToken);
  ++currToken;
  printf("%s, expecting to be world\n", *currToken);
  ++currToken;
  printf("%s, expecting to be (null)\n", *currToken);
  print_tokens(tokens);
  printf("TEST2\n");
  //test2
  char* words2 = "   single";
  char ** tokens2 = tokenize(words2);
  currToken = tokens2;
  
  printf("Print tokens: ");
  print_tokens(tokens2);

  printf("%s, expecting to be single\n", *currToken);
  ++currToken;
  printf("%s, expecting to be (null)\n", *currToken);
  
}

void test_free_token(){

}

void test_get_token(){
  char* words = "Hello world 123";
  char** tokens = tokenize(words);

  printf("tokens[0] is %s, expecting Hello\n", get_token(tokens, 0));
  printf("tokens[1] is %s, expecting world\n", get_token(tokens, 1));
  printf("tokens[2] is %s, expecting 123\n", get_token(tokens, 2));
}


void test_strcmp() {
  char* str1 = "Hello";
  char* str_1 = "Hello";
  char* str2 = "Hello world";
  char* str3 = "Hello world";
  char* str4 = "Hello\t world";
  char* str5 = "";
  char* str6 = "";

  printf("Test 1: 'Hello' with 'Hello', expecting: 1, result: %d\n", strequals(str1, "Hello")); 
  printf("Test 2: 'Hello' with 'Hello world', expecting: 0, result: %d\n", strequals(str1, "Hello world"));
  printf("Test 3: 'Hello world' with 'Hello world', expecting: 1, result: %d\n", strequals(str2, str3));
  printf("Test 4: '' with '', expecting: 1, result: %d\n", strequals(str5, str6));
  printf("Test 5: '' with 'Hello', expecting: 0, result: %d\n", strequals(str5, str1));
  printf("Test 6: 'Hello world' with 'Hello\t world', expecting: 0, result: %d\n", strequals(str2, str4));
}


int main() {
  //printf("main/n");
  //test_count_words();
  test_word_start();
  //test_word_end();
  //test_space_char();
  //test_non_space_char();
  //test_copy_str();
  //test_tokenize();
  //test_get_token();
  //test_strcmp();
  } */

