#include<stdio.h>

main()
{
	printf("signed char min=%d\n", -(char)((unsigned char)~0 >> 1));
	printf("signed char max=%d\n", (char)((unsigned char)~0 >> 1));

	printf("unsigned char max=%d\n", (unsigned char)~0);


}