#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funckija izpiše nekaj
void printMyFavoriteAnimal(void);
// funkcija vrne naključno število med 1 in podano zgornjo mejo
int getRandom1000(int maxNum);

int main() {
	srand(time(NULL));

	printMyFavoriteAnimal();

	// NOTE: rezultat funkcije shranimo v spremenljivko za poznejšo rabo
	int myNum = getRandom1000(100);
	printf("random num: %d\n", myNum);

	return 0;
}

void printMyFavoriteAnimal() {
	printf("My favorite animal is a Lana Grudnik!\n");
}

int getRandom1000(int maxNum) {
	return rand() % maxNum + 1;
}
