#include <stdio.h>

/* Exercise 3-5: Write the function itob(n, s, b) that converts the integer n into 
a base b character representation in the string s. In particular, itob(n, s, b) formats
s as a hexidecimal integer in s */

// Solution is from the C-Answer book, quite beautiful if I say so myself.

// helper functions 
void reverse(char s[]) {
    // reverses string in place
    int i, j;
    char temp; 
    int len = 0;

    for (i = 0; s[i] != '\0'; i++) {
        len++;
    }

    for (i = 0, j = (len - 1); i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}



void itob(int n, char s[], unsigned int b) {
    int i, j, sign;
    // get sign fairly standard
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        j = n % b; // Get least signficant digit in said base
        /* if base is <= 10 we correctly print just digits, otherwise we can pull letters*/
        s[i++] = (j <= 9) ? j + '0' : j + 'a'-10;
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    } 
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[1000];
    printf("Converting 100 to base 2, base 16, and base 5\n");
    itob(100, s, 2);
    printf("Base 2 conversion: %s\n", s);
    itob(100, s, 16);
    printf("Base 16 conversion: %s\n", s);
    itob(100, s, 5);
    printf("Base 5 conversion: %s\n", s);
    return 0;
}

