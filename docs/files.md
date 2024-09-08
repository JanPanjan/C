# Opening files

Datoteke lahko prebereš tako, da ustvariš `FILE` pointer in uporabiš `fopen()`:

    FILE *f_p;
    f_p = fopen(filename, mode)

Filename je ime datoteke. Mode:

    - w: write
    - r: read
    - a: append

Da ustvariš file, uporabi w. Če ne obstaja, bo naredil nov file. File naredi v current directory, razen če podaš absolute path.

Ko končaš, kliči `fclose()`, ki zapre file.

# Writing files

Da izpišeš nekaj v datoteko, uporabi `fprint(filePointer, text)`.

    fprintf(f_p, "nekaj")

V primeru, da je file odprt z w, se vsebina nadomesti z novo vsebino. Če odpremo z a, se vsebina doda prejšnji.

# Reading files

Odpremo s fopen in r mode. Moramo ustvariti string velik toliko, da bo lahko shranjena vsebina datoteke v njej.

Da shranimo v string vsebino, uporabimo `fgets(string, size, pointer)`:

- string: kam shraniti vsebino
- size: max data to read (naj se matcha z velikostjo string-a)
- pointer: file pointer

`fgets` prebere samo prvo vrstico. Da preberemo vse, uporabimo npr. while loop:

    while(fgets(string, size, pointer)):
        printf("%s", string)

Če datoteka ne obstaja, ti fgets vrne NULL.
