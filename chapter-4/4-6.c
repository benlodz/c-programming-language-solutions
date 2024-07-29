#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100 // max depth of the stack
#define MAXOP 100 // max size of an operator
#define NUMBER 0 // number was found
#define BUFSIZE 100 
#define ALPHA 26 // length of the alphabet

/* Exercise 4-6. Add commands for handling variables. (It’s easy to provide twenty-six variables with single-letter names.) Add
a variable for the most recently printed value. */

/* The solution here is quite simple but you need to pay attention.
the variable var stores the last thing seen in the loop, 
which is important because it stores the literal used in our array.

In addition, if we encounter a variable, we need to push it to the stack
when we're doing assignment, we're inadverently pushing the original 
variable to the stack. So during assignment we pop.  */

int getop(char []);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
int peak(void);
void duplicate(void);
void swap(void);
void clear(void);

int main() {
    int type;
    double op1;
    double op2;
    int c;
    char s[MAXOP];
    int var = 0;
    double v;

    double letters[ALPHA];
    int i;
    // set array initially to 0
    for (i = 0; i < ALPHA; i++) {
        letters[i] = 0.0;
    }
    


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
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '=':
                // assignment
                op1 = pop();
                printf("%g\n", op1);
                if ( var >= 'A' && var <= 'Z') {
                    letters[var - 'A'] = pop();
                }
                else {
                    printf("error: invalid variable");
                }
                break;

            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            case 'p':
                peak();
                break;
            case 'c':
                clear();
                break;
            case 'd':
                duplicate();
                break;
            case 'e':
                // e^x power
                push(exp(pop()));
                break;
            case 'o':
                // sin gets you the opposite side of a triangle so o
                push(sin(pop()));
            case 's':
                swap();
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    push(letters[type - 'A']);
                } else if (type == 'v') {
                    push(v);
                } else {
                    printf("error unknown command: %s\n", s);
                }
                break;
        }
        var = type;
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
    double res;
    if (sp > 0) {
        res = val[--sp];

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

    i = 0;

    // if it's not a digit or a fractional part just return
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    // check if we're dealing with a negative number
    if (c == '-') {
        s[++i] = c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return '-';
        }
    }

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

int peak(void) {
    // remember sp represents next free position in our stack
    if (sp >= 2) {
        printf("first element: %f\n", val[sp - 1]);
        printf("second element: %f\n", val[sp - 2]);
    } else {
        printf("error: no enough vals in the stack\n");
    }
}

void swap(void) {
    // we need at least two elements in our stack to swap
    if (sp >= 2) {
        double top = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = top;
    } else {
        printf("error: no enough vals in the stack\n");
    }
}

void clear(void) {
    // clear our stack
    sp = 0;
}

void duplicate(void) {
    double top = pop();
    push(top);
    push(top);
}