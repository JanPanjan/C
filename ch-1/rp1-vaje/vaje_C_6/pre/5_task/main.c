/**
    NAL: Napiši nalogo za okvirno ocenjevanje domače naloge. Program študenta vpraša
    po posameznih kosih domače naloge in nato prikaže točke. Uporabnik lahko odgovori 
    z "Da", "Ne" ali "Približno", tako da vpiše črke 'd', 'n' ali 'p'. Če uporabnik 
    na vsa vprašanja odgovri z "Da", program uporabnika tudi vpraša, če je opravil 
    dodaten del naloge, ki prinese bonus točke. Če uporabnik ni na vse odgovri z 
    "Da", se ta del dialoga ne pokaže. Če študent odgovori z "Da" naj dobi 2 točki,
    če odgovri z "Ne" 0 točk, če pa z "Probljižno" pa 1. 

    
    IZPIS:
    Mogoči odvogori na vprašanja (d-Da | n-Ne | p-približno)
    Ali program opravi obvezni del naloge? d
    Ali si uporabljal funkcije? d
    Ali si uporabljal lokalne spremenljivke in ne globalne? d
    Ali si preveril validnost vnosov? d
    Ali si uporabljal komentarje? d
    Ali si implementiral dodatni del naloge? d
    Predvideno število točk je približno 12.
*/

#include <stdio.h>
#include <stdbool.h>


void question(char prompt[], int* points, bool* everythingDone);

int main() {
    char answer;
    bool everythingDone = true;
    int points = 0;

    printf("Mogoči odvogori na vprašanja (d-Da | n-Ne | p-približno)\n");
    question("Ali program opravi obvezni del naloge? ", &points, &everythingDone);
    question("Ali si uporabljal funkcije? ", &points, &everythingDone);
    question("Ali si uporabljal lokalne spremenljivke in ne globalne? ", &points, &everythingDone);
    question("Ali si preveril validnost vnosov? ", &points, &everythingDone);
    question("Ali si uporabljal komentarje? ", &points, &everythingDone);

    if (everythingDone) {
        question("Ali si implementiral dodatni del naloge? ", &points, &everythingDone);
    }
    printf("Predvideno število točk je okrog %i.\n", points);
}

void question(char prompt[], int* points, bool* everythingDone) {
    char input;
    printf("%s", prompt);
    scanf(" %c", &input);
    if (input == 'd') {
        *points += 2;
    } else if (input == 'n') {
        *everythingDone = false;
    } else if (input == 'p') {
        *everythingDone = false;
        *points += 1;
    } else {
        // optional part
        printf("Prosim odgovori z 'd', 'n' ali 'p'\n");
        question(prompt, points, everythingDone);
    }
}