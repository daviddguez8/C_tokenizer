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

* **count_words()**: This recieves a string of word(s) as input and returns the amount of 
words contained in the phrase.

* **word_start()**: This recieves a string of word(s) as input and returns a pointer to the 
start of the first word in the phrase (inclusive). 

* **word_end()**: This recieves a string of word(s) as input and returns a pointer to the 
end of the first word in the phrase (exclusive).

