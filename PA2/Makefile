%.o: %.c grids.h
	gcc -Wall -c -o $@ $< -I.

life: main.o grids.o 
	gcc -Wall -o life main.o grids.o -I.

.PHONY: clean

clean:
	rm main.o grids.o

