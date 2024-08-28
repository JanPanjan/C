#include <stdio.h>

int main() {
    // basic
    int a = 5;
    while (a > 0) {
	printf("a: %d\n", a);
	a--;
    }
    printf("no more a.\n\n");

    // square function
    int i = 9;
    int square = 81;
    while (i >= 0) {
	printf("%d   %d\n", i, square);
	i--;
	square = i * i;
    }

    return 0;
}
