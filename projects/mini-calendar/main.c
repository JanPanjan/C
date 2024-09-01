#include <stdio.h>
#include <stdbool.h>

/// funkcija preveri, če je dano leto prestopno
bool is_leap_year(int year);
/// funkcija doda dano število dni danemu datumu
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add);

// array za dni v mesecu. 0 je placeholder
int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31};

int main() {
    /*
    int year;
    printf("vnesi leto med 1800 in 10.000:\n");
    scanf_s("%d", &year);

    if (is_leap_year(year) == true) {
        printf("Prestopno leto.");
    } else {
        printf("Ni prestopno leto.");
    }
    */

    int mm, dd, yy, days_left_to_add;

    printf("vnesi datum med leti 1800 in 10.000 v obliki mm dd yy in ");
    printf("povej koliko dni naj se doda\n");
    scanf_s("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);

    printf("vnešeni datum: %d-%d-%d\n", mm, dd, yy);
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("zamik za %d dni\n", days_left_to_add);
    printf("nov datum: %d-%d-%d\n", mm, dd, yy);

    return 0;
}

bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    int days_left_in_month;

    // dodajamo dni dokler jih ne zmanjka
    while (days_left_to_add > 0) {
        // koliko dni lahko dodamo trenutnemu mesecu?
        // vsem dnevom odštejemo trenutni dan
        // npr. marec ima 31 dni. danes je 21. ostane 10 dni
        days_left_in_month = days_in_month[*mm] - *dd;

        // če je prestopno leto, ima februar 1 dan več
        // število dni v mesecu se poveča
        if (is_leap_year(*yy) && *mm == 2) {
            days_left_in_month++;
        }

        // če je preveč dni za dodat, se bodo dnevi prenesli v naslednji mesec
        // če je dovolj dni, dodamo datumu
        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= days_left_in_month - 1;

            // menjamo dan na 1. v mesecu
            *dd = 1;

            if (*mm == 12) {
                // gremo na januar v novo leto
                *mm = 1;
                (*yy)++;
            } else {
                // gremo v naslednji mesec
                (*mm)++;
            }
        } else {
            // dodamo dneve
            *dd += days_left_to_add;
            // resetiramo days_left_to_add
            days_left_to_add = 0;
        }
        
    }
}
