// Made by Bruce Cosgrove

#include "Song.h"
#include <cstring>

Song::Song(const char *title, const float &length, const unsigned int &views, const unsigned int &likes) : length(length), views(views), likes(likes) {
	this->title = new char[std::strlen(title) + 1];
	std::strcpy(this->title, title);
}

Song::~Song() {
	delete[] title;
}

const char* Song::getTitle() const {
	return title;
}

bool Song::hasTitle(const char *title) const {
	return std::strcmp(this->title, title) == 0;
}

float Song::getLength() const {
	return length;
}

unsigned int Song::getViews() const {
	return views;
}

void Song::setViews(const unsigned int &views) {
	this->views = views;
}

unsigned int Song::getLikes() const {
	return likes;
}

void Song::setLikes(const unsigned int &likes) {
	this->likes = likes;
}

std::ostream& operator<<(std::ostream &ostr, const Song &song) {
	return ostr << "\tSong Title: " << song.title
				<< "\n\tSong Length: " << song.length
				<< "\n\tSong Views: " << song.views
				<< "\n\tSong Likes: " << song.likes << '\n';
}
