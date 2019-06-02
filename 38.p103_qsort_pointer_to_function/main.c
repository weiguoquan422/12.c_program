#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void swap(char *v[], int i, int j);
int numcmp(char *s1, char *s2);
void qsort1(void *v[], int left, int right, int (*comp)(void *, void *));

int main(int argc, char *argv[])
{
	int nlines;//读入的输入行数
    int numeric = 0;//若进行数值排序，则numeric的值为1

    //判断是否是数值排序
    if(argc > 1 && strcmp(argv[1], "-n") == 0){
        numeric = 1;
    }
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort1((void **)lineptr, 0, nlines - 1, (int(*)(void *, void *))(numeric ? numcmp : strcmp));
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
		if (nlines >= maxlines || (p = alloc(len + 1)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len] = '\0'; //删除换行符
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


void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


/*--------  以递增顺序对v[left]...v[right]进行排序  --------*/
void qsort1(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i, last;
    if (left >= right) {
        return;
    }
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1 ; i <= right ; i++ ) {
        if((*comp)(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort1(v, left, last-1, comp);
    qsort1(v, last+1, right, comp);
}


/*--------  按数值顺序比较字符串s1和s2  --------*/
int numcmp(char *s1, char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    }else if (v1 > v2)
    {
        return 1;
    }else {
        return 0;
    }
}