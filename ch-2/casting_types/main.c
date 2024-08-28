#include <stdio.h>

int main() {
	int a;
	double b = 3.14435676;

	// zdaj hočemo, da b vrednost postane int
	a = b // ali ""a = (int)b;"

	printf("vrednost b: %f\n", b);
	printf("vrednost a: %d\n", a);

	return 0;
}
