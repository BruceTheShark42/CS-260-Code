#include <iostream>
#include "RecordLabel.h"
#include "constants.h"

int main() {
	RecordLabel al;
	std::cout << al << '\n';
	al.addArtist("Bruce", "best story ever", "lazy");
	std::cout << al << '\n';
	al.addArtist("Bob", "great chef", "motivated");
	std::cout << al << '\n';
	al.addArtistSong("Bruce", "Hello there. General Kenobi.", 3.14f, 70, 29);
	std::cout << al << '\n';
	al.addArtistSong("Bruce", "Owono", 420.69f, 1, 3);
	std::cout << al << '\n';
	al.addArtistSong("Bob", "bawr rawr", 0.001f, 3452, 324);
	std::cout << al << '\n';
	al.addArtist("Bruce", "test", "");
	std::cout << al << '\n';
	al.addArtistSong("Bruce", "bieeeyyy!!!!!", 2.37f, 144, 30);
	std::cout << al << '\n';
	al.removeUnpopularSongs(30);
	std::cout << al << '\n';
	al.setArtistSongViews("Bruce", "nobody", 6);
	std::cout << al << '\n';
	al.setArtistSongViews("Bruce", "bieeeyyy!!!!!", 2);
	std::cout << al << '\n';
	al.removeUnpopularSongs(30);
	std::cout << al << '\n';
	al.setArtistSongViews("Bruce", "bieeeyyy!!!!!", 1);
	std::cout << al << '\n';
	al.setArtistSongViews("Bob", "bawr rawr", 1);
	std::cout << al << '\n';
	al.removeUnpopularSongs(30);
	std::cout << al << '\n';
	return 0;
}
