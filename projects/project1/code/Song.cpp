/*
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 */

#include "Song.h"
#include <cstring>
#include "constants.h"



Song::Song(const char *title, float length, int views, int likes) : length(length), views(views), likes(likes) {
	this->title = new char[std::strlen(title) + 1];
	std::strcpy(this->title, title);
}



Song::~Song() {
	delete[] title;
}



bool Song::hasTitle(const char *title) const {
	return std::strcmp(this->title, title) == 0;
}



int Song::getViews() const {
	return views;
}



void Song::setViews(int views) {
	this->views = views;
}



void Song::setLikes(int likes) {
	this->likes = likes;
}



std::ostream& operator<<(std::ostream &ostr, const Song &song) {
	return ostr << " --- Song:"
				<< "\n ---- Title: " << song.title
				<< "\n ---- Length: " << song.length
				<< "\n ---- Views: " << song.views
				<< "\n ---- Likes: " << song.likes << '\n';
}



void Song::toFileFormat(std::ofstream &file) const {
	file << 's' << title << DELIMETER << length << DELIMETER << views << DELIMETER << likes << DELIMETER << '\n';
}
