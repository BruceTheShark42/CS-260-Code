#ifndef WEBSITE_H
#define WEBSITE_H

#include <ostream>

class Website {
public:
	Website();
	Website(const char *url, const char *summary, const char *review, char rating);
	Website(const Website &website);
	Website& operator=(const Website &website);
	~Website();
public:
	bool checkURL(const char *url) const;
	inline const char* getURL() const { return url; }
	void setURL(const char *url);
	inline const char* getSummary() const { return summary; }
	inline const char* getReview() const { return review; }
	void setReview(const char *review);
	inline char getRating() const { return rating; }
	inline void setRating(char rating) { this->rating = rating; }
public:
	friend std::ostream& operator<<(std::ostream &ostr, const Website &website);
private:
	char *url, *summary, *review, rating;
};

std::ostream& operator<<(std::ostream &ostr, const Website &website);

#endif
