#include <stdio.h>

int my_any(char s1[], char s2[]);

int main() {
    char s1[] = "aab";
    char s2[] = "b";
    printf("s1:%s\ts2:%s, first occurance of s2 in s1 is at:%d\n", s1, s2, my_any(s1,s2));

    char s3[] = "fog";
    char s4[] = "gof";
    printf("s3:%s\ts4:%s, first occurance of s4 in s3 is at:%d\n", s3, s4, my_any(s3,s4));
}

int my_any(char s1[], char s2[]) {
    int i, j;
    char cur;

    // loop through s2
    for (i = 0; s2[i] != '\0'; ++i) {
        cur = s2[i];
        for (j = 0; s1[j] != '\0'; ++j) {
           if (s1[j] == cur) {
            return j;
           } 
        }
    }

    return -1;
}