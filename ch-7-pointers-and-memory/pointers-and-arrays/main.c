#include <stdio.h>
#include <string.h>

int main() {
    // NOTE: loopanje skozi array
    int polje[5] = {1,2,3,4,5};
    int* ptr = &polje[0];

    // WARN: pazi da deliš s sizeof(type), ko iščeš velikost polja
    int len = sizeof(polje)/sizeof(int);

    printf("array before:\n");
    for (int i = 0; i < len; i++) {
        printf("%i\n", *ptr);   // print value in pointer adress
        ptr++;                  // increment pointer to next element
    }

    // zdaj pa hočem vse elemente spremeniti na 3:
    // WARN: pred tem moraš postaviti pointer nazaj na prvi element polja
    ptr = &polje[0];
    for (int i = 0; i < len; i++) {
        *ptr = 3;   // modify value
        ptr++;      // increment pointer
    }

    // poglejmo kaj se je zgodilo
    printf("array after:\n");
    for (int i = 0; i < len; i++) {
        printf("%d\n", polje[i]);
    }

    return 0;
}
