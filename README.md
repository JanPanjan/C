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

### double to int

Spremenjlivkam lahko spremenimo podatkovni tip tekom izvajanja programa. Če imamo torej naslednji spremenljivki a in b:

    double b = 5.323;
    int a;

Lahko a spremenimo v double, tako da rečemo:

    a = b
    a = (int)b

Prva je implicitna (compiler ugiba v kateri tip mora spremeniti vrednost b), druga je implicitna (dobesedno povemo v kaj naj pretvori b vrednost).

### char to number

V ozadju je 'a' shranjen kot ASCII vrednost, ki je v bistvu številka 97 in 65 za 'A', zato lahko podaš char vrednost int in bo postal nek znak in int lahko podaš neko črko in bo postal številka znaka.

    char source = 'a';
    int target;
    
    target = (int)source; // 97

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

# operatorji

Osnovne matematične operacije ne bom coveral (+, -, /, *, %).
Increment: `a++`
Decrement: `a--`

Za vse lahko pišeš `+=`, `-=`, ...

## logični operatorji

`==`, `!=`, `>=`, `<=` in `!`.

"IN" se piše `&&`, "ALI" se piše `||`.

---

C izvede operacije po nekem zaporedju (ne slepo iz leve proti desni).
V tabeli so stopnje prednosti za operatorje:

| priority   | simbol    |
|--------------- | --------------- |
| 1   | ++   |
| 1   | --   |
| 1   | ()   |
| 2   | !   |
| 2 | (typecast) |
| 3 | * |
| 3 | / |
| 3 | % |
| 4 | + |
| 4 | - |
| 5 | <, <= |
| 5 | >, >= |
| 6 | !=, == |
| 7 | && |
| 8 | \|\| |
| 9 | all assignement operators |

## switch statements

Primer:
```
switch (grade) {
  case 9:
    printf("Freshman\n");
    break;
  case 10:
    printf("Sophomore\n");
    break;
  case 11:
    printf("Junior\n");
    break;
  case 12:
    printf("Senior\n");
    break;
  default:
    printf("Invalid\n");
    break;
}
```

- `grade`: izraz ali vrednost, ki se primerja z vsakim case
- `case value:`: če bo `grade == value`, se bo izvedlo vse pod tem casom
- `default`: basically _else_ statement

Pomembno je, da se expression ali variable znotraj `()` evaluira v nek **integralni podatkovni tip** (int, char, short, long, long long, enum); cela števila?

### razlika med if-else in switch

Prav tako so pomembni `break` ukazi po končanem case, s čimer preprečimo, da se izvedejo nadaljni casi (torej tisti ki se ujema in vsak naslednji, vključno z default bi se izvedli).

_If-else_ izvedejo samo en block of code.

## Ternary operatorji

*If-else* lahko pišemo na krajši način, brez if ali else. To je feature C-ja.

```
condition ? do something : do something else;
```

Torej "if condition je true, naredi to kar je za vprasajemm drugace naredi to kar je za dvopicjem".

Zgornje je identično temu:

```
if (condition) {
  // Do something
} else {
  // Do something else
}
```

Deluje kot nek *pipe operator*, zato lahko uporabiš tudi za print.

```
y > x ? printf("y je vecja stevilka. y = %d", y) : printf("x je vecja stevilka. x = %d", x);
```

# Loops aka zanke

## While

    while (nekaj je res) {
        delaj in vladaj
    }

## For

    for (int x; pogoj ki je res; increment x) {
        delaj in vladaj
    }

##
