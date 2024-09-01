# Structures

Spadajo med _derived_ data types, kot [arrays](/docs/arrays.md) in [pointers](/docs/pointers-and-memory.md). To so [podatkovni tipi](docs/variables.md) zgrajeni na podlagi primitivnih, osnovnih tipov (int, double, char...). 

Structures omogočajo programerju, da ustvari svoje podatkovne tipe (razrede basically). Olajšajo delo s kompleksnimi strukturami.

# Struktura struktur

Primer struct:

    struct Bottle {
        char *name;
        int maxCapacity;
        int currentCapacity;
    };

Spremenljivke, ki jih definiraš znotraj struct se imenujejo _member variables_ in so lahko katerikoli osnovni tip (ali derived).

Member variables morajo biti samo **declared** in ne initialized (vrže error).

# Inicializacija struktur

Zgornjo strukturo inicializiraš tako, da ustvariš spremenljivko tipa Bottle in ji znotraj `{}` podaš vrednosti v vrstnem redu.

    struct Bottle b1 = {"sdfg", 23, 0};

Lahko jih podaš tudi v neurejenem vrstnem redu.

    struct Bottle b1 = {
        .maxCapacity = 24,
        .name = "dfsg",
        .currentCapacity = 0
    };

# Zakaj uporabljamo structures

Structs uporabljamo, da se znebimo preveč clusterfucka v skripti z ustvarjanjem novih spremenljivk. Lahko bi uporabili arrays, ampak so limited na isti tip vrednosti. 

Tu pridejo na vrsto structs, katerim lahko definiramo spremenljivke različnih vrednosti in ostanemo zapakirane znotraj te strukture.

Tako kot je bil primer osebe zgoraj, namesto da hranimo spremenljivke:

    int starost = 21;
    char ime[20] = "Jan";
    char priimek[20] = "Panjan";

Lahko naredimo struct in tako posledično definiramo več oseb brez da nastane clusterfuck:

    struct Oseba {
        int starost;
        char ime[20];
        char priimek[20];
    };

    struct Oseba jan = {21, "Jan", "Panjan"};

# Dostopanje do elementov v structs

Z operatorjem _dot notation_ lahko dostopamo in delamo z vrednostmi, ki so del member variables v strukturi.

To naredimo tako:

    objektTipaStruct.memberVariableName

Če nadaljujemo zgornji primer, zdaj lahko spremenimo starost npr:

    jan.starost = 22;    

Enako lahko naredimo znotraj printf:

    printf("star sem %d let", jan.starost);

Prav tako lahko najprej declaraš strukturo in nato inicializiraš z dot operatorjem:

    struct Oseba anja;

    anja.ime = "Anja";
    anja.starost = 23;
    anja.priimek = "Panjan";

# Structures and pointers

Tudi s svojimi strukturami lahko uporabljaš [pointers](/docs/pointers-and-memory.md). Najprej ustvariš objekt in nato ustvariš pointer, ki kaže na ta objekt.

    struct Oseba miha = {28, "Miha", "Panjan"};
    struct Oseba* miha_p = &miha;

Da dostopaš do vrednosti v pointerju, pišeš:

    (*miha).starost; 
    (*miha).ime; 
    (*miha).priimek; 

Drugi način dostopanja do vrednosti, je z _arrow_ notacijo, ki izgleda tako:

    miha_p->ime;
    miha_p->starost;
    miha_p->priimek;

Drugi način naj bi bil bolj berljiv, ampak personal preference.

# Structures and functions

Prav tako lahko pošljemo structs in pointerje structs v funkcije. Ker se ustvarijo kopije (glej [pointers-and-memory](/docs/pointers-and-memory.md)), postane memory usage velik risk. Prav tako spremebe podatkov ne bodo spremenile originalnih podatkov v strukturi.

Zaradi tega je bolj priročno uporabljati pointerje structs, ki hranijo adress member variables od structs in vplivajo na originalno strukturo.


