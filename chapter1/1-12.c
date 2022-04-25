#include <stdio.h>

main() {
	int c;
	int out;
	out = 0;

	while ( (c = getchar()) != EOF) {
		if ( (c == ' ' || c == '\t') ) {
			c = '\n';
			if (out != 1) {
				putchar(c);
				out = 1;
			}
		} else {
			putchar(c);
			out = 0;
		}
	}
}

