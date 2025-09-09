#include "format.h"
#include <ctype.h>

void to_upper(char* string) {
	char* curr_pos = string;
	while (*curr_pos != '\0') {
		*curr_pos = toupper(*curr_pos);
		curr_pos++;
	}
}
