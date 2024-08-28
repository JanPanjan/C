#include <stdio.h>

int main() {

	int i = 0;
	while (i < 10) {
		if (i == 5) {
			printf("nope\n");
			i++;
			continue;
		}
		printf("%d\n", i);
		i++;
	}

	int x = 0;
	for (x; x < 10; x++) {
		if (x == 5) {
			continue;
		}
		printf("%d\n", x);
	}

	return 0;
}
