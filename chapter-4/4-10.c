#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100 // max depth of the stack
#define MAXOP 100 // max size of an operator
#define NUMBER 0 // number was found
#define BUFSIZE 100 
#define ALPHA 26 // length of the alphabet
#define MAXLINE 100

/* Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes getch and ungetch
unnecessary. Revise the calculator to use this approach. */

/* I think the solution here slides in quite well. 
We first modify getop by figuring out if we should get a new line or not. 
After have our pointer li that points to the line we got from getline.
After instead of calling getchar() or getch() in this case,
we simply just advance the pointer li. */


int getop(char []);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
int peak(void);
void duplicate(void);
void swap(void);
void clear(void);
int lineget(char line[], int limit);

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


int li = 0;
char line[MAXLINE];

int getop(char s[]) {
    int i, c;


    if (line[li] == '\0') {
        if (lineget(line, MAXLINE) == 0) {
            return EOF;
        } else {
            li = 0;
        }
    }

    // terminates upon white space
    while ((s[0] = c = line[li++]) == ' ' || c == '\t') {}
    s[1] = '\0';

    i = 0;

    // if it's not a digit or a fractional part just return
    if (!isdigit(c) && c != '.' && c != '-') {
        printf("Early exit, character is not a digit\n");
        return c;
    }

    // check if we're dealing with a negative number
    if (c == '-') {
        if (!isdigit(line[li + 1])) {
            return '-';
        }
    }

    if (isdigit(c)) {
        /* At the start of the program we assigned s[0] for c, 
        this while loop simply puts c into s while advancing 
        the pointer.  */
        while (isdigit(s[++i] = c = line[li++]));
    }
    if (c == '.') {
        // same idea except for the fractional part
        while (isdigit(s[++i] = c = line[li++]));
    }
    s[i] == '\0';
    li--;
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

int lineget(char line[], int limit) {
    int c, i;
    
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    return i;
}