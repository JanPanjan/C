/**
 * NAL: Inicializiraj niz (string) texta lorem ipsum. Uporabnika vprašaj
 * za poljuben niz(string). Napiši funkcijo, ki sprejme text, uporabnikov
 * text in naslov spremenljivke v katero naj shrani število ponovitev 
 * 
 * IZPIS:
 * Vpiši besedo: s
 * St. pojavitev: 39
*/

#include <stdio.h>

void count(char string[], char target[], int* p_counter);

int main() {
    char str[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    int counter;

    printf("Vpisi besedo: ");
    char word[50];
    scanf("%s", word);

    count(str, word, &counter);
    printf("Stevilo pojavitev: %i\n", counter);
}

void count(char string[], char target[], int* p_counter) {
    *p_counter = 0;
    int i = 0;
    while (string[i] != '\0') {
        int same = 1;
        int j = 0;
        while (target[j] != '\0') {
            if (string[i + j] == '\0') {
                break;
            }
            if (string[i + j] != target[j]) {
                same = 0;
                break;
            }
            j++;
        }
        if (same) {
            *p_counter += 1;
        }
        i++;
    }
}


