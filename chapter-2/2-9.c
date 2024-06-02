#include <stdio.h>

/*
Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost bit in x. Explain why and 
use this observation to write a faster version of bitcount

The reason it deletes the rightmost bit is because by subtracting - 1 you will invert the rightmost bit, 
an inverted bit AND'd on itself will always produce 0 since they're opposite. Thus deleting the bit.
*/

int bitcount(unsigned int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n &= (n-1);
    }
    return count;
}

int main() {
    printf("n: %u, res: %d\n", 14, bitcount(14));
    // the result here should be 3
    return 0;
}
