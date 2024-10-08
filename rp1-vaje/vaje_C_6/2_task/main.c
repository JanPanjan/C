/**
    NAL: napiši program, ki od uporabnika sprejme število. To število naj
    predstavlja polmer kroga. Vaš program naj izračuna in izpiše obseg in 
    ploščino kroga.

    IZPIS:
    Vapiši polmer: 5
    Obseg: 31.400000
    Ploščina: 78.500000
*/
#include <stdio.h>

int main() {
    double input;
    printf("Vpisi polmer: ");
    scanf("%lf", &input);

    printf("Obseg: %lf\n", (2 * 3.14 * input));
    printf("Ploščina: %lf\n", (3.14 * input * input));
}