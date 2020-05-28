main: main.o WebTree.o Website.o
	g++ -o main main.o WebTree.o Website.o

main.o: main.cpp WebTree.h Website.h
	g++ -c main.cpp

WebTree.o: WebTree.cpp WebTree.h Website.h
	g++ -c WebTree.cpp

Website.o: Website.cpp Website.h
	g++ -c Website.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm *.o main
