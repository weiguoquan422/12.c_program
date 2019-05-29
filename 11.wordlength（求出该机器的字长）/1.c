#include <stdio.h>

int wordlength(void)
{
    int i;
    unsigned v = (unsigned)~0;
    for (i = 1; (v = v >> 1) > 0; i++)
    {
	;
    }
    return i;
}

int main()
{
    int a;
    a = wordlength();
    printf("%d", a);
}
