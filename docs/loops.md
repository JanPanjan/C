# Loops aka zanke

## While

Pogoj je preverjen PRED izvajanjem ukazov.

    while (nekaj je res) {
        delaj in vladaj
    }

## do-while

Pogoj je preverjen PO izvajanju ukazov. Priročno, ko hočeš, da program naredit nekaj _vsaj enkrat_, preden pogleda pogoj.

    do {
        // Statement(s)
    } while (condition);

## For

Uporabno, ko vemo točno kolikokrat se mora izvesti nekaj (prihrani čas).

    for (int x; pogoj; x++) {
        // Statement(s)
    }

## break in continue

Vplivata na najbolj notranji loop (če imamo nested loops).

### break

Uporabno, da exitamo loop v rekurzivnih funkcijah ponavadi. Z break ukazom jih kontroliramo.

### continue

Preskoči vse nadaljne ukaze v trenutni iteraciji zanke in preskoči na naslednji krog.

Pri while loop moraš pred continue incrementat value, drugače bo bil infinite loop. Pri for ni potrebno, saj se izvede increment avtomatsko.

