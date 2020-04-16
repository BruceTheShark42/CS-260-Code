// Made by Bruce Cosgrove

#ifndef SONG_H
#define SONG_H
#include <ostream>
#include <fstream>

class Song {
public:
	Song(const char *title, float length, int views, int likes);
	~Song();
	
	bool hasTitle(const char *title) const;
	int getViews() const;
	void setViews(int views);
	void setLikes(int likes);
	void toFileFormat(std::ofstream &file) const;
private:
	friend std::ostream& operator<<(std::ostream &ostr, const Song &song);
	
	char *title;
	float length;
	int views;
	int likes;
};

std::ostream& operator<<(std::ostream &ostr, const Song &song);
#endif
