#include <stdio.h>
#define MAXLINE 100

/* Exercise 1-18: my_remove all trailing blanks and tabs from each line of input. */

int my_getline(char s[], int maxline);
int my_remove(char s[]);

int main()
{
	char line[MAXLINE];

	while (my_getline(line, MAXLINE) > 0)
	{
		if (my_remove(line) > 0)
		{
			printf("%s", line);
		}
	}
}

int my_getline(char s[], int maxline)
{
	int i, c;

	for (i = 0; i < maxline - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
	{
		s[i] = c;
	}

	/* 	clean up by adding a newline. */
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

int my_remove(char s[])
{
	int i;
	i = 0;

	/* 	Look for the newline */
	while (s[i] != '\n')
	{
		++i;
	}
	--i;

	/* 	Get to the next non blank character. */
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
	{
		--i;
	}

	/* 	Clean up the string by putting a newline and null terminator if (i >= 0) */
	{
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}

	return i;
}