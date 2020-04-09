#include "SongList.h"

SongList::SongList() : head(new Node()) {}

SongList::~SongList() {
	deleteRec(head);
}

void SongList::deleteRec(Node *node) {
	if (node != nullptr) {
		deleteRec(node->next);
		delete node;
	}
}

bool SongList::addSong(const char *title, const float &length, const unsigned int &views, const unsigned int &likes) {
	insertNodeInOrder(new Node(new Song(title, length, views, likes)));
}

bool SongList::removeUnpopularSongs(const unsigned int &likes) {
	Node *prev = head;
	while (prev->next != nullptr) {
		if (prev->next->song->getLikes() < likes)
			delete removeNode(prev);
		else
			prev = prev->next;
	}
}

bool SongList::setSongViews(const char *title, const unsigned int &views) {
	Node *node = head->next;
	while (node != nullptr) {
		Song *song = node->song;
		if (song->hasTitle(title)) {
			song->setViews(views);
			return true;
		}
		node = node->next;
	}
	return false;
}

bool SongList::setSongLikes(const char *title, const unsigned int &likes) {
	Node *prev = head;
	while (prev->next != nullptr) {
		Song *song = prev->next->song;
		if (song->hasTitle(title)) {
			song->setLikes(likes);
			// Remove the node from the list and put it in the correct place
			insertNodeInOrder(removeNode(prev));
			return true;
		}
		prev = prev->next;
	}
	return false;
}

void SongList::insertNodeInOrder(Node *node) {
	Node *prev = head;
	while (prev->next != nullptr && prev->next->song->getLikes() >= node->song->getLikes())
		prev = prev->next;
	node->next = prev->next;
	prev->next = node;
}

SongList::Node* SongList::removeNode(Node *prev) {
	Node *removed = prev->next;
	prev->next = removed->next;
	return removed;
}

SongList::Node::Node(Song *song, Node *next) : song(song), next(next) {}

SongList::Node::Node(Node *prev, Song *song) : song(song), next(prev->next) {
	prev->next = this;
}

SongList::Node::~Node() {
	delete song;
}

std::ostream& operator<<(std::ostream& ostr, const SongList &list) {
	if (list.head->next != nullptr)
		printRec(ostr, list.head->next);
	else
		ostr << "No songs available!\n";
	return ostr;
}

void printRec(std::ostream& ostr, SongList::Node *node) {
	if (node != nullptr) {
		ostr << "----------------------------\n" << *node->song;
		printRec(ostr, node->next);
	}
}
