#include "calc.h"
#include <stdlib.h>

int sqroot(int n) {
	if (n < 0) {
		printf("Error! Root of a negative number!");
		exit(1);
	} else if (n == 0 || n == 1) return n;

	int low = 0, high = n;

	while (low <= high) {
		int mid = (low + high) / 2;
		int result = mid * mid;
		
		if (result == n) {
			return mid;
		} else if (result < n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return high;
}
