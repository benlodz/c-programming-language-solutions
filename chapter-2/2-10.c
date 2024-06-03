#include <stdio.h>

/* Exercise 2-10: Rewrite the function lower, which converts the upper case letters to lower case, which a conditional
expression instead of if else */

int lower(int c) {
    // The distance between a to A is the distance to capitlize a letter so a - A gets us the distance in a negative and thus
    // the letter becomes lower
    return (c > 'A' ? c + ('a' - 'A') : c);
}

int main() {
    int c = 'B';
    int lower_c = 'b';
    printf("c: %c , res: %c\n", c, lower(c));
    printf("lower_c: %c , res: %c\n", lower_c, lower(c));
    return 0;
}