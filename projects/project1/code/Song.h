/*
 * Song.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 * 
 * Used to store data about a song
 */

#ifndef SONG_H
#define SONG_H
#include <ostream>
#include <fstream>

class Song {
public:
	/*
	 * Constructs a new Song
	 * 
	 * Inputs:
	 *  title - the title of the song
	 *  length - the length of the song
	 *  views - the number of views
	 *  likes - the number of likes
	 */
	Song(const char *title, float length, int views, int likes);
	
	
	
	/*
	 * Destructs a song
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~Song();
	
	
	
	/*
	 * Checks if this song has a given title
	 * 
	 * Inputs:
	 *  title - the title to compare
	 * 
	 * Outputs:
	 *  whether or not this song has the given title
	 */
	bool hasTitle(const char *title) const;
	
	
	
	/*
	 * Gets the number of views
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the number of views
	 */
	int getViews() const;
	
	
	
	/*
	 * Sets the number of views
	 * 
	 * Inputs:
	 *  views - the new number of views
	 * 
	 * Outpits:
	 *  none
	 */
	void setViews(int views);
	
	
	
	/*
	 * Sets the number of likes
	 * 
	 * Inputs:
	 *  likes - the new number of likes
	 * 
	 * Outputs:
	 *  none
	 */
	void setLikes(int likes);
	
	
	
	/*
	 * Converts this song to my custom file format
	 * 
	 * Inputs:
	 *  file - the std::ofstream to write to
	 * 
	 * Outputs:
	 *  writes this song to the file
	 */
	void toFileFormat(std::ofstream &file) const;
private:
	friend std::ostream& operator<<(std::ostream &ostr, const Song &song);
	
	// Stores the title of the song
	char *title;
	// Stores the length of the song
	float length;
	// Stores the number of views of the song
	int views;
	// Stores the number of likes of the song
	int likes;
};



/*
 * Prints a song
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  song - the song to print
 * 
 * Outputs:
 *  writes this song to ostr
 */
std::ostream& operator<<(std::ostream &ostr, const Song &song);
#endif
