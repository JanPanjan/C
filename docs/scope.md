# Scope

Scope ali obseg pomeni dostop do nekaterih spremenljivk in vrednosti znotraj določenega obsega ali delov programa. Spremenljivke, ki jih ustvarimo znotraj funkcij, niso dostopne izven _obsega_ funkcije.

V spodnjem primeru imamo dve spremenljivki z istim imenom. Njihova vrednost in pomen sta odvisna od obsega v katerem se nahajata.

    int someFunction() {
        int myVariableName = 20;
    }  

    int main() {
        char myVariableName[] = "10"; 
    }

Scope v bistvu ustvarimo s `{}` curly braces (if stavki, loops, funkcije...)
