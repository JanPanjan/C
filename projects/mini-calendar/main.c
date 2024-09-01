#include <stdio.h>
#include <stdbool.h>

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

int main() {
    printf("to je true: %d\n", true);
    printf("to je false: %d\n", false);

    int leto = 2004;
    bool f_leto = is_leap_year(leto);
    printf("leto %d: %d\n", leto, f_leto);

    return 0;
}
