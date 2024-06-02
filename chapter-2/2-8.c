#include <stdio.h>

// Exercise 2-8: Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n positions

/*
This problem is kind of confusion at first because what does rotation even mean?

rotation of 3 bits
123456 -> 456123
much more easier to understand if you think of it like a wheel.
*/

int wordlength() {
    int length = 0;
    unsigned int n = ~0;
 
    while (n != 0) {
        ++length;
        n = n >> 1;
    }
    printf("length of unsigned integer:%d\n" , length);
    return length;
}


unsigned int rightrot(unsigned int x, int n) {
    int rbit;
    int length = wordlength();

    while (n-- > 0) {
        rbit = (x & 1) << (length - 1);
        x = x >> 1; // lop off last bit
        x = x | rbit;
    }
    return x;
}

int main() {
    printf("x: %u, res: %u\n", 15, rightrot(15,3));
    printf("x: %u, res: %u\n", 1, rightrot(1,1));

    /* 
    result: x: 1, res: 2147483648
    on my machine an unsigned integer is 32 spaces long.
    Therefore having the bit set at the leftmost column will be 2^(32-1)
    2^31= 2147483648 
    so our rightrot works correctly 
    */ 
   return 0;
}
