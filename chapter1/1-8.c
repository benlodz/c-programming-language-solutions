#include <stdio.h>

main() {	
	int c,bc,tc,nc;

	bc = 0;
	tc = 0;
	nc = 0;

	while ( (c = getchar()) != EOF) {
		if (c == ' ') {
			bc++;
		}
		if (c == '\t') {
			tc++;
		}
		if (c == '\n') {
			nc++;
		}
	}

	printf("Blanks:%d Tabs:%d Newline:%d\n",bc,tc,nc);


}

