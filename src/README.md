Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).


## ui.c
 
Is where all the interaction will take place. This is will act as the only point of 
communication with the user. Here the user will enter the desired phrase, and receive the 
history and tokenized words. 

### Dependecies

* stringLib.c
* TODO

## tokenizer.c

Contains useful string manipulation functions. Such as count_words(), word_start()...

### Functions:

* **space_char(char c)**: Returns 1 if c is a space char (' ', '\t', '\n'). 0 otherwise.

* **non_space_char(char c)**: Returns 1 if c is not a space char (' ', '\t', '\n'). 0 otherwise.

* **count_words(char* words)**: This recieves a string of word(s) as input and returns the amount of 
words contained in the phrase.

* **word_start(char* words)**: This recieves a string of word(s) as input and returns a pointer to the 
start of the first word in the phrase (inclusive). 

* **word_end(char\* words)**: This recieves a string of word(s) as input and returns a pointer to the 
end of the first word in the phrase (exclusive).

* **tokenize(char\* words)**: Recieves a string as input, and extract each word in the string, allocates memory and saved the pointer to that new string. Returns a double pointer pointing to the first word in words. 

* **print_tokens(char\*\* tokens)**: Recieves a tokenized sequence of strings and prints each string along with its memory address.

* **get_token(char\*\* tokens, int id)**: Recieves a tokenized sequence of strings and returns the pointer to the string at position id.

* **free_tokens(char\*\* tokens)**: Recieves a tokenized sequence of strings and frees every memory allocated for these tokens. 

* **strcmp(char\* str1, char\* str2)**: Compares str1 and str2 and returns 1 if they are equal. 0 otherwise.


## history.c

Responsible for keeping track of the inputs entered by the user. Using a linked lists, stores tokenized strings in history

* **init_history()**:
Initializes and allocates memory for a list

* **add_history(List\* list, char\* str)**: 
Given a string str, it traverses the list and adds str to the end of the list, it handles allocation for each item.


* **get_history(List\* list, int id)**:
Given an int id, traverses the list and returns the content of the item at position id. It returns and empty string len(list) -1 < id.

* **print_history(List\* list)**:
Given a list, prints all the elements in the list in a nice readable format.

* **free_items(Item\* item)**:
It frees item and all the following items after it.

* **free_history(Item\* list)**:
Given a history list, it frees the memory allocated for each item in the list and also for the list itself.
