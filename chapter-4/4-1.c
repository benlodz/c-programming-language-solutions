#include <stdio.h>
#define MAXLINE 1000

/* Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if
there is none. */

int myline(char s[], int lim);
int strindex(char s[], char t[]);

int myline(char s[], int lim) {
    int i, c;
    i = 0;
    
    while (--lim > 0 && (c = getchar()) && ( c != EOF) && (c != '\n')) {
       s[i++] = c; 
    }
    if (c == '\n') {
        s[i++] = '\n';
    } 
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k;
    int rightmost_index = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') {
            rightmost_index = i;
        }
    }

    return rightmost_index;
}

int main() {
    char line[MAXLINE];
    char search_string[] = "beef";
    // index for rightmost occurance of string t or search string
    int res; 

    while (myline(line, MAXLINE) > 0) {
        res = strindex(line, search_string);
        printf("searched string: %s", line);
        printf("search string: %s\n", search_string);
        printf("rightmost index: %d\n", res);
    }

    return 0;
}
