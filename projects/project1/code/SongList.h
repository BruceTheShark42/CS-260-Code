// Made by Bruce Cosgrove

#ifndef SONG_LIST
#define SONG_LIST
#include "Song.h"
#include <ostream>
#include <fstream>

class SongList {
public:
	SongList();
	~SongList();
	
	bool addSong(const char *title, float length, int views, int likes);
	void removeUnpopularSongs(int views);
	bool setSongViews(const char *title, int views);
	bool setSongLikes(const char *title, int likes);
	void toFileFormat(std::ofstream &file) const;
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
