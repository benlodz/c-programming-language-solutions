#include <stdio.h>

#define MAXLINE 100
#define TABSTOP 5

/* 
 * My justification for this is because the amount of space a tab 
 * takes is dependent on the font. So, just to make it simple, I
 * made it a, "symbolic parameter." 
 * When I originally did this exercise, I just replaced tab with 5 spaces
 * without any awareness of what a "tab" really is. Now after a quick
 * google search, I understand how tabstops work. Not that it's actually
 * super useful information I guess.
 */

void detab();

char input[MAXLINE];
char buffer[MAXLINE];

char c;

main() {
	extern char input[];
	extern char c;

	while (c != EOF) {
		detab();
	}

	return 0;
}

void detab() {
	extern char input[];
	extern char c;
	extern char buffer[];
	int i, j, k;

	for (i = 0; i < (MAXLINE-1) && (( c = getchar() ) != EOF ) && c != '\n'; i++) {
		input[i] = c;
	}

	if (c == '\n') {
		input[i] = c;
		i++;
	}

	input[i] = '\0';

	i = 0;
	j = 0;

	while ( (buffer[i] = input[j]) != '\0') {
	       if (buffer[i] == '\t') {
		       for (k = 0; k < ( TABSTOP - ( j % TABSTOP)); k++) {
			       buffer[i] = ' ';
			       i++;
		       }
		       j++;
	       } else {
		       i++;
		       j++;
	       }
	}


	printf("%s",buffer);

}




