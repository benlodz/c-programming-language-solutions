#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getfloat(float*);
/* Exercise 5-2. Write getfloat, the floating-point analog of getint. 
What type does getfloat return as its function value? */

int main(void) {
    float x;
    while (getfloat(&x) != EOF) {
        printf("Got this float: %f", x);
    }
    return 0;
}

int getfloat(float *pn) {
    int c, sign;

    // skip whitespace 
    while (isspace(c = getch()));

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int d = c;
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF) {
                ungetch(c);
            }
            printf("Only got sign.");
            return 0;
        }
    }

    for (*pn = 0.0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
    }
    float power;
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
    }

    *pn *= sign / power;

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
        printf("Buffer overflow");
    } else {
        buf[bufp++] = c;
    }
}