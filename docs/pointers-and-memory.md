# Pointers and memory

Pointer pointa v nek blok spomina, ki ga zasede neka spremenljivka primitivnega tipa (int, char, double) ali nek tip definiran s struct.

Point pointerjev (pun intended) je, da zmanjšajo porabo spomina. Torej v bistvu ne ustvariš nove spremenljivke, ampak pokažeš _kje je nekaj shranjeno_.

## Sintaksa

    dataType* nameOfPointer;
    dataType *nameOfPointer;

Eno ali drugo. Npr.

    int* ptr;
    int *ptr;

## Reference operator

Pointer hrani _adress_ (naslov) prvega bajta spomina spremenljivke. Da nakažemo, da se shrani adress v pointer, uporabimo `&` (reference operator) pred imenom željene spremenljivke.

    &variableName;

Pointerji so mutable, torej lahko, kot spremenljivkam, shraniš drug adress tekom izvajanja programa, tako da podaš drug adress

    ptr = &drugVariable;

---

Da torej naredimo pointer:

    int aaa = 123;
    int *aaa_p = &aaa;

## Dereference operator

če želimo izpisati/uporabiti **vrednost** shranjena v adressu pointerja, moramo uporabiti `*` (dereference operator).

    *ptr;

Ko je pointer enkrat _dereferenced_, lahko uporabimo njegovo vsebino (vrednost, ki je shranjena), kot navadno spremenljivko.

    int bbb = *ptr;

Toda ne spreminjamo vrednosti pointerja, ampak vrednost shranjeno v adressu - v bistvu spreminjamo spremenljivko.

# printf in pointerji

Če hočeš prikazat adress shranjen v pointerju, moraš v funkciji `printf` uporabiti `%p`.

    printf("%p", aaa_p);

Output bo drugačen vsakič, ko zaženeš program. Če hočeš prikazati vrednost shranjeno v pointerju:

    printf("%d", *aaa_p);

# Operacije s pointerji

Ker so pointerji basically posebne spremenljivke, lahko z njimi opravljamo tudi (osnovne) aritmetične operacije, seštevanje in odštevanje.

Odštevanje/prištevanje pomeni, da bo pointer kazal na drug blok spomina.

Deljenje in množenje nista dovoljena. Če delimo adress, lahko pride do iracionalnega števila (potrebujemo integer). Če množimo, lahko naletimo na zelo visoko število, ki je izven ranga razpoloženega spomina.

Prav tako ne moreš seštevat pointerjev med sabo. Seštevanje velja samo z integerji (1,2,3...).

    ptr++;
    ptr += 1;
    ptr = ptr + 1;

## Kako to deluje

Dodati $n$ ne pošlje pointerja v naslednji blok spomina, ampak 

$$
n \times \text{velikost podatkovnega tipa v bajtih (bytes)}
$$

Če kaže pointer na int, ki ima 4 bajte, bo nov adress kazal na adress 4 mesta stran ($1 \times 4$). Če bi dodali 2, bi kazal 8 mest stran.

Primer:

    pointer += 3;

To shrani pointer iz idk 100 adress na 112 adress, 3 int sizes away.

V primeru, da ga pošlješ predaleč, ti bo program crashal.

# Pointers and arrays

Ker so [arrays](docs/arrays.md) *contiguous blocks of memory* rezervirani za en podatkovni tip, gredo hand in hand s pointerji. Če imamo int pointer, lahko gremo s pomočjo tega pointerja skozi array ali spreminjamo vrednosti arraya.

Čeprav izgleda prezakomplicirano početi s pointerji, so potrebni za nekatere funkcije arrayev.

# Memory allocation

Spomin je razdeljen v dve kategoriji - _stack_ in _heap_.

## Stack

Del spomina, ki je zelo organiziran. Podatki so na voljo le znotraj določenega scop-a.

Ko ustvariš spremenljivko, _statično_ zapolniš spomin. Ta spomin se sprosti le, ko program ne potrebuje več spremenljivke.

## Heap

Dinamično polnjene spomina. Basically, ti rečeš, da naj se rezervira nekaj spomina in ta bo ostal rezerviran dokler eksplicitno ne rečeš, da ga nočeš več.

Pozabiti sprostit _dynamically allocated memory_ bo privedlo do memory-leaks in poor preformance.

# Funckije za dynamic memory allocation

V C-ju obstajajo funkcije, s katerimi dinamično alociramo spomin (in ga sprostimo):

- malloc
- calloc
- realloc
- free

Potrebuješ `stdlib` library in vsaj en pointer.

## malloc()

Rezerviraj bytes na heap.

## calloc()

Rezerviraj spomin za neke ints, doubles ali katerikoli podatkovni tip.

## realloc()

Razširi ali zoožaj blok rezerviranega spomina (ta ki je bil rezerviran z malloc ali calloc).

## free()

Sprosti prej rezerviran spomin.
