#include "Artist.h"
#include <cstring>
#include "constants.h"

Artist::Artist(const char *name, const char *topStory, const char *description) {
	this->name = new char[std::strlen(name) + 1];
	std::strcpy(this->name, name);
	this->topStory = new char[std::strlen(topStory) + 1];
	std::strcpy(this->topStory, topStory);
	this->description = new char[std::strlen(description) + 1];
	std::strcpy(this->description, description);
}

Artist::~Artist() {
	delete[] name;
	delete[] topStory;
	delete[] description;
}

bool Artist::addSong(const char *title, float length, int views, int likes) {
	return songs.addSong(title, length, views, likes);
}

void Artist::removeUnpopularSongs(int views) {
	songs.removeUnpopularSongs(views);
}

bool Artist::setSongViews(const char *title, int views) {
	return songs.setSongViews(title, views);
}

bool Artist::setSongLikes(const char *title, int likes) {
	return songs.setSongLikes(title, likes);
}

bool Artist::hasName(const char *name) const {
	return std::strcmp(this->name, name) == 0;
}

std::ostream& operator<<(std::ostream &ostr, const Artist &artist) {
	return ostr << " - Artist:\n"
				<< " -- Name: " << artist.name
				<< "\n -- Top Story: " << artist.topStory
				<< "\n -- Description: " << artist.description
				<< "\n -- Songs:\n" << artist.songs;
}

void Artist::toFileFormat(std::ofstream &file) const {
	file << 'a' << name << DELIMETER << topStory << DELIMETER << description << DELIMETER << '\n';
	songs.toFileFormat(file);
}
