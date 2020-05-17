main: main.o WebTable.o Website.o
	g++ -o main main.o WebTable.o Website.o

main.o: main.cpp WebTable.h Website.h
	g++ -c main.cpp

WebTable.o: WebTable.cpp WebTable.h Website.h
	g++ -c WebTable.cpp

Website.o: Website.cpp Website.h
	g++ -c Website.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm *.o main
