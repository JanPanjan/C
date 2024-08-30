#include <stdio.h>

int main() {
	int i = 10;
	for (i; i > 0; i--) {
	    printf("%d -> %d\n", i, i-1);
	}

	// continue ali break
	for (int i = 0; i < 10; i++) {
	    if (i % 2 == 0) {
	        continue;
	    }
	    printf("\n%d is odd", i);
	}

	return 0;
}
