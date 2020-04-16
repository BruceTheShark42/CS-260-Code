/*
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 */

#include "RecordLabel.h"
#include <fstream>
#include "constants.h"



RecordLabel::RecordLabel() : head(new Node()) {
	readFromFile();
}



RecordLabel::~RecordLabel() {
	writeToFile();
	deleteRec(head);
}



void RecordLabel::deleteRec(Node *node) {
	if (node != nullptr) {
		deleteRec(node->next);
		delete node;
	}
}



bool RecordLabel::addArtist(const char *name, const char *topStory, const char *description) {
	Node *node = getNodeWithArtistName(name);
	if (node == nullptr) {
		appendNode(new Node(new Artist(name, topStory, description)));
		return true;
	}
	return false;
}



bool RecordLabel::addArtistSong(const char *name, const char *title, float length, int views, int likes) {
	Node *node = getNodeWithArtistName(name);
	return node != nullptr && node->artist->addSong(title, length, views, likes);
}



bool RecordLabel::setArtistSongViews(const char *name, const char *title, int views) {
	Node *node = getNodeWithArtistName(name);
	return node != nullptr && node->artist->setSongViews(title, views);
}



bool RecordLabel::setArtistSongLikes(const char *name, const char *title, int likes) {
	Node *node = getNodeWithArtistName(name);
	return node != nullptr && node->artist->setSongLikes(title, likes);
}



void RecordLabel::removeUnpopularSongs(int views) {
	for (Node *node = head->next; node != nullptr; node = node->next)
		node->artist->removeUnpopularSongs(views);
}



RecordLabel::Node::Node(Artist *artist, Node *next) : artist(artist), next(next) {}



RecordLabel::Node::Node(Node *prev, Artist *artist) : artist(artist), next(prev->next) {
	prev->next = this;
}



RecordLabel::Node::~Node() {
	delete artist;
}



void RecordLabel::appendNode(Node *node) {
	Node *prev = head;
	while (prev->next != nullptr)
		prev = prev->next;
	prev->next = node;
	// To ensure that this will be the end of the list
	node->next = nullptr;
}



RecordLabel::Node* RecordLabel::removeNode(Node *prev) {
	Node *removed = prev->next;
	prev->next = removed->next;
	return removed;
}



RecordLabel::Node* RecordLabel::getNodeWithArtistName(const char *name) const {
	Node *node = head->next;
	while (node != nullptr && !node->artist->hasName(name))
		node = node->next;
	return node;
}



bool RecordLabel::displayArtist(std::ostream &ostr, const char *name) const {
	Node *node = getNodeWithArtistName(name);
	if (node != nullptr) {
		ostr << *node->artist;
		return true;
	}
	return false;
}



std::ostream& operator<<(std::ostream &ostr, const RecordLabel &list) {
	if (list.head->next != nullptr)
		printRec(ostr, list.head->next);
	return ostr;
}



void printRec(std::ostream &ostr, RecordLabel::Node *node) {
	if (node != nullptr) {
		ostr << *node->artist;
		printRec(ostr, node->next);
	}
}



void RecordLabel::readFromFile() {
	std::ifstream file(FILE_NAME);
	if (file.is_open()) {
		char *name = new char[MAX_CHARS], *topStory = new char[MAX_CHARS], *description = new char[MAX_CHARS];
		char *title = new char[MAX_CHARS], *length = new char[MAX_CHARS], *views = new char[MAX_CHARS], *likes = new char[MAX_CHARS];
		while (!file.eof()) {
			char type = file.get();
			if (!file.eof()) {
				if (type == 'a') {
					file.getline(name, MAX_CHARS, DELIMETER);
					file.getline(topStory, MAX_CHARS, DELIMETER);
					file.getline(description, MAX_CHARS, DELIMETER);
					addArtist(name, topStory, description);
				} else {
					file.getline(title, MAX_CHARS, DELIMETER);
					file.getline(length, MAX_CHARS, DELIMETER);
					file.getline(views, MAX_CHARS, DELIMETER);
					file.getline(likes, MAX_CHARS, DELIMETER);
					addArtistSong(name, title, std::stof(length), std::stoi(views), std::stoi(likes));
				}
				file.get();
			}
		}
		file.close();
		// This would not be necessary if they could be statically allocated
		// Not to mention this way is slower to access (even if only by nanoseconds)
		// Please just let us use statically allocated arrays
		// It would make everything simpler to both write and grade
		delete[] name;
		delete[] topStory;
		delete[] description;
		delete[] title;
		delete[] length;
		delete[] views;
		delete[] likes;
	}
}



void RecordLabel::writeToFile() {
	std::ofstream file(FILE_NAME);
	if (file.is_open()) {
		for (Node *node = head->next; node != nullptr; node = node->next) 
			node->artist->toFileFormat(file);
		file.close();
	}
}
