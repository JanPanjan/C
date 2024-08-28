#include <stdio.h>

int main() {
	// if-else
	int a = 2;
	int b = 3;
	int min1;

	if (a < b) {
		min1 = a;
	} else {
		min1 = b;
	}
	printf("min1: %d\n", min1);

	// tenary
	int x = 2;
	int y = 3;
	int min2;

	min2 = x < y ? x : y;
	printf("min2: %d\n", min2);

	// printf
	y > x ? printf("y je vecja stevilka. y = %d", y) : printf("x je vecja stevilka. x = %d", x);

	return 0;
}
