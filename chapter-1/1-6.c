#include <stdio.h>

/* Verify that EOF is not 0 nor 1 */

main()
{
	printf("%d", getchar() != EOF);
}
