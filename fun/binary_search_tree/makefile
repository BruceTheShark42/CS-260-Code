main: main.o Tree.o
	g++ -o main main.o Tree.o

main.o: main.cpp Tree.h
	g++ -c main.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm *.o

clobber:
	rm main
