#include <stdio.h>

int main() {
    char str[] = {'H', 'i', ' ', 'L', 'a', 'n', 'a', '\0'};
    // char str[] = "Hi Lana";
    printf("%s\n", str);

    // 8 znakov -> length bo 8, ceprav je v bistvu 7 crk
    int len = sizeof(str)/sizeof(char);
    printf("string length: %d\n", len);

    // dostopanje do elementov je enako kot arrays
    // moramo podati %c
    printf("crka na prvem mestu (0): %c\n", str[0]);
    printf("crka na zadnjem mestu (7): %c\n", str[len - 1]);
    // ne vidi se, ker je \0
    
    // spreminjanje elementov enako kot arrays
    str[0] = 'h';
    printf("new string: %s\n", str);

    return 0;
}
