#include <stdio.h>
#include <string.h>

struct Oseba {
	char ime[25];
	char priimek[25];
	int starost;
};

// NOTE: funkcije lahko imajo tudi return type struct
struct Oseba ageChange(struct Oseba os1, struct Oseba *os2) {
	os1.starost += 1;
	os2->starost += 1;
	// ker smo os2 s pointerjem spremenili vrednost, lahko vrnemo os1
	return os1;
}

int main() {
	struct Oseba jan = {"Jan", "Panjan", 21}; 
	struct Oseba lana = {"Lana", "Grudnik", 20}; 

	jan = ageChange(jan, &lana);

	printf("jan je star %d\n", jan.starost);
	printf("lana je stara %d\n", lana.starost);

    return 0;
}
