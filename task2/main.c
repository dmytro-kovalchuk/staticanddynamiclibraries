#include <stdio.h>
#include <stdlib.h>
#include "format.h"

int main(void) {
	char format;
	printf("Choose format to convert - (l)ower or (u)pper: ");
	char format = getchar();
	getchar();

	char string[256];
	printf("Enter text: ");
	fgets(string, sizeof(string), stdin);

	if (format == 'l') {
		to_lower(&string);
	} else if (format == 'u') {
		to_upper(&string);
	} else {
		printf("Error! Invalid format to convert!");
		return 1;
	}
	
	printf("Result: %s", string);

	return 0;
}
