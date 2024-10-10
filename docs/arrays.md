# Arrays

Osnovna podatkovna struktura. Gre se za to, da je več spremenljivk z istim podatkovnim tipom (glej [variables](docs/variables.md)) shranjenih v nek _blok_ spomina.

Uporabno, ko moramo shranit več vrednosti istega tipa, ki so povezane med sabo.

Na primer koordinate $x$, $y$ in $z$ lahko pišemo:

    int main() {
        int x;
        int y;
        int z;
    }

Bolj organizirano, ko se pojavi več in več spremenljivk, je hraniti array:

    int main() {
        int koordinate[3] = {1, 2, 3};
    }

Zdaj so vse shranjene v **eni** spremenljivki

---

Prav tako, če bi ustvaril npr.

    int a = 1;
    char b = 'b';
    int c = 2;

Bi v spominu to izgledalo nekako tako:

    int:a[ 1 ] | char:b[ 'b' ] | int:c[ 2 ]

Zdaj naši števili nista eden zraven drugega. To je drugače, če naredimo array.

    int array[2] = {1, 2};
    char b = 'b';

Zdaj je spomin:

    int:array{[0][ 1 ] | [1][ 2 ]} | char:b[ 'b' ]

Anyways, yeah.

# Ustvarjanje polj

## Neinicializirana polja

Ustvarjen brez podanih vrednosti.

    int age[4];

Nujno moraš podat velikost, zato da compiler ve koliko prostora mora rezervirati. Ko je enkrat ustvarjen mu **ne moreš spreminjati velikosti** (_static_).

## Inicializirano polje

Ustvarjen s podanimi vrednostmi.

    int age[] = {1, 2, 3, 4};

V tem primeru mu ne podamo vrednosti za velikost, saj to pove število vnesenih
vrednosti (a vseeno lahko).

# Delo z vrednostmi

## Velikost polja

Ker v C-ju direktno delaš s spominom (nima automatic memory allocation), moraš
pazit kako spreminjaš vrednosti arrayev. Če boš izbral za index manj kot 0 ali
več kot `arraySize - 1`, boš spreminjal neke druge vrednosti znotraj programa,
kar ni dobro ane.

Da dobiš velikost polja, lahko uporabiš funckijo `sizeof()`. Funkcija vrne
integer velikosti polja v bajtih.

Bolj primerno za
for loops, kjer lahko za pogoj pišeš npr. `i < sizeof(array)`.

Ker vrne vrednost v bytes, ki jih je zasedel array, moramo deliti vrednost s
številom bajtov, ki jih zasede ena vrednost uporabljenega tipa.

Na primer, integerji uporabijo 4 bajte vsak. Če imamo polje velikosti 5, bo
sizeof vrnila 20 (bajtov). 
dobljeno vrednost moramo deliti s 4, da dobimo 5 (velikost polja).

    int polje[5];
    sizeof(polje)/4;

Na srečo lahko sizeof vrne tudi število bajtov, ki jih zahteva nek podatkovni
tip. Če pišemo torej sizeof(int), vrne 4 (bajte).

    sizeof(polje)/sizeof(int);

## Dostopanje elementov

    array[index]

Prvi index je 0, zadnji index je `arraySize - 1`.

Fun fact: ko ustvarimo pointer na array, bo ta kazal na prvi element. Število, ki ga podamo znotraj `[]` je v bistvu offset za pointer - koliko mest naprej naj pogleda.

Torej offset = 2, pomeni glej 2 adressa naprej.

## Spreminjanje elementov

    array[index] = newValue

Kot da bi naredil novo spremenljivko.

# Multidimenzionalna polja

    int array[1][2];
    int array[][2] = { {1,2,3}, {4,5,6} };

Do njihovih elementov dostopamo z _nested loops_

```
for (int i; ...) {
    for (int j; ...) {
        polje[i][j];
    }
}
```

Da nam ni treba **hard**kodirat velikosti dimenzij polja v for loop, naredimo
spremenljivki:

```
int arr[3][3] = {......};

int row = sizeof(arr)/sizeof(arr[0]);
int col = sizeof(arr[0])/sizeof(int);

```
