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

bool SongList::addSong(const char *title, float length, int views, int likes) {
	Node *node = getNodeWithSongTitle(title);
	if (node == nullptr) {
		insertNodeInOrder(new Node(new Song(title, length, views, likes)));
		return true;
	}
	return false;
}

void SongList::removeUnpopularSongs(int views) {
	Node *prev = head;
	while (prev->next != nullptr) {
		if (prev->next->song->getViews() < views)
			delete removeNode(prev);
		else
			prev = prev->next;
	}
}

SongList::Node* SongList::getNodeWithSongTitle(const char *title) const {
	Node *node = head->next;
	while (node != nullptr) {
		if (node->song->hasTitle(title))
			return node;
		node = node->next;
	}
	return nullptr;
}

int SongList::getSongViews(const char *title) const {
	Node *node = getNodeWithSongTitle(title);
	if (node != nullptr)
		return node->song->getViews();
	return -1;
}

bool SongList::setSongViews(const char *title, int views) {
	// Can't use getNodeWithSongTitle(title) because the previous node is needed
	Node *prev = head;
	while (prev->next != nullptr) {
		if (prev->next->song->hasTitle(title)) {
			prev->next->song->setViews(views);
			// Remove the node from the list and put it in the correct place
			insertNodeInOrder(removeNode(prev));
			return true;
		}
		prev = prev->next;
	}
	return false;
}

int SongList::getSongLikes(const char *title) const {
	Node *node = getNodeWithSongTitle(title);
	if (node != nullptr)
		return node->song->getLikes();
	return -1;
}

bool SongList::setSongLikes(const char *title, int likes) {
	Node *node = getNodeWithSongTitle(title);
	if (node != nullptr) {
		node->song->setLikes(likes);
		return true;
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
	return ostr;
}

void printRec(std::ostream& ostr, SongList::Node *node) {
	if (node != nullptr) {
		ostr << *node->song;
		printRec(ostr, node->next);
	}
}

void SongList::toFileFormat(std::ofstream &file) const {
	for (Node *node = head->next; node != nullptr; node = node->next)
		node->song->toFileFormat(file);
}
