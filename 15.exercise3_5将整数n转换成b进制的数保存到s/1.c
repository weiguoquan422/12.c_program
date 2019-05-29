#include <string.h>
#include <stdio.h>
#define MAXLINE 1000



// reverse function:reverse the array s
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}



// itob function:convert n to characters in s -base b
void itob(int n, char s[], int b)
{
	int i, j, sign;
	void reverse(char s[]);

	if ((sign = n) < 0)
	{
		n = -n;
	}
	i = 0;
	do
	{
		j = n % b;
		s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
	} while ((n = n / b) > 0);
	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}



// printstring function:print a array
void printstring(char s[]){
	int i;
	for (  i = 0; s[i]!='\0'; i++)
	{
		printf("%c",s[i]);
	}
	printf("\n");
}



int main(){
	int i;
	char a[MAXLINE], b[MAXLINE];
	int length;

	itob(-2147483640,a,2);

	printstring(a);
}
