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

