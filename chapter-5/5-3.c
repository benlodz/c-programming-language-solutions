#include <stdio.h>

void ptr_strcat(char *s, char *t);

int main() {
    char s[] = "foo";
    char t[] = "bar";
    printf("%s\n", s);
    ptr_strcat(s, t);
    printf("%s\n", s);
}

void ptr_strcat(char *s, char *t) {
    // get to the end of s
    while (*s != '\0')
    s++;
    while (*t != '\0') {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}