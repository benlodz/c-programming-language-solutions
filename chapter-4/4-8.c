int c;
int buf = -1;

/* Exercise 4-8. Suppose that there will never be more than one character of pushback. 
Modify getch and ungetch accordingly. */


int getch(void) {
    if (buf != -1) {
        int res = buf;
        buf = - 1;
        return res;
    }
}

void ungetch(int c) {
    if (buf != -1) {
        printf("Error buffer full\n");
    } else {
        buf = c;
    }
}