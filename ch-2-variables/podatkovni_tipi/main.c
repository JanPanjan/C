#include <stdio.h>

int main() {
	int starost = 21;
	char ime = 'J';
	float ta_jajca = 2.5f;

	printf("Ime mi je %can pan%can\n", ime, ime);
	printf("Star sem %d let.\n", starost);
	printf("Ta jajca so velika: %f cm.\n", ta_jajca);

	// NOTE: velikosti podatkovnih tipov
	printf("int: %lli\n", sizeof(int));
	printf("float: %lli\n", sizeof(float));
	printf("double: %lli\n", sizeof(double));
	printf("char: %lli\n", sizeof(char));

	return 0;
}
