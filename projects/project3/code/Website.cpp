#include "Website.h"
#include <cstring>

using namespace std;

Website::Website()
		: url(nullptr), summary(nullptr), review(nullptr), rating(1) {}

Website::Website(const char *url, const char *summary, const char *review, char rating)
		: rating(rating) {
	this->url = new char[strlen(url) + 1];
	strcpy(this->url, url);
	this->summary = new char[strlen(summary) + 1];
	strcpy(this->summary, summary);
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
}

Website::Website(const Website &website)
		: url(nullptr), summary(nullptr), review(nullptr) {
	*this = website;
}

// Yes I know this is a bit of repetition, but I don't care here.
Website& Website::operator=(const Website &website) {
	if (url != nullptr) delete[] url;
	url = new char[strlen(website.url) + 1];
	strcpy(url, website.url);
	
	if (summary != nullptr) delete[] summary;
	summary = new char[strlen(website.summary) + 1];
	strcpy(summary, website.summary);
	
	if (review != nullptr) delete[] review;
	review = new char[strlen(website.review) + 1];
	strcpy(review, website.review);
	
	rating = website.rating;
}

Website::~Website() {
	if (url != nullptr) delete[] url;
	if (summary != nullptr) delete[] summary;
	if (review != nullptr) delete[] review;
}

bool Website::checkURL(const char *url) const {
	return strcmp(this->url, url) == 0;
}

void Website::setURL(const char *url) {
	if (this->url != nullptr) delete[] this->url;
	this->url = new char[strlen(url) + 1];
	strcpy(this->url, url);
}

void Website::setReview(const char *review) {
	if (this->review != nullptr) delete[] this->review;
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
}

std::ostream& operator<<(std::ostream &ostr, const Website &website) {
	return ostr << " Website:\n - URL: " << website.url
				<< "\n - Summary: " << website.summary
				<< "\n - Review: " << website.review
				<< "\n - Rating: " << +website.rating
				<< '\n';
}
