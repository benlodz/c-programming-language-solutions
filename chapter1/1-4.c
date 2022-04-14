#include <stdio.h>

main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	while ( celsius <= upper ) {
		fahr = (9.0/5.0) + (celsius + 32.0);	
		printf("Celsius | Fahrenheit\n");
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

