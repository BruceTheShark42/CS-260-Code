main: main.o dlist.o supplied.o
	g++ -g -o main main.o dlist.o supplied.o

main.o: main.cpp dlist.h
	g++ -g -c main.cpp

dlist.o: dlist.cpp dlist.h
	g++ -g -c dlist.cpp

run:
	./main

clean:
	rm main main.o dlist.o
