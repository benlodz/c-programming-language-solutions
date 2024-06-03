#include <stdio.h>

/* Exercise 3-1: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside),
Write a version with only one test inside the loop and measure the difference in run time. */

/* I think the wording of this problem is dumb and I got confused. 
Technically you do three tests in a binary search,
whether it'd be lower, higher, or the precise value
but according to the solution book, an if statement counts as one test,
which kind of makes sense. Oh well I guess, ¯\_(ツ)_/¯ */

int binary_search(int x, int v[], int N) {
    /*
    x: value to search for
    v: array to search, assumed to be in ascending order
    N: length of the array  
    */
    int l, r, mid;

    l = 0;
    r = N - 1;
    while (l <= r) {
        mid = (v[l] + v[r]) / 2;
        if (v[mid] > x) {
            r = mid - 1;
        } else if (v[mid] < x) {
            l = mid + 1;
        } else {
            break;
        }
    }
    if (v[mid] == x) return mid;
    return -1;
}


int main() {
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("x: %d, res: %d\n", 2, binary_search(2,v, 10));
    return 0;
}