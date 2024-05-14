#include <stdio.h>

/* Exercise 1-9: Write a program to copy  input to output, replacing a string of blanks with a single blank. */

main()
{
	int c, blank;

	blank = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{

			if (blank == 0)
			{
				putchar(c);
				blank = 1;
			}
		}
		if (c != ' ')
		{
			putchar(c);
			blank = 0;
		}
	}
}
