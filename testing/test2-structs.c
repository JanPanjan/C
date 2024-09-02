#include <stdio.h>
#include <string.h>

int main() {
    struct Os {
	int num;
	char *ime;
    };

    struct Osa {
	int num;
	char ime[10];
    };

    struct Os windows;
    windows.num = 999;
    windows.ime = "Windows";
    printf("num: %d\nname: %s\n", windows.num, windows.ime);
    printf("windows.ime je pointer in kaže na prvo črko v \"Windows\"\n");
    printf("pointer pointa na: %c\n", windows.ime[0]);
    printf("drugi znak: %c\n", windows.ime[1]);

    struct Osa osasa;
    strcpy(osasa.ime, "osasta osa");
    printf("ime ose: %s\n", osasa.ime);
    printf("zdaj nimamo pointerja. ali lahko dostopamo do prvega elementa?\n");
    printf("prvi znak: %c\n", osasa.ime[0]);
    printf("drugi znak: %c\n", osasa.ime[1]);

    char *nek_niz = "blaBLA";
    printf("to je nek niz: %s\n", nek_niz);
    // spremenimo niz
    nek_niz = "bruhhhhhh";
    printf("to je nek niz po spremembi: %s\n", nek_niz);
    printf("adress niza: %p\n", nek_niz);

    for (int i = 0; i < strlen(nek_niz); i++) {
	printf("adr %d: %p\n", i, nek_niz);
	nek_niz++;
    }
    printf("zdaj je vrednost na adressu: %d\n", *nek_niz);

    char *aa = "jan";
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);
    aa++;
    printf("aa: %s; adr: %p\n", aa, aa);

    // BUG: crazy

    return 0;
}
