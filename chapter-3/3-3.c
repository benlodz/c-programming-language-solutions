#include <stdio.h>

/* Exercise 3-3: Write a function expand(s1, s2) that expands shorthand notation like a-z in string s1
into the equivalent complete list abc..xyz in s2. Allow for letters of either case and digits,
be prepared to handle cases like a-b-c- and a-z0-9 and -a-z. Arrange that a leading or trailing - 
is taken literally  */


// this solution is given by the C Answer book 
void expand(char s1[], char s2[]) {

    int i, j;
    char c;
    i = j = 0;

    while ( (c = s1[i++]) != '\0') {
        // check if we have a valid pattern like a-z
        if (s1[i] == '-' && s1[i+1] > c) {
            i++;
            while (c < s1[i]) {
                s2[j++] = c++;
            }
        } else {
            // just copies c into s2
            // As the question correctly points out, "take it literally"
            s2[j++] = c;
        } 
    }
    s2[j] == '\0';
}

int main() {
    char s1[] = "a-z";
    char s2[] = "1-9";
    char s3[] = "a-z1-9";
    char s4[] = "-a-z";

    char e1[100];
    char e2[100];
    char e3[100];
    char e4[100];

    expand(s1,e1);
    expand(s2,e2);
    expand(s3,e3);
    expand(s4,e4);

    printf("s1: %s, e1: %s\n", s1, e1);
    printf("s2: %s, e2: %s\n", s2, e2);
    printf("s3: %s, e3: %s\n", s3, e3);
    printf("s4: %s, e4: %s\n", s4, e4);
    
    return 0;
}