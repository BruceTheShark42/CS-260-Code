// Made by Bruce Cosgrove

#ifndef SONG_LIST
#define SONG_LIST
#include <ostream>
#include "Song.h"

class SongList {
public:
	SongList();
	~SongList();
	
	bool addSong(const char *title, const float &length, const unsigned int &views, const unsigned int &likes);
	bool removeUnpopularSongs(const char *title, const unsigned int &likes);
	bool setSongViews(const char *title, const unsigned int &views);
	bool setSongLikes(const char *title, const unsigned int &likes);
	friend std::ostream& operator<<(std::ostream& ostr, const SongList &list);
private:
	struct Node {
		Node(Song *song = nullptr, Node *next = nullptr);
		Node(Node *prev, Song *song = nullptr);
		~Node();
		Song *song;
		Node *next;
	} *head;
	
	void deleteRec(Node *node);
	void removeNode(Node *prev);
};

std::ostream& operator<<(std::ostream& ostr, const SongList &list);
#endif
