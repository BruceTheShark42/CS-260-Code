/*
 * Artist.h
 *
 * Bruce Cosgrove
 * CS 260
 * Assignment #1
 * 
 * Used to store data about an Artist
 */

#ifndef ARTIST_H
#define ARTIST_H
#include "SongList.h"
#include <ostream>
#include <fstream>

class Artist {
public:
	/*
	 * Constructs a new Artist
	 * 
	 * Inputs:
	 *  name - the artist's name
	 *  topStory - the artist's top story
	 *  description - the artist's description
	 * 
	 * Outputs:
	 *  none
	 */
	Artist(const char *name, const char *topStory, const char *description);
	
	
	
	/*
	 * Destructs an artist
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~Artist();
	
	
	
	/*
	 * Adds a song to the artist's album
	 * 
	 * Inputs:
	 *  title - the song title
	 *  length - the song length
	 *  views - the song view count
	 *  likes - the song like count
	 * 
	 * Outputs:
	 *  whether or not the song could be added
	 */
	bool addSong(const char *title, float length, int views, int likes);
	
	
	
	/*
	 * Removes any unpopular songs
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
	 *  views - the song view count
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
	 *  views - the song like count
	 * 
	 * Outputs:
	 *  whether or not the song's likes could be set
	 */
	bool setSongLikes(const char *title, int likes);
	
	
	
	/*
	 * Checks if the artist has a given name
	 * 
	 * Inputs:
	 *  name - the name to test
	 * 
	 * Outputs:
	 *  whether or not the names match
	 */
	bool hasName(const char *name) const;
	
	
	
	/*
	 * Converts this artist to my custom format
	 * 
	 * Inputs:
	 *  file - the file to output to
	 * 
	 * Outputs:
	 *  converts this artist to my custom format and writes it to the file
	 */
	void toFileFormat(std::ofstream &file) const;
private:
	// name is used for identifying this Artist
	// topStory and description are only used for printing/writing to files and serve no purpose whatsoever
	char *name, *topStory, *description;
	// Stores the list of songs
	SongList songs;
	
	friend std::ostream& operator<<(std::ostream &ostr, const Artist &artist);
};



/*
 * Prints the artist to a std::ostream
 * 
 * Inputs:
 *  ostr - the std::ostream to output to
 *  artist - the artist to output
 * 
 * Outputs:
 *  the artist is written to the std::ostream
 */
std::ostream& operator<<(std::ostream &ostr, const Artist &artist);
#endif
