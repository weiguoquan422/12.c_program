#include <string.h>
#include <stdio.h>
#define MAXLINE 1000
#define abs(x) (x<0 ? -x:x)



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
// itoa function:convert n to characters in s,w characters wide

void itoa(int n,char s[],int w)
{
	int i,sign;
	void reverse(char s[]);
	sign=n;
	i=0;
	do{
		s[i++]=abs(n%10)+'0';
	}while((n/10)!=0);
	if (sign<0)
	{
		s[i++]='-';
	}
	while (i<w)
	{
		s[i++]=' ';
	}
	s[i]='\0';
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

	itoa(24,a,10);
	printstring(a);
}