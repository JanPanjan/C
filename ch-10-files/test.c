#include <stdio.h>
#include <string.h>

int main() {
    FILE *ptr = fopen("sporocilo.txt", "r");
    char fin[1000];
    char vsebina[1000];
    
    while(fgets(fin, 1000, ptr) != NULL) {
	strcat(vsebina, fin);
    }

    printf("%s", vsebina);

    return 0;
}
