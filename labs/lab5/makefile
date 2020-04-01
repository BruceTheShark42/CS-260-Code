main: main.o CList.o supplied.o
	g++ -o main main.o CList.o supplied.o

main.o: main.cpp CList.h
	g++ -c main.cpp

CList.o: CList.cpp CList.h
	g++ -c CList.cpp

run:
	./main

clean:
	rm main.o CList.o

clobber:
	rm main
