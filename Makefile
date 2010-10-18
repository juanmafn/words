CC=g++
FLAGS=-Wall -ansi -pendantic

words: words.cc heap.o
	$(CC) -o words words.cc heap.o estructuras.o $(FLAGS)

heap.o: heap.cc heap.h
	$(CC) -c heap.cc $(FLAGS)

estructuras.o: estructuras.cc estructuas.h
	$(CC) -c estructuras.cc $(FLAGS)
