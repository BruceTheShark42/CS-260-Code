// Made by Bruce Cosgrove

#ifndef SONG_H
#define SONG_H
#include <ostream>

class Song {
public:
	Song(const char *title, const float &length, const unsigned int &views, const unsigned int &likes);
	~Song();
	
	const char* getTitle() const;
	bool hasTitle(const char *title) const;
	float getLength() const;
	unsigned int getViews() const;
	void setViews(const unsigned int &views);
	unsigned int getLikes() const;
	void setLikes(const unsigned int &likes);
private:
	friend std::ostream& operator<<(std::ostream &ostr, const Song &song);
	
	char *title;
	float length;
	unsigned int views;
	unsigned int likes;
};

std::ostream& operator<<(std::ostream &ostr, const Song &song);
#endif
