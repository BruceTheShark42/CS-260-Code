/*
 * RecordLabel.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 * 
 * The main ADT that stores a list of Artists
 */

#ifndef RECORD_LABEL_H
#define RECORD_LABEL_H
#include "Artist.h"

class RecordLabel {
public:
	/*
	 * Constructs a new RecordLabel
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	RecordLabel();
	
	
	
	/*
	 * Destructs this RecordLabel
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~RecordLabel();
	
	
	
	/*
	 * Adds an artist to this record label
	 * 
	 * Inputs:
	 *  name - the artist's name
	 *  topStory - the artist's top story
	 *  description - the artist's description
	 * 
	 * Outputs:
	 *  whether or not the artist could be added
	 */
	bool addArtist(const char *name, const char *topStory, const char *description);
	
	
	
	/*
	 * Adds a song to the artist
	 * 
	 * Inputs:
	 *  name - the artist's name
	 *  title - the title of the song
	 *  topStory - the artist's top story
	 *  description - the artist's description
	 * 
	 * Outputs:
	 *  whether or not the song could be added to the artist's songs
	 */
	bool addArtistSong(const char *name, const char *title, float length, int views, int likes);
	
	
	
	/*
	 * Sets an artist's song's views
	 * 
	 * Inputs:
	 *  name - the artist's name
	 *  title - the song title
	 *  views - the number of likes
	 * 
	 * Outputs:
	 *  whether or not the artist could be added
	 */
	bool setArtistSongViews(const char *name, const char *title, int views);
	
	
	
	/*
	 * Sets an artist's song's views
	 * 
	 * Inputs:
	 *  name - the artist's name
	 *  title - the song title
	 *  likes - the number of likes
	 * 
	 * Outputs:
	 *  whether or not the song's likes could be set
	 */
	bool setArtistSongLikes(const char *name, const char *title, int likes);
	
	
	
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
	 * Displays an artist
	 * 
	 * Inputs:
	 *  ostr - the std::ostream to write to
	 *  name - the name of the artist to display
	 * 
	 * Outputs:
	 *  whether or not the artist exists
	 */
	bool displayArtist(std::ostream &ostr, const char *name) const;
private:
	struct Node {
		/*
		 * Constructs a new node
		 * 
		 * Inputs:
		 *  artist - the artist to store
		 *  next - the next node
		 * 
		 * Outputs:
		 *  none
		 */
		Node(Artist *artist = nullptr, Node *next = nullptr);
		
		
		
		/*
		 * Constructs a new node
		 * 
		 * Inputs:
		 *  prev - the previous node
		 *  artist - the artist to store
		 * 
		 * Outputs:
		 *  none
		 */
		Node(Node *prev, Artist *artist = nullptr);
		
		
		
		/*
		 * Destructs a node
		 * 
		 * Inputs:
		 *  none
		 * 
		 * Outputs:
		 *  none
		 */
		~Node();
		
		
		
		// Stores the Artist data
		Artist *artist;
		// Stores the next Node
		Node *next;
	} *head; // Stores a dummy node to the front of the list
	
	
	
	/*
	 * Recursively deletes the nodes
	 * 
	 * Inputs:
	 *  node - the node to delete
	 * 
	 * Outputs:
	 *  none
	 */
	void deleteRec(Node *node);
	
	
	
	/*
	 * Appends a node to the end of the list
	 * 
	 * Inputs:
	 *  node - The node to append
	 * 
	 * Outputs:
	 *  none
	 */
	void appendNode(Node *node);
	
	
	
	/*
	 * Removes and returns a node
	 * 
	 * Inputs:
	 *  prev - the node previous of the returned node
	 * 
	 * Outputs:
	 *  the removed node
	 */
	Node* removeNode(Node *prev);
	
	
	
	/*
	 * Returns the first node with the given name
	 * 
	 * Inputs:
	 *  name - the name to compare with
	 * 
	 * Outputs:
	 *  the first node with the name (nullptr if none)
	 */
	Node* getNodeWithArtistName(const char *name) const;
	
	
	
	friend std::ostream& operator<<(std::ostream &ostr, const RecordLabel &list);
	friend void printRec(std::ostream &ostr, RecordLabel::Node *node);
	
	// The data file
	static constexpr const char *FILE_NAME = "labels.data";
	
	
	
	/*
	 * Reads from the above file
	 * 
	 * Inputs:
	 *  the file to read from
	 * 
	 * Outputs:
	 *  reads the label data to this record label
	 */
	void readFromFile();
	
	
	
	/*
	 * Writes to the "above" file
	 * 
	 * Inputs:
	 *  the file to write to
	 * 
	 * Outputs:
	 *  writes label data to the file
	 */
	void writeToFile();
};



/*
 * Prints this RecordLabel to the std::ostream
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  list - the RecordLabel to print
 */
std::ostream& operator<<(std::ostream &ostr, const RecordLabel &list);



/*
 * Recursively prints the RecordLabel
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  node - the node to print
 */
void printRec(std::ostream &ostr, RecordLabel::Node *node);
#endif
