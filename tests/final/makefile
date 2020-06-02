main: main.o supplied.o table.o
	g++ -o main main.o supplied.o table.o

main.o: main.cpp table.h
	g++ -c main.cpp

table.o: table.cpp table.h
	g++ -c table.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm main.o table.o main
