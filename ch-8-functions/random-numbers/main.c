#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// nastavimo seed za random number
	// time(NULL) nam da število sekund od 1.1.1970
	srand(time(NULL));

	// random stevilo med 1 in 20
	// +1 ker: ostanki pri deljenju z npr. 3 so 0, 1 in 2
	int randNum = rand() % 20 + 1;
	printf("num: %d\n", randNum);

    return 0;
}
