#include <stdio.h>
#include <string.h>

int htio(char s[]);
int int_pow(int x, int y);

int main() {

    char s[6] = "0xff";
    printf("The string %s to integer is: %d", s, htio(s));
    return 0;
}

int htio(char s[]) {
    /* 
    Assuming there is no mistake we can ignore the first two characters but,
    we can have a built in check for that.

    0xF = 15
    Hexadecimal numbers go backwards like binary numbers
    each column is (16^n * 15) times the amount in that column 

    so for 3 columns 
    256 | 16 | 1 since 16^3, 16^2, 16^1
    
    First we find the length of the string
    iterate backwards
    and then return the result
    */ 
    int str_len = strlen(s); 
    int place = str_len - 2;
    int i = 0;
    int res = 0;    

    for (i = 2; s[i] != '\0'; ++i) {
        int number = (s[i] - 'a');
        int column_val = (15 * (int_pow(16,place)));
        res += number * column_val;
        place--;
    }
    return res;
}

int int_pow(int x, int y) {
    int res = x;
    int i = 0;
    for (i = 0; i < y; ++i){
        res *= x;
    }
}