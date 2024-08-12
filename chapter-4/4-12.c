#include <stdio.h>
#include <string.h>

/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by
calling a recursive routine. */

void itoa(char s[], int n);
int dfs(char s[], int n);

int main() {
    int x = 100;
    char s[100];
    itoa(s, x);
    printf("integer: %d\n string:%s\n", x, s);
    int y = 4569;
    itoa(s, y);
    printf("integer: %d,\n string: %s\n", y, s);
}

void itoa(char s[], int n) {
    // edge case what if we have a just '0'
    if (n == 0) {
        s[0] = '0';
        s[1] = '\0';
    }
    // 
    int i = dfs(s, n);
    s[i] = '\0';
}

int dfs(char s[], int n) {
    /* i represents the index where to place the character in s*/
    if (!n) {
        return 0;
    } else {
        int r = n % 10;
        int i = dfs(s, n / 10);
        s[i] = r + '0';
        return i + 1;
    }
}