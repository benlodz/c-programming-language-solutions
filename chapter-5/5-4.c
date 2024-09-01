#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char s[] = "foobar";
    char t[] = "bar";
    char z[] = "car";

    printf("Strings:%s\t%s\t%s\n", s, t, z);
    printf("does t occur at the end of s? %d\n", strend(s,t));
    printf("Does z occur ar the end of s? %d\n", strend(s,z));
    return 0;
}

int strend(char *s, char *t) {
    // get the length of t
    int t_length = 0;
    while (*t != '\0') {
        t_length++;
        t++;
    }

    int s_length = 0;
    while (*s != '\0') {
        s_length++;
        s++;
    }

    /*In order for t to occur at s, we need enough
    characters in s for t */
    if (t_length > s_length)
    return 0;

    t -= t_length;
    s -= t_length;

    while (*t != '\0') {
        if (*s != *t) {
            return 0;
        }
        t++;
        s++;
    }

    return 1;
}