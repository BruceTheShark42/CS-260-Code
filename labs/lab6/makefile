main: main.o Table.o supplied.o
	g++ -o main main.o Table.o supplied.o

main.o: main.cpp Table.h
	g++ -c main.cpp

Table.o: Table.cpp Table.h
	g++ -c Table.cpp

run:
	./main

clean:
	rm main.o Table.o

clobber:
	rm main
