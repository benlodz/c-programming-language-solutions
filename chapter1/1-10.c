#include <stdio.h>

/* Exercise 1-10: Replace backspaces, tabs, and newlines with the escape character. */

main()
{
	int c, s;

	s = '\\';

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			putchar(s);
			c = 't';
		}
		if (c == '\b')
		{
			putchar(s);
			c = 'b';
			/* backspace is Ctrl+H */
		}
		if (c == '\n')
		{
			putchar(s);
			c = 'n';
		}
		putchar(c);
	}
}
