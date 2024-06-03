#include <stdio.h>

/* Exercise 3-4: In a two complementary system representation, our version of itoa does not handle the largest
negative number. That is, the value of n = -(2^(WORDSIZE - 1)). Explain why not. Modifiy it to print the value correctly. */

/* First you need to know what two complementary system is, 
refer here: https://youtu.be/4qH4unVtJkE?si=cakbPRfNlyh5l_u2

In a two compliments system, for a signed 4-bit integer,
the largest positive integer you can get is ((2^3) - 1) = 7

In the context of the original itoa function, we need to convert n to a positive number, 
however we cannot store the largest negative number.

In order to remediate this we simply just get the absolute number and continue the loop until it hits 0 */

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

int abs(int n) {
    return (n > 0) ? n : -(n); 
}

void itoa(int n, char s[]) {
    int i, sign, digit;
    sign = n;
    i = 0;
    do {
        digit = n % 10;
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
int main() {
    char s100[100];
    char s256[100];

    itoa(100, s100);
    itoa(256, s256);

    printf("integer: %d, %s\n", 100, s100);
    printf("integer: %d, %s\n", 256, s256);

    return 0;
}