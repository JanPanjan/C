# C codecademy skill path

Link: [C_skill_path](https://www.codecademy.com/paths/c/tracks/welcome-to-the-learn-c-skill-path/modules/welcome-to-the-learn-c-skill-path/informationals/welcome-to-the-learn-c-skill-path)
# Uvod v C

Izdan leta 1972, vsi moderni operacijski sistemi so implementirani v C-ju, mislim, da je bil tudi Python zgrajen na C-ju, Linux jedra tudi, obstajajo tudi izpeljani jeziki C++ in C#. Prav tako je pogost v sistemih manjših gospodinjskih aparatov.

# Compiling

## Linux

Compilaš z GCC compilerjem.

    gcc script.c -o ime_za_compiled_script

Če podaš ime, ne bo `./a.out`, ampak `./ime.out`.

## Windows

Moraš installat nek gnu shit in potem samo rečeš

    cl script.c

Potem ti naredi `./main.exe`. Da se ti izvede program, runaš samo exe file.

# Sintaksa

1. include nek package
2. funkcija main je to kar se zgodi v programu (think java); prav tako mora bit lowercase
3. semmicollons ali ; na koncu vrstic
4. funkcija mora vrniti nekaj ker ni void (return 0 - no error)

`\n` je _escape sequence_, ki naredi newline
`\t` naredi tab (4 spaces)

`//` je single line komentar
`/**/` je multi line komentar

# Spremenljivke

## Podatkovni tipi v C-ju

Tip govori o tem _kakšen_ podatek je shranjen v spremenljivki. Ko enkrat declaraš spremenljivko z nekim imenom, ji ne moreš spreminjati podatkovnega tipa.

| type | opis | sintaksa |
| --------------- | --------------- | --------------- |
| int | cela števila | 1,2,3... |
| float | 6 decimalna števila | 2.1f, 2.34f, ... |
| double | 15 decimalna števila | 2.3456, 5.76543, ... |
| char | črka | 'a', 'b', 'c'... |
Shranjujejo neke podatke.

    // declare
    type name;

    // assign
    name = value;

    // initialyze
    type name = value;

Spremenljivke so inicialitzirane prvič, ko jim podamo vrednost.

## Pravila za poimenovanje

- lahko so iz velikih/malih črk, števil in `_`
- prvi znak nujno črka (case insensitive)
- ne sme biti **keyword** (npr. int, main, ipd.)

## Konstante

Spremenljivke, katerih vrednosti **ne moremo** spreminjati tekom izvajanja programa.

Deklariramo jih tako:

    const type name = value;

Priporočeno je, da imajo CAPITAL LETTERS v imenu.

## Spreminjanje podatkovnih tipov (casting types)

Spremenjlivkam lahko spremenimo podatkovni tip tekom izvajanja programa. Če imamo torej naslednji spremenljivki a in b:

    double b = 5.323;
    int a;

Lahko a spremenimo v double, tako da rečemo:

    a = b
    a = (int)b

Prva je implicitna (compiler ugiba v kateri tip mora spremeniti vrednost b), druga je implicitna (dobesedno povemo v kaj naj pretvori b vrednost).


## float VS double

Razlika v decimalnih mestih je razlika v prostoru, ki ga zavzameta. Ker float zavzame manj mest, to pomeni, da ni tako natančen kot double, a je zato hitrejši kar se tiče izvajanja programa.

Double je zato pomemben v znanstvenih izračunih ali medicinskih, povsod, kjer je pomembno, da smo čimbolj natančni.

>Float začne čudno sesštevati in zaokroževati pri 2.7 in 2.8

# printf funkcija

Definicija funkcije:

    printf("string to display", [list of optional parameters])

Če hočeš uporabiti vrednosti spremenljivk znotraj printf, moraš pisati `%...` in za vejico ime spremenljivke.

| simbol | type |
| -------------- | --------------- |
| %d, %i    | int |
| %f | float in double |
| %c | char |

