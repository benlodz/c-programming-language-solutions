#include <stdio.h>

#define MAXLINE 100
#define MAXLEN 50
#define MAXCOL 20

/* Exercise 1-22: Write a program to fold input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. */

int line_get(char s[], int lim);

int main() {
	char line[MAXLINE];
	int len;
	int i;
	
	while (( (len = line_get(line, MAXLINE)) > 0)) {
		if (len > MAXLEN) {
			for (i = 0; i < len; ++i) {
				if (line[i] == ' ' || line[i] == '\t') {
					putchar('\n');
					// Get to the next non blank character.
					while (line[i] == ' ' || line[i] == '\t') {
						++i;
					}
				} else if (i % MAXCOL == MAXCOL - 1) {
					putchar('\n');
					++i;
				} 
				putchar(line[i]);
			}
		} else {
			printf("%s", line);
		}
	}
}

int line_get(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim -1 && (c=getchar()) != '\n' && c != EOF; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}