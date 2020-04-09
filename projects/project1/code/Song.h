// Made by Bruce Cosgrove

#ifndef SONG_H
#define SONG_H
#include <ostream>

class Song {
public:
	Song(const char *title, const float &length, const int &views, const int &likes);
	~Song();
	
	const char* getTitle() const;
	bool hasTitle(const char *title) const;
	float getLength() const;
	int getViews() const;
	void setViews(const int &views);
	int getLikes() const;
	void setLikes(const int &likes);
private:
	friend std::ostream& operator<<(std::ostream &ostr, const Song &song);
	
	char *title;
	float length;
	int views;
	int likes;
};

std::ostream& operator<<(std::ostream &ostr, const Song &song);
#endif
