# makefile
# 
# Bruce Cosgrove
# CS 260
# Assignment #1
# 
# Builds the program

# I know there are ways to automate this process
# Could you let me know some ways to do that?
# Thanks!

main: main.o RecordLabel.o Artist.o SongList.o Song.o
	g++ -o main main.o RecordLabel.o Artist.o SongList.o Song.o

main.o: main.cpp RecordLabel.h Artist.h SongList.h Song.h
	g++ -c main.cpp

RecordLabel.o: RecordLabel.cpp RecordLabel.h Artist.h SongList.h Song.h
	g++ -c RecordLabel.cpp

Artist.o: Artist.cpp Artist.h SongList.h Song.h
	g++ -c Artist.cpp

SongList.o: SongList.cpp SongList.h Song.h
	g++ -c SongList.cpp

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm *.o main
