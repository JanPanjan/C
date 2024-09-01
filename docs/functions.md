# Functions

Funkcije so vlabkadld, sprejmejo ARGUMENTE.

    funkcija(x, y, c);

x y in c so argumenti.

    funkcija(1, 2, 3);

1 2 in 3 so PARAMETRI.

Pokličeš jih tako, da dodaš oklepaje in parametre (lahko tudi ne).

# Libraries

Funkcije pridejo znotraj paketov, libraries, modules, whatever.

<stdio.h>
<time.h>
...

glej [ibm](https://www.ibm.com/docs/en/i/7.5?topic=extensions-standard-c-library-functions-table-by-name)
## <stdlib.h>

- srand:
- rand: 

## <math.h>

Matematične funkcije.

- ceil: vzame katerokoli število in zaokroži navzgor.
- floor: vzame katerokoli število in zaokroži navzdol.
- log: vzame int in vrne naravni logaritem števila.

## <ctype.h>

- isupper: vzame char in vrne 1 ali 0 glede na to, ali je capital letter.
- toupper: vzame char in jo spremeni v capital letter.

# Definiranje funkcij

Potrebujemo *function signiature*, ki nam pove 3 stvari:

1. ime funkcije
2. število parametrov
3. return type
4. (function body)

To izgleda tako:

    returnType functionName (type1 parameter1, type2 parameter2)
    {
        // function body
    }

Return type je nek podatkovni tip (int, boolean, char...). Če ne vrne nič, samo naredi nekaj, napiši kot returnType `void`. V tem primeru ne pišeš `return`.

Prav tako, če funkcija ne sprejme parametrov, piši na njihovem mestu `void`, čeprav deluje tudi brez.

    void myFunc(void) {...}

V function body so ukazi, ki se zgodijo, ko pokličemo funkcijo.

# Function behaviour

Imamo funkcijo, ki nam vrne naključno število med 1 in 1000:

    int getRandom1000() {
	int random1000 = rand() % 1000 + 1;
	return random1000;
    }   

Kaj če bi hoteli, da nam vrne med 1 in 10.000 ali pa 100.000? Namesto, da definiramo nove funkcije, lahko uporabimo parametre, s katerimi določimo ravnanje funkcije.

Preprost primer:

    int seštej(int a, int b) {
	return a+b;
    }

Funkcija vrne vsoto int a in b. Rezultat se bo razlikoval glede na števili, ki ju podamo funkciji.

# Funkcije s pointerji

Ko funkcija prejme argument, naredi kopijo vrednosti in jo shrani v parameter spremenljivki. Vsi nadaljni ukazi se bodo izvedli na parameter spremenjivki in ne bodo vplivali na originalno podano vrednost.

Na vrednost spremenljivke je dobro vplivati direktno, ko želimo prihraniti na spominu, saj funkcija ne porabi prostora za ustvarjanje kopij. Na primer, ko delamo z [arrays](docs/arrays.md) ali z drugimi kompleksnimi strukturami.

## Kaj to pomeni

Naj bo to nek mali program:

    int main() {
	int a = 10;
        myFunc(a);
	printf("a izven funkcije: %d", a);

	return 0;
    }
    void myFunc(int a) {
    	a += 2;
    	printf("a znotraj funkcije: %d", a);
    }

Ko se to izvede, bo `myFunc` izpisal 12, medtem ko bo printf v main izpisal 10 - VREDNOST A SE NI SPREMENILA!!! To je super, v primeru, da je ne želimo spremeniti.

Če želimo vrednost spremenljivke spremeniti, podamo v funkcijo [pointer](/docs/pointers-and-memory.md), ki hrani adress spremenljivke.

Najprej torej naredimo pointer

    int *a_p = &a;

prilagodimo funkcijo

    void myFunc(int *a) {
    	*a += 2;
    	printf("a znotraj funkcije: %d", *a);
    }

in jo pokličemo s pointerjem

    myFunc(a_p);

Keep in mind, da ti ni treba **ustvarit** pointerja, lahko samo pošlješ adress spremenljivke v funkcijo:

    myFunc(&a);

# Function prototypes

Kot si že opazil, sem vse funkcije napisal nad main in jih nato definiral pod main. Lahko bi jih definiral tudi nam main, ampak imaš dve možnosti:

1. funkcijo inicializiraš nad main, da se shrani v buffer tekom izvajanja programa
2. ustvariš prototip funkcije pred main in nato definiraš kjerkoli hočeš

Prototip funkcije je vrstica, ki vsebuje signiature te funkcije:

    returnType functionName (type1 parameter1, type2 parameter2);

Tako compiler shrani ime in vse, da lahko preveri funkcijo tudi, če je definirama pod main.

Prav tako compiler ne potrebuje imen argumentov funkcij, dovolj je, če mu podaš samo tipe argumentov, a je bolj pregledno z imeni.

    returnType functionName (type1, type2);

---

Files:

- [basic](ch-8-functions/basic/main.c) 
- [user-defined](ch-8-functions/user-defined/main.c) 
- [random numbers](ch-8-functions/random-numbers/main.c) 
- [with pointers](ch-8-functions/functions-w-pointers/main.c) 
