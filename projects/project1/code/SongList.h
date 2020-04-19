/*
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 */

#ifndef SONG_LIST
#define SONG_LIST
#include "Song.h"
#include <ostream>
#include <fstream>

class SongList {
public:
	/*
	 * Constructs a new SongList
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	SongList();
	
	
	
	/*
	 * Destructs a SongList
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~SongList();
	
	
	
	/*
	 * Adds a song to this list
	 * 
	 * Inputs:
	 *  title - the song title
	 *  length - the song length
	 *  views - the number of views
	 *  likes - the number of likes
	 * 
	 * Outputs:
	 *  whether or not the song could be added
	 */
	bool addSong(const char *title, float length, int views, int likes);
	
	
	
	/*
	 * Removes all unpopular songs
	 * 
	 * Inputs:
	 *  views - the minimum number of views to be considered popular
	 * 
	 * Outputs:
	 *  none
	 */
	void removeUnpopularSongs(int views);
	
	
	
	/*
	 * Sets a song's views
	 * 
	 * Inputs:
	 *  title - the song title
	 *  views - the new number of views
	 * 
	 * Outputs:
	 *  whether or not the song's views could be set
	 */
	bool setSongViews(const char *title, int views);
	
	
	
	/*
	 * Sets a song's likes
	 * 
	 * Inputs:
	 *  title - the song title
	 *  likes - the new number of likes
	 * 
	 * Outputs:
	 *  whether or not the song's likes could be set
	 */
	bool setSongLikes(const char *title, int likes);
	
	
	
	/*
	 * Converts this SongList to my custom file format
	 * 
	 * Inputs:
	 *  file - the std::ofstream to write to
	 * 
	 * Outputs:
	 *  writes this SongList to the file
	 */
	void toFileFormat(std::ofstream &file) const;
private:
	struct Node {
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  song - the song to store
		 *  next - the next node
		 * 
		 * Outputs:
		 *  the new node
		 */
		Node(Song *song = nullptr, Node *next = nullptr);
		
		
		
		/*
		 * Constructs a new Node
		 * 
		 * Inputs:
		 *  prev - the prevuous node
		 *  song - the song to store
		 * 
		 * Outputs:
		 *  the new node
		 */
		Node(Node *prev, Song *song = nullptr);
		
		
		
		/*
		 * Destructs a Node
		 * 
		 * Inputs:
		 *  none
		 * 
		 * Outputs:
		 *  none
		 */
		~Node();
		
		
		
		Song *song;
		Node *next;
	} *head;
	
	
	
	/*
	 * Recursively deletes Nodes
	 * 
	 * Inputs:
	 *  node - the node to start deleting at
	 * 
	 * Outputs:
	 *  deletes each node in the list
	 */
	void deleteRec(Node *node);
	
	
	
	/*
	 * Inserts a node in the order of popularity
	 * 
	 * Inputs:
	 *  node - the node to insert
	 * 
	 * Outputs:
	 *  inserts the node in the correct place
	 */
	void insertNodeInOrder(Node *node);
	
	
	
	/*
	 * Removes a Node from this list
	 * 
	 * Inputs:
	 *  prev - the previous node
	 * 
	 * Outputs:
	 *  the removed Node
	 */
	Node* removeNode(Node *prev);
	
	
	
	/*
	 * Checks this list for any songs with the given title
	 * 
	 * Inputs:
	 *  title - the title to compare
	 * 
	 * Outputs:
	 *	the first node with the title
	 *	nullptr if no songs had the given title
	 */
	Node* getNodeWithSongTitle(const char *title) const;
	
	
	
	friend std::ostream& operator<<(std::ostream &ostr, const SongList &list);
	friend void printRec(std::ostream &ostr, SongList::Node *node);
};



/*
 * Prints a SongList
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  list - the list to print
 * 
 * Outputs:
 *  writes the list to ostr
 */
std::ostream& operator<<(std::ostream &ostr, const SongList &list);



/*
 * Recursively prints a SongList
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  node - the node to print
 * 
 * Outputs:
 *  writes the list to ostr
 */
void printRec(std::ostream &ostr, SongList::Node *node);
#endif
