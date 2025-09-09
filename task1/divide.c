#include "calc.h"
#include <stdlib.h>

int divide(int a, int b) {
	if (b == 0) {
		printf("Error! Division by zero!");
		exit(1);
	}
	return a / b;
}
