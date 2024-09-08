#include <stdio.h>
#include <string>

int main() {
	// naredimo pointer
	FILE *f_p; 

	// odpremo file
	f_p = fopen("sporocilo.txt", "r");

	// buffer string ki bo hranil vsebino
	char vsebina[1000];
	// string ki bo hranil vsebino po odprtju
	char ltm[1000];

	// preberemo vsebino
	while(fgets(vsebina, 100, f_p) != NULL) {
		printf("%s", vsebina);
		// dodamo v ltm
		strcat(vsebina, ltm);
	}

	// zapremo buffer
	fclose(f_p);


    return 0;
}
