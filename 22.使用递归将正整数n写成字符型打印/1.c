#include <stdio.h>
// printd函数：打印十进制数n
void printd(int n)
{
	if (n<0)
	{
		putchar('-');
		n=-n;
	}
	if (n/10)
	{
		printd(n/10);
	}
	putchar(n%10+'0');
}
int main()
{
	int n;
	n=187;
	printd(n);
	printf("\n");
}