#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);


/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a
character back on the input. */



int getint(int *pn) {
    int c, sign;

    // skips / strips whitespace
    while (isspace(c = getch()))
    ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int d = c;
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF) {
                ungetch(c);
            }
            printf("Only got sign.\n");
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("buffer overflow.\n");
    } else {
        buf[bufp++] = c;
    }
}

int main() {
    int x; 
    while (getint(&x) != EOF) {
        printf("Number we got: %d\n", x);
    }
    return 0;
}