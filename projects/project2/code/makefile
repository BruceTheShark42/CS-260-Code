main: main.o GroupQueue.o Group.o Customer.o CustomerStack.o util.o
	g++ -o main main.o GroupQueue.o Group.o Customer.o CustomerStack.o util.o

main.o: main.cpp GroupQueue.h CustomerStack.h
	g++ -c main.cpp

GroupQueue.o: GroupQueue.cpp GroupQueue.h Group.h
	g++ -c GroupQueue.cpp

Group.o: Group.cpp Group.h Customer.h util.h
	g++ -c Group.cpp

Customer.o: Customer.cpp Customer.h util.h
	g++ -c Customer.cpp

CustomerStack.o: CustomerStack.cpp CustomerStack.h Customer.h
	g++ -c CustomerStack.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm main *.o
