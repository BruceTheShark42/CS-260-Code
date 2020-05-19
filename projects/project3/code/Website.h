/*
 * Website.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #3
 * 
 * Used to store information about a Website
 */

#ifndef WEBSITE_H
#define WEBSITE_H

#include <ostream>

class Website {
public:
	/*
	 * Constructs a new Website
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the new Website
	 */
	Website();
	
	/*
	 * Constructs a new Website
	 * 
	 * Inputs:
	 *  url - the URL
	 *  summary - the summary
	 *  review - the review
	 *  rating - the rating
	 * 
	 * Outputs:
	 *  the new Website
	 */
	Website(const char *url, const char *summary, const char *review, char rating);
	
	/*
	 * Copies an existing Website
	 * 
	 * Inputs:
	 *  website - the Website to copy
	 * 
	 * Outputs:
	 *  the new Website
	 */
	Website(const Website &website);
	
	/*
	 * Copies an existing Website
	 * 
	 * Inputs:
	 *  website - the Website to copy
	 * 
	 * Outputs:
	 *  this Website
	 */
	Website& operator=(const Website &website);
	
	/*
	 * Destructs a Website
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  none
	 */
	~Website();
public:
	/*
	 * Checks if this Website's URL is the same as the given URL
	 * 
	 * Inputs:
	 *  url - the URL to compare
	 * 
	 * Outputs:
	 *  if the URLs are the same
	 */
	bool checkURL(const char *url) const;
	
	/*
	 * Returns the URL
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the URL
	 */
	inline const char* getURL() const { return url; }
	
	/*
	 * Sets the URL
	 * 
	 * Inputs:
	 *  url - the new URL
	 * 
	 * Outputs:
	 *  none
	 */
	void setURL(const char *url);
	
	/*
	 * Returns the summary
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the summary
	 */
	inline const char* getSummary() const { return summary; }
	
	/*
	 * Returns the review
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the review
	 */
	inline const char* getReview() const { return review; }
	
	/*
	 * Sets the review
	 * 
	 * Inputs:
	 *  review - the new review
	 * 
	 * Outputs:
	 *  none
	 */
	void setReview(const char *review);
	
	/*
	 * Returns the rating
	 * 
	 * Inputs:
	 *  none
	 * 
	 * Outputs:
	 *  the rating
	 */
	inline char getRating() const { return rating; }
	
	/*
	 * Sets the rating
	 * 
	 * Inputs:
	 *  rating - the new rating
	 * 
	 * Outputs:
	 *  none
	 */
	inline void setRating(char rating) { this->rating = rating; }
public:
	friend std::ostream& operator<<(std::ostream &ostr, const Website &website);
private:
	char *url, *summary, *review, rating;
};

/*
 * Writes a Website to a std::ostream
 * 
 * Inputs:
 *  ostr - the std::ostream to write to
 *  website - the Website to write
 * 
 * Outputs:
 *  returns ostr
 */
std::ostream& operator<<(std::ostream &ostr, const Website &website);

#endif
