#include <stdio.h>
#define MAXLINE 100

/* Exercise 1-17: Print all lines longer than 80 characters. */

int lineget(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = lineget(line, MAXLINE)) > 0)
	{
		if (len > 80)
		{
			printf("%s\n", line);
		}
	}

	return 0;
}

int lineget(char s[], int lim)
{

	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}

	if (c == '\n')
	{
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}
