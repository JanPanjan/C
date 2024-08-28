#include <stdio.h>

int main() {
	int a = 3;
	int b = 3;

	printf("a before: %d\n", a);

	if (a == b) {
		a++;
	}

	printf("a after: %d\n", a);
}
