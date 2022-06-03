#include <stdio.h>

#define TABSTOP 5
#define MAXLINE 100

void entab();

char c;

int main() {
	extern char c;
	while ( c != EOF) {
		entab();
	}
	return 0;
}

void entab() {

	/* gets a string from standard in and stores it */ 
	extern char c;
	char input[MAXLINE];
	char buffer[MAXLINE];
	int i, j;

	for (i = 0; i < MAXLINE-1 && ( ( c = getchar()) != EOF ) && c != '\n'; i++) {
		input[i] = c;
	}

	if (c == '\n') {
		input[i] = '\n';
		i++;
	}

	input[i] = '\0';

	/*replaces blanks with tabs if there is enough spaces */

	int spaceCounter = 0;
	for (i = j = 0; input[j] != '\0'; i++,j++) { 
		buffer[i] = input[j];
		if (input[j] == ' ') { 
			spaceCounter++; 
			/* this checks if the current index at the input is a tab stop
			 * every tab stop is at 5 columns so to compensate for the 
			 * 0-index I increment by 1. The second condition if there
			 * is more than 1 zero. If there is, just let it be, no need
			 * for a tab.
			 */
			if ( ( ( (j+1) % TABSTOP) == 0) && spaceCounter > 1 ) {
				/*the index on the buffer is changed to 
				 * the first space so for 'aaa  ' this will put
				 * i at 3. */
				i = i - spaceCounter + 1;
				buffer[i] = '\t';
				spaceCounter = 0;
			}
		} else {
			spaceCounter = 0;
		}
	}
	buffer[i] = '\0';	
	printf("string:%s",buffer);


}

