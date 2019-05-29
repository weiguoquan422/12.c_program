#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 //最大文本行数
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;//下一个空闲位置,将allocbuf 的首地址给 allocp

char *alloc(int n)
/* 开辟能够存放n个字符的区域，并将首地址返回 */
{
	if (allocbuf+ALLOCSIZE-allocp>=n)
	{
		allocp=allocp+n;
		return allocp-n;
	}else
	{
		return 0;
	}
}

/* getline:read a line into s,return length 读入一行给s，并返回其长度 */
int getline1(char *s,int lim)
{
	int c;
	char *t=s;

	while (--lim>0 && (c=getchar())!=EOF && c!='\n')
	{
		*s ++=c;
	}
	*s='\0';
	return s-t;
}

char *lineptr[MAXLINES]; /* 定义一个数组，每个数组元素指向一个字符文本行 */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
{
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error:input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int getline1(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p;
	char line[MAXLEN];
	nlines = 0;
	while ((len = getline1(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len -1] = '\0'; //删除换行符
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/*void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
	{
		printf("%s\n", lineptr[i]);
	}
}*/

void writelines(char *lineptr[],int nlines)
{
	while (nlines-->0)
	{
		printf("%s\n",*lineptr++);
	}
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)//如果数组元素个数小于2,则返回
	{
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (strcmp(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}