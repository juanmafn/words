CC=g++
FLAGS=-Wall -ansi -pedantic

words: words.cc heap.o estructuras.o
	$(CC) -o words words.cc heap.o estructuras.o $(FLAGS)

heap.o: heap.cc heap.h
	$(CC) -c heap.cc $(FLAGS)

estructuras.o: estructuras.cc estructuras.h
	$(CC) -c estructuras.cc $(FLAGS)

clean:
	rm -f *.o words

