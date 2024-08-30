# Strings
V bistvu so strings [arrays](docs/arrays.md) of chars (glej [podatkovne tipe](docs/variables.md)).
To pomeni, da so podvrženi enakim stvarem kot arrays - ne moremo jim spreminjati velikosti.

## Ustvarjanje string

Kot da delaš array:

    char str[] = {'H', 'i', ' ', 'L', 'a', 'n', 'a', '\0'};

Blankspace je tudi character in vsak string mora imeti _null terminating
character_, ki nakaže **kje se konča string**, zato je v bistvu length vedno +1
od vseh znakov v besedi.

Če hočemo dobiti zadnjo črko, moramo reči `length - 2`, saj samo `-1` pride do
`\0`.

---

String lahko ustvarimo tudi tako (bolj priročno):

    char str[] = "Hi Lana";

## printf strings

Da izpišemo string, moramo uporabiti `%s`.

    printf("%s\n", str);

Da dobimo črko iz stringa pišemo:

    printf("%c\n", str[0]);

Črke spreminjamo enako kot elemente v poljih (A NE MOREMO SPREMINJATI VELIKOSTI
oz. dodajati/odstranjevati črk).

    str[0] = y;

# <string.h>

Library za razne stvari s strings. Dodaj to na vrh C datoteke:

    #include <string.h>

## loops in strings

Ko delamo z loops npr. je težko vedet dolžine stringov vedno. Zato obstaja
funkcija `strlen()`, ki vrne dolžina stringa **brez null characterja**

Potem skozi loop do elementov dostopaš enako kot pri arrays...

## concatenating strings - združevanje nizov

Funkcija `strcat()` združi dva stringa.

    strcat(dst, src);

- `dst`: destination string
- `src`: source string

Ne ustvari tretji string, ampak **posodobi dst string**. Ampak vemo, da so
strings (arrays) immutable, rigth? Kaj se potem zgodi...

>Funkcija sprejme dva niza in ustvari char array velikosti `strlen(src) + strlen(dst) + 1` (ker strlen ne upošteva `\0`, moramo dodati na konec še en znak, zato je +1). Potem zapolni array z zanki iz obeh nizov, začne z dst. Nato zavrže spomin, kjer je bil shranjen **prvotni** dst string in asociira ([pointers](docs/pointers.md)) dst z novim char array.

Če jih hočeš več združit, moraš vsako posebej:

    strcat(a, b);
    strcat(a, c);
    strcat(a, d);
    ...

## copying strings - kopiranje nizov

Nize kopiramo s funkcijo `strcpy()`. Funkcija kopira string v prazen char array.

    strcpy(dst, src);

>Funkcija kopira vsebino src niza v dst niz. Pomembno je, da je velikost
>praznega char polja večja ali enaka **dolžini src niza + 1**. Če je prekratek,
>bo šlo vse v kurac.
