#include <stdio.h>

// 2-4: Write an alternative version of squeeze(s1, s2) that deletes each character in s1 
// that matches any character in s2.

void squeeze( char s1[], char s2[]);

int main() {
    char s1[] = "aabb";
    char s2[] = "b"; 

    printf("Before:\n s1: %s\t s2:%s\n", s1, s2);
    squeeze(s1,s2);
    printf("After:\n s1: %s\t s2:%s\n", s1, s2);
    // expected result: "aa"

    char s3[] = "abcd";
    char s4[] = "ac"; 

    printf("Before:\n s3: %s\t s4:%s\n", s3, s4);
    squeeze(s3,s4);
    printf("After:\n s3: %s\t s4:%s\n", s3, s4);
    // expected result: "bc"
}

void squeeze(char s1[], char s2[]) {
    // loop variables
    int i;
    int j;
    int k;
    char bad_char;

    // we loop through every character in s2
    for (i = 0; s2[i] != '\0'; ++i) {
        bad_char = s2[i];
        for (j = k = 0; s1[k] != '\0'; k++) {
            if (s1[k] != bad_char) {
                s1[j++] = s1[k];
            }
        }
        s1[j] = '\0'; 
    }
}