/*
 * util.cpp
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * The implementation of util functions
 */

#include "util.h"
#include <cstring>

void copyString(char *&dst, const char *src) {
	dst = new char[std::strlen(src) + 1];
	std::strcpy(dst, src);
}
