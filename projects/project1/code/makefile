main: main.o SongList.o Song.o
	g++ -o main main.o SongList.o Song.o

main.o: main.cpp SongList.h Song.h
	g++ -c main.cpp

SongList.o: SongList.cpp SongList.h Song.h
	g++ -c SongList.cpp

Song.o: Song.cpp Song.h
	g++ -c Song.cpp

run:
	./main

memrun:
	valgrind ./main

clean:
	rm *.o

clobber:
	rm main
