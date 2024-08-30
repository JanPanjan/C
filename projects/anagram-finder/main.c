#include <stdio.h>
#include <string.h>

int main() {

    // 1. Create two integer arrays called counter1 and counter2. Initialize both arrays with four zeros each.
    int counter1[] = {0, 0, 0, 0};
    int counter2[] = {0, 0, 0, 0};

    // 2. We will check if the following two strings are anagrams:
    char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
    char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

    // 3. First, create a for loop to loop through the string. Use strlen() to find the length of the string.
    // ‘a’ - increment counter1[0] by one.
    // ‘b’ - increment counter1[1] by one.
    // ‘c’ - increment counter1[2] by one.
    // ‘d’ - increment counter1[3] by one.
    // If we encounter a space, we ignore it.
    for (int i = 0; i < strlen(s1); i++) {
        switch (s1[i]) {
            case 'a':
                counter1[0]++;
                break;
            case 'b':
                counter1[1]++;
                break;
            case 'c':
                counter1[2]++;
                break;
            default:
                counter1[3]++;
                break;
        }
    }

    for (int i = 0; i < strlen(s2); i++) {
        switch (s2[i]) {
            case 'a':
                counter2[0]++;
                break;
            case 'b':
                counter2[1]++;
                break;
            case 'c':
                counter2[2]++;
                break;
            default:
                counter2[3]++;
                break;
        }
    }

    // We need a flag that we can use to determine if there is a mismatch in the two counters.
    // First, create an integer variable called flag and set it to 0.
    // - The flag will be set to zero if there is no mismatch in the
    // counters
    // - The flag will be set to one if there is a mismatch in the counters
    int flag = 0;

    // Create an empty for loop that you will use to loop through both counters.
    // In the loop, change the flag variable’s value to 1 if a mismatch is encountered.
    for (int i = 0; i < 4; i++) {
        if (counter1[i] != counter2[i]) {
            flag = 1;
        }
    }

    // If the two strings are anagrams, print “Anagram!”. If they are not, print “Not Anagram!”
    flag == 1 ? printf("Not Anagram!\n") : printf("Anagram!\n");

    return 0;
}
