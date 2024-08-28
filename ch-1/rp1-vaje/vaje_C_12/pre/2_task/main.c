/**
 * NAL: Inicializiraj niz (string) texta lorem ipsum. Uporabnika vprašaj
 * za poljubno črko. Napiši funkcijo, ki sprejme ta niz, črko in naslov spremenljivke
 * v katero naj shrani število ponovitev tega znaka v danem nizu.
 * 
 * IZPIS:
 * Vpiši črko: s
 * St. pojavitev: 73
*/
#include <stdio.h>

void count(char string[], char target, int* p_counter);


int main() {
    char str[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    int counter;
    printf("Vpisi crko: ");
    char target_char;
    scanf("%c", &target_char);
    count(str, target_char, &counter);
    printf("St. pojavitev: %i\n", counter);
}

void count(char string[], char target, int* p_counter) {
    *p_counter = 0;
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == target) {
            *p_counter += 1;
        }
        i++;
    }
}


