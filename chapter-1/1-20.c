#include <stdio.h>

/* Exercise 1-20: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
   Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? */

#define TABINC 8 /* tab increment size */

main() {
	int c, nb, pos;
	nb = 0; /* number of blanks necessary */
	pos = 1; /* position of character in line */

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			/* We get the distance from the current pos and the next tab stop.
			The reason we subtract one is because pos is the tab character.
			We also "wrap" it with TABINC, suppose we were at column 14. */
			nb = TABINC - (pos - 1) % TABINC;
			while (nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		} else if (c == '\n') {
			/*If it's a newline, we reset the position to zero and print the newline character */
			putchar(c);
			pos = 1;
		} else {
			putchar(c);
			++pos;
		}
	}
}


/* Update 5/8/24: This was the solution I wrote over 2 years ago. The above solution 
is the one defined in the answer book. 

My justification for this is because the amount of space a tab
takes is dependent on the font. So, just to make it simple, I
made it a, "symbolic parameter."
When I originally did this exercise, I just replaced tab with 5 spaces
without any awareness of what a "tab" really is. Now after a quick
google search, I understand how tabstops work. Not that it's actually
super useful information I guess.

#define MAXLINE 100
#define TABSTOP 5

void detab();

char input[MAXLINE];
char buffer[MAXLINE];

char c;

main()
{
	extern char input[];
	extern char c;

	while (c != EOF)
	{
		detab();
	}

	return 0;
}

void detab()
{
	extern char input[];
	extern char c;
	extern char buffer[];
	int i, j, k;

	for (i = 0; i < (MAXLINE - 1) && ((c = getchar()) != EOF) && c != '\n'; i++)
	{
		input[i] = c;
	}

	if (c == '\n')
	{
		input[i] = c;
		i++;
	}

	input[i] = '\0';

	i = 0;
	j = 0;

	while ((buffer[i] = input[j]) != '\0')
	{
		if (buffer[i] == '\t')
		{
			for (k = 0; k < (TABSTOP - (j % TABSTOP)); k++)
			{
				buffer[i] = ' ';
				i++;
			}
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}

	printf("%s", buffer);
} */