#include <stdio.h>
#define MAXLINE 100

int lineget(char line[], int maxline);
void copy(char to[], char from[]);

main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ( (len = lineget(line,MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest,line);
		}
	}
	
	
	if (max > 0) {
		printf("%s",longest);
	}

	return 0;
}

int lineget(char s[], int lim) {

	int c, i;
	
	for (i = 0; i < lim -1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i = 0;
	/*
	 * the solution here was put a paranthesis 
	 */
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
