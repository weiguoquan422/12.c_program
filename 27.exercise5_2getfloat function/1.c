#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int getch(void);
void ungetch(int c);

#define BUFSIZE 100

char buf[BUFSIZ];
int bufp = 0;
int getch(void)
{
	return ((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch:too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

int getfloat(float *pn)
{
	int c, sign;
	float power;//位权

	while (isspace(c = getch()))
	//有空格被压回来，则在函数一开始就把它去掉。连续好几个空格也是可以把它们去掉的，第一个空格被压回来再取出来，去掉，再取再跳，知道取得为非空格
	{
		;
	}

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	//如果是空格则压回去
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		c = getch();
	}
	for (*pn = 0.0; isdigit(c); c = getch())
	{
		*pn = 10.0 * *pn + (c - '0');
	}
	if (c == '.')
	{
		c = getch();
	}
	for (power = 1.0; isdigit(c); c = getch())
	{
		*pn = 10.0 * *pn + (c - '0');
		power = 10.0 * power;
	}
	*pn = *pn * sign / power;

	if (c != EOF)
	{
		ungetch(c);
	}
	return c;
}

int main()
{
	int n;
	float array[SIZE];
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
	{
		;
	}
	array[n] = '\0';
	for (n = 0; n < SIZE && array[n] != '\0'; n++)
	{
		printf("%f\n", array[n]);
	}
	return 0;
}