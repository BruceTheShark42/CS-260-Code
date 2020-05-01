#include "util.h"
#include <cstring>

void copyString(char *&dst, const char *src) {
	dst = new char[std::strlen(src) + 1];
	std::strcpy(dst, src);
}
