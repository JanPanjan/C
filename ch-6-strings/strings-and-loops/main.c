#include <stdio.h>
#include<string.h>

int main() {
	char lana[] = "Lana";
	int len = strlen(lana); // funckija ne upošteva '\0'
	printf("%s\n", lana);
	printf("%d\n", len);

	// NOTE: loop z len
	printf("\nfor loop:\n");
	for (int i = 0; i < len; i++) {
		printf("%c\n", lana[i]);
	}
	
	// NOTE: strcat
	char jan[] = "jan";
	char panjan[] = "panjan";
	printf("%s\n", jan);
	printf("%s\n", panjan);

	strcat(jan, panjan); // ne naredimo novega stringa, ker modificira dst
	// string
	printf("%s\n", jan);

	// NOTE: strcpy
	char anja[] = "Anja";
	char new[5]; // moramo narediti prazen array
	printf("new before: %s\n", new);
	strcpy(new, anja);
	printf("new after: %s\n", new);

	return 0;
}
