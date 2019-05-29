#include <stdio.h>
#define MAXLINE 1000
int getlinee(char s[], int lim);
void expand(char s1[], char s2[]);
void printstring(char s[]);

int main()
{
	int i;
	char a[MAXLINE], b[MAXLINE];
	int length;

	length = getlinee(a, MAXLINE);
	printf("%d", length);
	printf("\n");
	expand(a, b);
	printstring(a);
	printstring(b);
}

// expand funtion:expand shorthand notation in s1 into string s2
void expand(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;

	while ((c = s1[i++]) != '\0')
	{
		if (s1[i] == '-' && s1[i + 1] > c)
		{
			i++;
			while (c < s1[i])
			{
				s2[j++] = c++;
			}
		}
		else
		{
			s2[j++] = c;
		}
	}
	s2[j] = '\0';
}

// getline function:read a line into an array,return its length
int getlinee(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

// printstring function:print a array
void printstring(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}