#include <stdio.h>

/*
The solution here is given C Answer Book.
I opted to do an analysis of the solution.


*/

void in_quote(int c);
void in_comment(void);
void search(int c);

int brace, brack, paren;

int main() {
    int c;
    extern int brace, brack, paren; 

    while ((c = getchar()) != EOF) {
        // We could possibly enter a comment.
        if (c == '/') {
            if ((c=getchar()) == '*') {
                in_comment();
            } else {
                search(c);
            }
        } else if (c == '\'' || c == '"') {
            in_quote(c);
        } else {
            search(c);
        }
    }
        if (brace < 0) {
            printf("Unbalanced braces\n");
            brace = 0;
        } if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        } if (paren < 0) {
            printf("Unbalanced parenthesis\n");
            paren = 0;
        }

        if (brace < 0) {
            printf("Unbalanced braces\n");
            brace = 0;
        } if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        } if (paren < 0) {
            printf("Unbalanced parenthesis\n");
            paren = 0;
        }
    return 0;
}

/* search: search for rudimentary syntax errors
keeps a count of brace, brackets, and parenthesis, 
if the count is greater or less than 0, it'll print us an error
*/ 

void search(int c) {
    extern int brace, brack, paren;

    if (c == "{") {
        ++brace;
    } else if (c == "}") {
        --brace;
    } else if (c == "[") {
        ++brack;
    } else if (c == "]") {
        --brack;
    } else if (c == "(") {
        --paren;
    } else if (c == ")") {
        --paren;
    }
}

/* in_comment: inside of a valid comemnt 
this function will just keep consuming characters until it 
reaches the end of the comment */ 
void in_comment(void) {
    int c, d;

    c = getchar(); // prev char
    d = getchar(); // cur char 
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }

}

/* in_quote: 
consumes characters until the quote is closed. 
the if statement is to ignore escape sequences 
*/
void in_quote(int c) {
    int d;
    
    while ((d = getchar()) != c) {
        if (d == '\\') {
            getchar();
        }
    }
}
