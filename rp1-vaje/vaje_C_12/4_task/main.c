/**
 * NAL: Inicializiraj polje vsaj 10 števil. Napiši funkcijo reverse, ki 
 * sprejme polje števil, funkcija naj obrne zaporedje števil v polju. 
 * Pravtako implementiraj funkcijo swap, ki s pomočjo kazalcev(pointerjev) 
 * zamenja vrednosti števil naslovov dveh spremenjivk. Pravtako za uporabo 
 * definiraj konstanto NUM_AMOUNT, ki predstavlja velikost polja števil.
 * 
 * IZPIS:
 * 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
*/


#include <stdio.h>

void reverse(int nums[10]);
void swap(int* pa, int* pb);

const int NUM_AMOUNT = 10;

int main() {
    int nums[NUM_AMOUNT];
    for (int  i = 0 ; i < NUM_AMOUNT ; i++) {
        nums[i] = i + 1;
    }

    for (int i = 0 ; i < NUM_AMOUNT ; i++) {
        printf("%i ", nums[i]);
    }
    printf("\n");
    reverse(nums);
    for (int i = 0 ; i < NUM_AMOUNT ; i++) {
        printf("%i ", nums[i]);
    }
    printf("\n");
}

void reverse(int nums[NUM_AMOUNT]) {
    for (int i = 0 ; i < NUM_AMOUNT / 2; i++) {
        swap(&nums[i], &nums[NUM_AMOUNT - i - 1]);
    }
}

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}