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
- `case value:`: če bo `grade == value`, se bo izvedlo vse pod tem case-om
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
