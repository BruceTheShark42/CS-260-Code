// Made by Bruce Cosgrove

#include "Song.h"
#include <cstring>

Song::Song(const char *title, const float &length, const int &views, const int &likes) : length(length), views(views), likes(likes) {
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

int Song::getViews() const {
	return views;
}

void Song::setViews(const int &views) {
	this->views = views;
}

int Song::getLikes() const {
	return likes;
}

void Song::setLikes(const int &likes) {
	this->likes = likes;
}

std::ostream& operator<<(std::ostream &ostr, const Song &song) {
	return ostr << " -- Song:"
				<< "\n --- Title: " << song.title
				<< "\n --- Length: " << song.length
				<< "\n --- Views: " << song.views
				<< "\n --- Likes: " << song.likes
				<< "\n\n";
}
