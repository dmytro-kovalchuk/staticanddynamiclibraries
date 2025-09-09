#include "format.h"
#include <ctype.h>

void to_lower(char* string) {
	char* curr_pos = string;
	while(*curr_pos != '\0') {
		*curr_pos = tolower(*curr_pos);
		curr_pos++;
	}
}
