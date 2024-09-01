#include <stdio.h>

int main() {
	// naredimo struct oseba
	struct Oseba {
		char ime[25];
		char priimek[25];
		int starost;
	};

	// inicializiramo osebo
	struct Oseba jan = {
		.starost = 21,
		.ime = "Jan",
		.priimek = "Panjan"
	};
	struct Oseba lana = {
		.starost = 20,
		.ime = "Lana",
		.priimek = "Grudnik"
	};

	return 0;
}
