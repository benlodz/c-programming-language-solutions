#include <stdio.h>

/* Exercise 3-6: Write a version of itoa that accepts three arguments instead of two. The third argument is a 
minimum field width; the converted number must be padded with blanks on the left if necessary to make it
wide enough. */


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

void itoa(int n, char s[], int w) {
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = (n % 10) + '0';
    } while ((n /= 10) > 0);

    // slight modification here for next loop
    if (sign < 0) {
        s[i] = '-';
    }

    /* i at this point represents the length of string
    so dist represents the amount of padding we need. */
    int dist = w - i;
    int m = i;
    i += dist;
    for (; m >= 0; m--) {
        s[m + dist] = s[m];
    } 
    for (--dist; dist >= 0; dist--) {
        s[dist] = '-';
    }

    s[++i] = '\0';
    reverse(s);
}

int main() {
    printf("Converting 12345 to a string with a min field width of 10.\n");
    char s[100];
    itoa(12345, s, 10);
    printf("converted:%s\n", s);
    return 0;
}