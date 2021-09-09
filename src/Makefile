ui.o: ui.c stringLib.h
	gcc -c ui.c

stringLib.o: stringLib.c stringLib.h
	gcc -c stringLib.c

ui: ui.o stringLib.o
	gcc -o ui ui.o stringLib.o
