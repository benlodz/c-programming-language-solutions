#include <stdio.h>

#define CHAR_MAX 127 

main() {
	char freq[CHAR_MAX];
	char c;
	int i, j;
	int max = 0;

	for (i = 0; i < CHAR_MAX; i++) {
		freq[i] = 0;
	}
	
	while ( (c = getchar()) != EOF) {
		if ((++freq[c]) > max) {
			max = freq[c];
			printf("max:%d",max);
		}
		
	}
	putchar('\n');

	for (i = max; i > 0; i--) {
		printf("%3d|",i);
		for (j = 0; j < CHAR_MAX; j++) {
			if ( freq[j] >= i) {
				printf("*");
			} else if (freq[j] != 0)  {
				printf("-");
			}
		}
		printf("\n");
	}
	printf("   |");
	for (i = 0; i < CHAR_MAX; i++) {
		if (freq[i] != 0) {
			putchar(i);
		}
	}
	printf("\n");

}





















