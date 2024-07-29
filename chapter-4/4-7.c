#include <string.h>

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf
and bufp, or should it just use ungetch? */

// Instead of copy the whole source as before, I'm just providing the function

void ungets(char s[]) {
    int len = strlen(s);

    while (len > 0) {
        ungetch(s[--len]);
    }
}