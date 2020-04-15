#ifndef ARTIST_H
#define ARTIST_H
#include "SongList.h"
#include <ostream>
#include <fstream>

class Artist {
public:
	Artist(const char *name, const char *topStory, const char *description);
	~Artist();
	
	bool addSong(const char *title, float length, int views, int likes);
	void removeUnpopularSongs(int views);
	int getSongViews(const char *title) const;
	int getSongLikes(const char *title) const;
	bool setSongViews(const char *title, int views);
	bool setSongLikes(const char *title, int likes);
	bool hasName(const char *name) const;
	void toFileFormat(std::ofstream &file) const;
private:
	char *name, *topStory, *description;
	SongList songs;
	
	friend std::ostream& operator<<(std::ostream &ostr, const Artist &artist);
};
std::ostream& operator<<(std::ostream &ostr, const Artist &artist);
#endif
