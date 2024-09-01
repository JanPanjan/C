#include <stdio.h>

int main() {
	// NOTE: naredimo struct oseba
	struct Oseba {
		char ime[25];
		char priimek[25];
		int starost;
	};

	// NOTE: inicializiramo osebo
	// dve vrsti inicializacije:
	struct Oseba lana = {"Lana", "Grudnik", 20};

	struct Oseba jan = {
		.starost = 21,
		.ime = "Jan",
		.priimek = "Panjan"
	};

	// NOTE: dostopanje do elementov
	// dot operator
	printf("jan je star %d let\n", jan.starost);
	printf("lana se piše %s\n", lana.priimek);

	// pointerji in structs
	struct Oseba *jan_p = &jan;	
	struct Oseba *lana_p = &lana;	

	// dot operator in pointer
	printf("panjan %s\n", (*jan_p).ime);
	printf("lana %s\n", (*lana_p).priimek);
	// arrow notation
	printf("panjan %s\n", jan_p->ime);
	printf("lana %s\n", lana_p->priimek);

	return 0;
}
