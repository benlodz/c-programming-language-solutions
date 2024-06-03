#include <stdio.h>

/*
Exercise 3-2: Write a function escape(s, t) that converts characters like newline and tab into visible escape
sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other directions as well,
converting escape sequences to real characters.
*/

// why is t -> s when the order of the arguments is s and t..
// Very silly.
void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

// Same idea except turn sequences into the actual characters 
void revEscape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[i+1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char t[100] = "test\tstring\n";
    char s[100];
    char s_rev[100];

    printf("initial string: %s\n", t);
    escape(s,t);
    printf("After running escape function: %s\n", s);
    revEscape(s_rev, s);
    printf("After running reverse escape function: %s\n", s_rev);
    return 0;
}