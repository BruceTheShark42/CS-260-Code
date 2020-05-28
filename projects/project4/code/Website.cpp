/*
 * Website.cpp
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #4
 * 
 * The implementation of Website
 */

#include "Website.h"
#include <cstring>

using namespace std;

Website::Website()
		: topic(nullptr), keyword(nullptr), url(nullptr), summary(nullptr), review(nullptr), rating(1) {}

Website::Website(const char *topic, const char *keyword, const char *url, const char *summary, const char *review, char rating)
		: rating(rating) {
	this->topic = new char[strlen(topic) + 1];
	strcpy(this->topic, topic);
	this->keyword = new char[strlen(keyword) + 1];
	strcpy(this->keyword, keyword);
	this->url = new char[strlen(url) + 1];
	strcpy(this->url, url);
	this->summary = new char[strlen(summary) + 1];
	strcpy(this->summary, summary);
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
}

Website::Website(const Website &website)
		: topic(nullptr), keyword(nullptr), url(nullptr), summary(nullptr), review(nullptr) {
	*this = website;
}

// Yes I know this is a bit of repetition, but I don't care here.
Website& Website::operator=(const Website &website) {
	if (topic != nullptr) delete[] topic;
	topic = new char[strlen(website.topic) + 1];
	strcpy(topic, website.topic);
	
	if (keyword != nullptr) delete[] keyword;
	keyword = new char[strlen(website.keyword) + 1];
	strcpy(keyword, website.keyword);
	
	setURL(website.url);
	
	if (summary != nullptr) delete[] summary;
	summary = new char[strlen(website.summary) + 1];
	strcpy(summary, website.summary);
	
	setReview(website.review);
	rating = website.rating;
}

Website::~Website() {
	if (topic != nullptr) delete[] topic;
	if (keyword != nullptr) delete[] keyword;
	if (url != nullptr) delete[] url;
	if (summary != nullptr) delete[] summary;
	if (review != nullptr) delete[] review;
}

bool Website::checkTopic(const char *topic) const {
	return strcmp(this->topic, topic) == 0;
}

bool Website::checkKeyword(const char *keyword) const {
	return strcmp(this->keyword, keyword) == 0;
}

void Website::setKeyword(const char *keyword) {
	if (this->keyword != nullptr) delete[] this->keyword;
	this->keyword = new char[strlen(keyword) + 1];
	strcpy(this->keyword, keyword);
}

bool Website::operator<(const char *keyword) const {
	size_t len = strlen(this->keyword), klen = strlen(keyword);
	for (size_t i = 0; i < len && i < klen; ++i) {
		if (this->keyword[i] < keyword[i])
			return true;
		else if (this->keyword[i] > keyword[i])
			return false;
	}
	// they are the same, which shouldn't happen
	return false;
}

bool Website::operator>(const char *keyword) const {
	return strcmp(this->keyword, keyword) && !(*this < keyword);
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
	return ostr << " Website:\n - Topic: " << website.topic
				<< "\n - Keyword: " << website.keyword
				<< "\n - URL: " << website.url
				<< "\n - Summary: " << website.summary
				<< "\n - Review: " << website.review
				<< "\n - Rating: " << +website.rating
				<< '\n';
}
