// Made by Bruce Cosgrove

#ifndef SONG_LIST
#define SONG_LIST
#include <ostream>
#include "Song.h"

class SongList {
public:
	SongList();
	~SongList();
	
	bool addSong(const char *title, const float &length, const int &views, const int &likes);
	bool removeUnpopularSongs(const int &likes);
	int getSongViews(const char *title) const;
	int getSongLikes(const char *title) const;
	bool setSongViews(const char *title, const int &views);
	bool setSongLikes(const char *title, const int &likes);
private:
	struct Node {
		Node(Song *song = nullptr, Node *next = nullptr);
		Node(Node *prev, Song *song = nullptr);
		~Node();
		Song *song;
		Node *next;
	} *head;
	
	void deleteRec(Node *node);
	void insertNodeInOrder(Node *node);
	Node* removeNode(Node *prev);
	Node* getNodeWithSongTitle(const char *title) const;
	
	friend std::ostream& operator<<(std::ostream &ostr, const SongList &list);
	friend void printRec(std::ostream &ostr, SongList::Node *node);
};

std::ostream& operator<<(std::ostream &ostr, const SongList &list);
void printRec(std::ostream &ostr, SongList::Node *node);
#endif
