#include<stdio.h>
#define MAXLINE 1000
int main()
{
	int i,c;
	i=0;
	char s[MAXLINE];
	while ((c=getchar())!=EOF)
	{
		s[i]=c;
	}
	s[i]='\0';

	printf("%s",s);
}