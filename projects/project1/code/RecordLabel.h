#ifndef RECORD_LABEL_H
#define RECORD_LABEL_H
#include "Artist.h"

class RecordLabel {
public:
	RecordLabel();
	~RecordLabel();
	
	bool addArtist(const char *name, const char *topStory, const char *description);
	bool addArtistSong(const char *name, const char *title, float length, int views, int likes);
	bool setArtistSongViews(const char *name, const char *title, int views);
	bool setArtistSongLikes(const char *name, const char *title, int likes);
	void removeUnpopularSongs(int views);
	bool displayArtist(std::ostream &ostr, const char *name) const;
private:
	struct Node {
		Node(Artist *artist = nullptr, Node *next = nullptr);
		Node(Node *prev, Artist *artist = nullptr);
		~Node();
		Artist *artist;
		Node *next;
	} *head;
	
	void deleteRec(Node *node);
	void appendNode(Node *node);
	Node* removeNode(Node *prev);
	Node* getNodeWithArtistName(const char *name) const;
	friend std::ostream& operator<<(std::ostream &ostr, const RecordLabel &list);
	friend void printRec(std::ostream &ostr, RecordLabel::Node *node);
	
	static constexpr const char *FILE_NAME = "labels.data";
	void readFromFile();
	void writeToFile();
};
std::ostream& operator<<(std::ostream &ostr, const RecordLabel &list);
void printRec(std::ostream &ostr, RecordLabel::Node *node);
#endif
