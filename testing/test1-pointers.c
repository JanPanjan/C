#include <stdio.h>

/// ali lahko spremenimo vrednost na adressu znotraj obsega funkcije
void spremeni(int *ptr, int novoSt);
/// ali lahko spremenimo kam pointa pointer v obsegu funkcije
void adress(int *ptr);

int main() {
	int a = 10;
	int *a_p = &a;
	spremeni(a_p, 2);
	printf("staro st: %d\n", a);

	adress(a_p);
	printf("stari adress value: %d\n", *a_p);
	
	// WARN:
	// vrednost na adressu se je spremenila po spremeni()
	// adress se ni spremenil izven funkcije po adress()

    return 0;
}

void spremeni(int *ptr, int novoSt) {
	// spremenimo vrednost na adressu
	*ptr = novoSt;
	printf("novo st: %d\n", *ptr);
}

void adress(int *ptr) {
	int b = 25;
	// spremenimo adress
	ptr = &b;
	printf("novi adress value: %d\n", *ptr);
}
