#include <stdio.h>

/* 2-6: Write a function setbits(x, p, n, y) that returns x with the n bits 
that begin at position p set to the rightmost bits of y, leaving other bits unchanged. */

// In other words, change the bits starting at p to the rightmost bits of y

// My way
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned int n_mask = ~(~0 << n);
    unsigned int d = (p - n + 1);
    unsigned int y_bits = (y & n_mask) << d; // get n-bits and shift it 
    unsigned int x_mask = ~(n_mask << (d)); // move bits to p and invert it
    x = x & x_mask; // we then use AND to clear p-n bits
    return x | y_bits;
}

// this is hardly readable, thanks c-book lol
unsigned c_setbits(unsigned x, int p, int n, unsigned y) {
    return x & ~(~(~0 << n) << (p+1-n)) |
    (y & ~(~0 << n)) << (p+1-n);
}

int main() {
    printf("x: %u , y: %u, res: %u\n", 6, 12, setbits(6,4,3,12));
    printf("x: %u , y: %u, res: %u\n", 6, 12, c_setbits(6,4,3,12));
    return 0;
}