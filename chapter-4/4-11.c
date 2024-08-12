
/* Exercise 4-11. Modify getop so that it doesn’t need to use ungetch. Hint: use an internal static variable. */

// instead of pasting the whole source file, I opted to just have the modified function here.




int getop(char s[]) {
    int i, c;
    static prev;

    if (prev == 0) {
        c = getch()
    } else {
        c = prev;
        prev = 0;
    }

    // terminates upon white space
    while ((s[0] = c) == ' ' || c == '\t') {}
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
        prev = 0;
    }
    return NUMBER;