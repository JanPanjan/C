#include <stdio.h>

/// funkcija brez pointerja
void myFunc(int a);
/// funkcija s pointerjem
void myOtherFunc(int *a);

int main() {
    // WARN: funkcije ne spreminjajo spremenljivk direktno
    int a = 10;
    myFunc(a);
    printf("a izven funkcije: %d\n", a);

    // moramo narediti pointer s katerim upravljamo vrednost a
    int *a_p = &a;
    // prav tako moramo prilagoditi funkcijo
    myOtherFunc(a_p);
    printf("a izven funkcije: %d\n", a);

    return 0;
}

void myFunc(int a) {
    a += 2;
    printf("a znotraj funkcije: %d\n", a);
}

void myOtherFunc(int *a) {
    *a += 2;
    printf("a znotraj funkcije: %d\n", *a);
}
