#include <stdio.h>

#define UPPER 300
#define STEP 20

int convertC(int fahr) {
	int celsius;
	
	for (; fahr <= UPPER; fahr+= STEP) {
		celsius = (((fahr-32)*5)/9);
		printf("%d\t%d\n",fahr,celsius);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		convertC(i);
	}
	return 0;
}


	
