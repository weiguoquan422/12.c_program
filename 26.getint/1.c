// 输入一个字符串，当其中有整型数时赋值给array[n]，有小写字母或空格直接跳过，有大写字母，赋值array[n]为1
#include <ctype.h>
#include <stdio.h>

#define SIZE 100
#define BUFSIZE 100

char buf[BUFSIZ];
int bufp=0;

int getch(void)
// 从输入流getchar或者缓存buf中取值
{
	return((bufp>0)?buf[--bufp]: getchar());
}


void ungetch(int c)
// 将c压回到buf中
{
	if (bufp>=BUFSIZ)
	{
		printf("ungetch:too many characters\n");
	}else
	{
		buf[bufp++]=c;
	}
}

int getint(int *pn)
{
	int c,sign;

	while (isspace(c=getch())||islower(c))
	{
		;
	}
	if (!isdigit(c)&&c!=EOF&&c!='+'&&c!='-')
	{
		*pn=0;
		return 0;
	}
	sign=(c=='-')? -1:1;
	if (c=='+'||c=='-')
	{
		c=getch();
	}
	for (*pn=0 ; isdigit(c) ; c=getch() )
	{
		*pn=10* *pn+(c-'0');
	}
	*pn=sign* *pn;
	if (c!=EOF)
	{
		ungetch(c);
	}
	return c;
}


/* main函数：输入一串字符，把里面的数字串转换为真的的数字，存入array中，并打印array */

int main()
{
	int n,array[SIZE];
	for (n=0 ; n<SIZE && getint(&array[n])!=EOF ; n++ )
	{
		;
	}
	array[n]='\0';
	for (n=0 ; n<SIZE&&array[n]!='\0'; n++ )
	{
		printf("%d\n",array[n]);
	}
	return 0;
}
