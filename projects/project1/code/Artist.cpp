#include "Artist.h"
#include <cstring>

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

bool Artist::addSong(const char *title, const float &length, const int &views, const int &likes) {
	return songs.addSong(title, length, views, likes);
}

int Artist::getSongViews(const char *title) const {
	return songs.getSongViews(title);
}

int Artist::getSongLikes(const char *title) const {
	return songs.getSongLikes(title);
}

bool Artist::setSongViews(const char *title, const int &views) {
	return songs.setSongViews(title, views);
}

bool Artist::setSongLikes(const char *title, const int &likes) {
	return songs.setSongLikes(title, likes);
}

std::ostream& operator<<(std::ostream &ostr, const Artist &artist) {
	return ostr << " - Artist:\n"
				<< " -- Name: " << name
				<< "\n -- Top Story: " << topStory
				<< "\n -- Description: " << description
				<< "\n -- Songs:\n" << songs;
}
