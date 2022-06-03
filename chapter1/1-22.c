#include <stdio.h>

#define MAXLINE 100
#define MAXCOLUMN 30

void fold(char input[]);

int main() {

	extern char c;

	while (c != EOF) {
		fold();
	}

	return 0;

}


