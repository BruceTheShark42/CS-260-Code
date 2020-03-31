main: main.o RandomArray.o LinkedList.o
	g++ -o main main.o RandomArray.o LinkedList.o

main.o: main.cpp LinkedList.h
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

run:
	./main

clean:
	rm main.o LinkedList.o

clobber:
	rm main
