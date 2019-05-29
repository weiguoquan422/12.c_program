#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 //����ı�����
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;//��һ������λ��,��allocbuf ���׵�ַ�� allocp

char *alloc(int n)
/* �����ܹ����n���ַ������򣬲����׵�ַ���� */
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

/* getline:read a line into s,return length ����һ�и�s���������䳤�� */
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

char *lineptr[MAXLINES]; /* ����һ�����飬ÿ������Ԫ��ָ��һ���ַ��ı��� */

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
			line[len -1] = '\0'; //ɾ�����з�
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
	if (left >= right)//�������Ԫ�ظ���С��2,�򷵻�
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