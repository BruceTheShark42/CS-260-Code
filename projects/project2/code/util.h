/*
 * util.h
 * 
 * Bruce Cosgrove
 * CS 260
 * Assignment #2
 * 
 * Generic functions and constants that many files may need
 */

#ifndef UTIL_H
#define UTIL_H

#define MAX_CHARS 256

/*
 * Copies one cstring another
 * 
 * Inputs:
 *  dst - the copied cstring
 *  src - the cstring to copy
 * 
 * Outputs:
 *  Allocates memory for dst and copies src to it
 */
void copyString(char *&dst, const char *src);

#endif
