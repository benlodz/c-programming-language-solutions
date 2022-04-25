#include <stdio.h>

main() {
	int c,s;

	s = '\\';

	while ( (c = getchar()) != EOF) {
		if (c == '\t') {
			c = 't';
			putchar(s);
		}
		if (c == '\b') {
			c = 'b';
			putchar(s);
			/* backspace is Ctrl+H */
		}
		if (c == '\n') {
			c =  'n';
			putchar(s);
		}
		putchar(c);
	}
}

