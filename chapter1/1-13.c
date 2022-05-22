#include <stdio.h>

#define LIMIT 9
main() {

	int arr [LIMIT+1];
	int out = 0;
	int length = 0;
	int max = 0; 
	int i, j; /* variable for for loops */
	int c; /* variable to get char */

	for (i = 0; i < LIMIT+1; i++) {
		arr[i] = 0;
	}

	while ( (c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') { /* checks for space */
			if (out == 0) { /* checks if just came from word */
				if (length > LIMIT) {
					if (arr[LIMIT]++ > max) {
						max = arr[LIMIT];
					}
					length = 0;
				} else {
					if (arr[length-1]++ > max) {
						max = arr[length-1];
					}
					length = 0;
				};
				out = 1;
			}
		} else {
			length++;
			out = 0;
		}
	}


	printf("\n");	
	for (i = max; i > 0; i--) {
		printf("%3d|",i);
		for (j = 0; j < LIMIT+1; j++) {
			if ((arr[j] >= i)) {
				printf("*");
			} else {
				printf("-");
			}
		}

					
		printf("\n");
	}
	printf("    ");
	for (i = 1; i < LIMIT+1; i++) {
		printf("%d",i);
	}
	printf("L");  /*L meaning everything beyond the limit */ 


	
}

					

