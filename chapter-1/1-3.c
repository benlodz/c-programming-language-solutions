#include <stdio.h>

/* Exercise 1-3: Rewrite program with a table heading */

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;	 /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20;	 /* step size */

	fahr = lower;

	printf("Fahrenheit|Celsius\n");
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
