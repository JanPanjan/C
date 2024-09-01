#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
	float st = 4.5;
	char crka = 'a';

	printf("float st: %f\n", st);
	// NOTE: math
	printf("ceil: %f\n", ceil(st));
	printf("floor: %f\n", floor(st));
	printf("log: %f\n", log(st));

	printf("char crka: %c\n", crka);
	// NOTE: ctype
	printf("isupper: %d\n", isupper(crka));
	printf("toupper: %c\n", toupper(crka));

    return 0;
}
