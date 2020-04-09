#ifndef ARTIST_H
#define ARTIST_H
#include "SongList.h"
#include <ostream>

class Artist {
public:
	Artist(const char *name, const char *topStory, const char *description);
	~Artist();

	bool addSong(const char *title, const float &length, const int &views, const int &likes);
	int getSongViews(const char *title) const;
	int getSongLikes(const char *title) const;
	bool setSongViews(const char *title, const int &views);
	bool setSongLikes(const char *title, const int &likes);
private:
	char *name, *topStory, *description;
	SongList songs;
	
	friend std::ostream& operator<<(std::ostream &ostr, const Artist &artist);
};
std::ostream& operator<<(std::ostream &ostr, const Artist &artist);
#endif
