#include <stdio.h>
#define MAXLINE 100

int lineget(char line[], int maxline);
void copy(char to[], char from[]);

main() {
	int len;
	char line[MAXLINE];
	char clean[MAXLINE];


	while ( lineget(line,MAXLINE) != 0) {
		copy(clean,line);
		printf("%s",clean);
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
	int j = 0;

	while ((to[i] = from[j]) != '\0') {
		if (to[i] == '\t') {
			j++;
		} else if ( (to[i] == ' ') && (to[i-1] == ' ')) {
			j++;
		} else {
			i++;
			j++;
		}
	}	
}
