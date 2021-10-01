ui.o: ui.c tokenizer.h
	gcc -c ui.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

ui: ui.o tokenizer.o history.o
	gcc -o ui ui.o tokenizer.o history.o
