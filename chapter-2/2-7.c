#include <stdio.h>

// Exercise 2-7: Write a function invert(x,p,n) that returns x with n bits inverted, starting at position p.

unsigned int inverted(unsigned int x, int p, int n) {
    // first let's get n bits from p
    unsigned int n_mask = ~(~0 << n);
    unsigned int d = p - n + 1;
    unsigned int inverted_bits = (((~x) >> d) & n_mask); // get bits and then invert those bits

    // clear n bits from p in x
    x = x & ~(n_mask << d);
    return x | inverted_bits; // Doing an OR with the inverted bits will set those bits to whatever the inverted bits may be
}

// solution from the C-book to juxtapose; much simpler
unsigned int c_inverted(unsigned int x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 -n));
}

int main() {
    printf("x: %u inversion: %u\n", 14, inverted(14,2,2));
    printf("x: %u inversion: %u\n", 14, inverted(14,2,1));

    printf("x: %u inversion: %u\n", 14, c_inverted(14,2,2));
    printf("x: %u inversion: %u\n", 14, c_inverted(14,2,1));
}