#include <math.h>
#include <stdio.h>
#define abs(x) (x<0 ? -x:x)
// itoa function:convert n to characters in s
void itoa(int n,char s[])
{
	static int i;
	if (n/10)
	{
		itoa(n/10,s);
	}else
	{
		i=0;
		if (n<0)
		{
			s[i++]='-';
		}
	}
	s[i++]=abs(n)%10+'0';
	s[i]='\0';
}



int main()
{
	char s[10];
	int n=100;
	itoa(n,s);
	printf("%s",s);
	return 0;
}