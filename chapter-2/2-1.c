#include <stdio.h>
#include <limits.h>

/* Exercise 2-1: Write a program to print the ranges of char, short, int, long, both signed and unsigned from standard headers. */

// Repetitive, boring, and the book at this point doesn't mention u or l specifier.
int main()
{
    printf("signed-char-min: %d\n", SCHAR_MIN);
    printf("signed-char-max: %d\n", SCHAR_MAX);
    printf("signed-short-min: %d\n", SHRT_MIN);
    printf("signed-short-max: %d\n", SHRT_MAX);
    printf("signed-int-min: %d\n", INT_MIN);
    printf("signed-int-max: %d\n", INT_MAX);
    printf("signed-long-min: %ld\n", LONG_MIN);
    printf("signed-long-max: %ld\n", LONG_MAX);

    printf("The min of all unsigned numbers is 0.\n");
    printf("unsigned-char-max: %u", UCHAR_MAX);
    printf("unsigned-short-max: %u", USHRT_MAX);
    printf("unsigned-int-max: %u", UINT_MAX);
    printf("unsigned-long-max: %lu", ULONG_MAX);
}