#include <stdio.h>
#include <string.h>

void rev(char s[]);
void recursive(char s[], int i, int l);

int main() {
    char s[] = "hello world";
    printf("string: %s\n", s);
    rev(s);
    printf("after rev: %s\n", s);
} 

void rev(char s[]) {
    // first get lenth of the string
    int l = strlen(s);
    recursive(s, 0, l);
}

void recursive(char s[], int i, int l) {
    int c, j;

    j = l - (i + 1);
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        recursive(s, ++i, l);
    }
}