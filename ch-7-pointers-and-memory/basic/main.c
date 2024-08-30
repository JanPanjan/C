#include <stdio.h>

int main() {
    // NOTE: reference operator
    int aa = 123;
    int *aa_p = &aa;
    printf("aa: %d\n", aa);
    printf("pointer: %p\n\n", aa_p);

    // NOTE: dereference operator
    int b = 2;
    int *b_p = &b;
    printf("adress: %p\n", b_p);
    printf("value in adress: %d\n\n", *b_p);

    // NOTE: pointer arithmetic
    printf("adress:                 %p\n", b_p);
    b_p += 1;
    printf("adress after increment: %p\n\n", b_p);
    // notice, kako se je spremenil za 4 bytes
    // s char se bo spremenil za en byte
    char f = 'a';
    char *f_p = &f;
    printf("adress:                 %p\n", f_p);
    f_p += 1;
    printf("adress after increment: %p\n\n", f_p);

    return 0;
}
