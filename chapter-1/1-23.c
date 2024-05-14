#include <stdio.h>

// Exercise 1-23 Remove all comments from a C program.

// This solution assumes that there is no syntax errors when it comes to the string

#define MAXLINE 100
#define INSIDE 0
#define OUTSIDE 1

int line_get(char s[], int lim);

int main() {
    char line[MAXLINE];
    int len;
    int status = INSIDE;

    while ((len = line_get(line, MAXLINE)) > 0) {
        // Skip single line comment
        if (line[0] == '/' && line[1] == '/') {
            continue;
        }
        // multi line comment
        else if (line[0] == '/' && line[1] == '*') {
            // Continue until we find the end of the comment.
            while (line[0] != '*' && line[1] != '/') {
                len = line_get(line, MAXLINE);
            }
        } else {
            printf("%s", line);
        }
    }
    return 0;
} 
        
int line_get(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}