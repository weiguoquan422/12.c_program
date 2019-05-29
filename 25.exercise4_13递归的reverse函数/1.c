#include <string.h>
#include <stdio.h>

// reverse function:reverse string s in place
void reverse(char s[])
{
	void reverser(char s[],int i,int len);
	reverser(s,0,strlen(s));
}

void reverser(char s[],int i,int len)
{
	int c,j;

	j=len-(i+1);
	if (i<j)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		reverser(s,++i,len);
	}
}

int main()
{
	char s[6]="fullss";
	reverse(s);
	printf("%s",s);
}