#include <iostream>
#include "SongList.h"

int main() {
	SongList sl;
	std::cout << sl << '\n';
	sl.addSong("Hello there. General Kenobi.", 3.14f, 70, 29);
	std::cout << sl << '\n';
	sl.addSong("Owono", 420.69f, 1, 3);
	std::cout << sl << '\n';
	sl.addSong("bawr rawr", 0.001f, 3452, 324);
	std::cout << sl << '\n';
	sl.addSong("bieeeyyy!!!!!", 2.37f, 144, 30);
	std::cout << sl << '\n';
	sl.removeUnpopularSongs(30);
	std::cout << sl << '\n';
	sl.setSongViews("nobody", 6);
	std::cout << sl << '\n';
	sl.setSongViews("bieeeyyy!!!!!", 2);
	std::cout << sl << '\n';
	sl.removeUnpopularSongs(30);
	std::cout << sl << '\n';
	sl.setSongLikes("bieeeyyy!!!!!", 1);
	std::cout << sl << '\n';
	sl.removeUnpopularSongs(30);
	std::cout << sl << '\n';
	return 0;
}
