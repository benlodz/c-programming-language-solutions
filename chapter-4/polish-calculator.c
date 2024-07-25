#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Kind of crazy how a leetcode medium problem is brought here: https://leetcode.com/problems/evaluate-reverse-polish-notation/
Anyway, this code isn't too bad and makes sense after reading it a bit. 
This is more of a template for the 4-3 to 4-10 */



#define MAXVAL 100 // max depth of the stack
#define MAXOP 100 // max size of an operator
#define NUMBER 0 // number was found
#define BUFSIZE 100 

int getop(char []);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);

int main() {
    int type;
    double op1;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                op1 = pop();
                op2 = pop();
                push(op1 + op2);
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("Error: Division by 0");
                }
                break;
            case '\n':
                printf("\t%.8g", pop());
                break;
            default:
                printf("error unknown command: %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0; // next free stack position or a pointer you could say
double val[MAXVAL]; // array is our stack

void push(double f) {
    if ( sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack is full, cannot push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack is empty. Nothing to pop\n");
        return 0.0; // program should crash here but implementation detail
    }
}

int getop(char s[]) {
    int i, c;

    // terminates upon white space
    while ((s[0] = c = getch()) == ' ' || c == '\t') {}
    s[1] = '\0';

    // if it's not a digit or a fractional part just return
    if (!isdigit(c) && c != '.' ) {
        return c;
    }

    i = 0;
    if (isdigit(c)) {
        /* At the start of the program we assigned s[0] for c, 
        this while loop simply puts c into s while advancing 
        the pointer.  */
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        // same idea except for the fractional part
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] == '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: buffer overflow\n");
    } else {
        buf[bufp++] = c;
    }
}

