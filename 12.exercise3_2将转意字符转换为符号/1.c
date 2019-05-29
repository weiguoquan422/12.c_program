#include <stdio.h>
#define MAXLINE 1000
int getlinee(char s[], int lim);
void escape(char s[], char t[]);

int main()
{
	int i;
	char a[MAXLINE], b[MAXLINE];
	int length;

	length = getlinee(a, MAXLINE);
	escape(b, a);
	printf("\n");
	printf("%d",length);
	printf("\n");
	for (  i = 0; a[i]!='\0'; i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	
	for (  i = 0; b[i]!='\0'; i++)
	{
		printf("%c",b[i]);
	}
	printf("\n");
}

// getline function:read a line into an array,return its length
int getlinee(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF ; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

// escape function:expand newline and tab into visible sequences
void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch (t[i])
		{
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}