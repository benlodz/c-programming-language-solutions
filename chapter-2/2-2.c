#include <stdio.h>

#define MAXLINE 1000

// Exercise 2-2: Write a loop equivalent to the for loop above without using && or ||. 

/* 
for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c!= EOF; ++i){
    s[i] = c;
}
*/

int main() {
    enum boolean {YES, NO};
    char loop = YES;
    char c, line[MAXLINE];
    int i = 0;
    while (loop == YES) {
       if (i > MAXLINE - 1) {
        loop = NO;
       } else if ((c=getchar()) == '\n'){
        loop = NO;
       } else if (c == EOF) {
        loop = NO;
       } else {
        line[i] = c;
        ++i;
       }
    }
    printf("%s\n", line);
    return 0;
}