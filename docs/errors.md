# Errors

Napake delimo na več vrst, a se vse družijo glede na eno lastnost - vse motijo delovanje programa.

## Compile-time errors

Napake ob izvajanju. Napake, ki jih najde compiler.

Lahko so syntax ali semantic errors.

### Syntax

Sfaljen znak or something.

    printf("tvoja mama\n";

### Semantic

Ukazi so slovnično pravilni, a se ne izvedejo, tako kot želi programer.

    a + b = c;   // Error: value required as left operand of assignment

    int i;
    i = i + 2;   // Error: use of a un-initialized variable

## Link-time errors (linker errors)

Napake, ki jih najde _linker_, ko proba združiti object files v delujoč program.

Npr. če pišeš **Main()** namesto **main()**.

## Run-time errors

Napake, ki jih povzročijo pogoji ob izvajanju.

Npr. division by zero ali pa integer overflow ()

## Logic errors

Napake ob sestavljanju algoritmov in logike programa. 

Ne vplivajo na izvajanje programa, le na njegovo zaželjeno aktivnost.
