#include "SongList.h"

SongList::SongList() : head(new Node()) {}

SongList::~SongList() {
	deleteRec(head);
}

void deleteRec(Node *node) {
	if (node != nullptr) {
		deleteRec(node->next);
		delete node;
	}
}

bool SongList::addSong(const char *title, const float &length, const unsigned int &views, const unsigned int &likes);

bool SongList::removeUnpopularSongs(const char *title, const unsigned int &likes);

void SongList::removeNode(Node *prev) {
	Node *toDelete = prev->next;
	prev->next = toDelete->next;
	delete toDelete;
}

bool SongList::setSongViews(const char *title, const unsigned int &views) {
	Node *node = head->next;
	while (node != nullptr) {
		Song *song = node->song;
		if (song->hasTitle(title)) {
			song->setViews(views);
			return true;
		}
	}
	return false;
}

bool SongList::setSongLikes(const char *title, const unsigned int &likes)
	Node *node = head->next;
	while (node != nullptr) {
		Song *song = node->song;
		if (song->hasTitle(title)) {
			song->setLikes(likes);
			// TODO: put this song in a different place
			// Make a helper function to add a node that
			// both this function an addSong use
			// addSong will just construct a Song object
			// and use the addNode function, while this 
			// function will use the song already present
			// as the argument for addNode.
			// addNode should be renamed though.
			return true;
		}
	}
	return false;
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

void printRec(std::osrream& ostr, SongList::Node *node) {
	if (node != nullptr) {
		ostr << "----------------------------" << node->song;
		printRec(ostr, node->next);
	}
}
