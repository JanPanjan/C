#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func() {
	int speed        = rand() % 3 + 1;
	int acceleration = rand() % 3 + 1;
	int nerves       = rand() % 3 + 1;

	return speed + acceleration + nerves;
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		printf("value %d: %d\n", i, func());
	}

    return 0;
}
