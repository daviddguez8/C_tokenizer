ui.o: ui.c tokenizer.h
	gcc -c ui.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

ui: ui.o tokenizer.o
	gcc -o ui ui.o tokenizer.o
