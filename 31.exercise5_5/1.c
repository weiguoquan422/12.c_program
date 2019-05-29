/*
 * @Author: Guoquan Wei 1940359148@qq.com 
 * @Date: 2018-01-14 19:15:40 
 * @Last Modified by: Guoquan Wei
 * @Last Modified time: 2018-01-14 19:32:35
 */

#include <stdio.h>
/* strncpy:copy n characters from t to s */
void strncpy1(char *s,char *t,int n)
{
	while (*t && n-- > 0)//如果n>t的长度，当*t=\0时，跳出此循环，令之后的*s补'\0'
	{
		*s++=*t++;
	}
	while (n-- > 0)
	{
		*s++='\0';
	}
	*s++='\0';
}

#include <string.h>
/* strncat : concatenate n characters of t to the end of s 把t连接到s的末尾*/
void strncat1(char *s,char *t,int n)
{
	void strncpy1(char *s,char *t,int n);
	strncpy1(s+strlen(s),t,n);
}

/* strncmp:compare at most n characters of t with s 比较s与t的前n个字符*/
int strncmp1(char *s,char *t,int n)
{
	for (  ; *s==*t ; s++, t++ )
	{
		if (*s =='\0' || --n<=0)
		{
			return 0;
		}
		/* 如果s到末尾了，或者n个字符完全相同，则返回0 */
	}
	return *s-*t;//否则，返回第一个不同字符之间ascii码的差值
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

#include <ctype.h>
/* atoi:covert s to integer 把字符串转换成整形数 */
int atoi(char *s)
{
	int n,sign;

	for (  ; isspace(*s) ; s++ )
	{
		;
	}

	sign=(*s == '-') ? -1:1;//跳过符号
	if (*s =='+'|| *s =='-')
	{
		s++;
	}

	for (n=0 ; isdigit(*s) ; s++ )
	{
		n=10 * n+ *s -'0';
	}
	return sign*n;
}

void reverse(char *s)
{
	int c;
	char *t;

	for (t=s+(strlen(s)-1) ; s<t ; s++,t-- )
	{
		c=*s;
		*s=*t;
		*t=c;
	}
}

/* itoa:covert n to characters in s; pointer version 将整数n转换成字符，存入s中 */
void itoa(int n, char *s)
{
	int sign;
	char *t =s;//把s的首地址存入t

	if ((sign=n)<0)//用sign保存n
	{
		n=-n;//当n为负时，取反，使之为正，因为负的时候除十取余会出现问题
	}

	do{
		*s++ =n%10 +'0';
	}while((n=n/10)>0);

	if (sign<0)
	{
		*s++='-';
	}
	*s='\0';
	reverse(t);//reverse函数的参数是字符串的首地址
}

/* strindex:return index of t in s,-1 if none t在s中出现的位置*/
int strindex(char *s,char *t)
{
	char *b=s;
	char *p,*r;

	for (  ; *s!='\0' ; s++ )
	{
		for (p=s,r=t ; *r!='\0'&& *p==*r ; p++,r++ )
		{
			;
		}
		if (r>t && *r == '\0')
		{
			return s-b;
		}
	}
	return -1;
}

/* atof:convert string s to double把字符串转换为double型 */
double atof(char *s)
{
	double val,power;
	int sign;

	for (  ; isspace(*s) ; s++ )
	{
		;
	}

	sign=(*s=='-')? -1:1;
	if (*s=='+'||*s=='-')
	{
		s++;
	}

	for (val=0.0 ; isdigit(*s) ; s++ )
	{
		val=10.0*val+(*s-'0');
	}
	if (*s =='.')
	{
		s++;
	}
	for (power=1.0 ; isdigit(*s) ; s++ )
	{
		val=10.0 * val +(*s -'0');
		power =10.0 * power;
	}
	return sign*val/power;
}

int main()
{
	int cmpnum;
	int lengtha,lengthb;
	double numc;
	int numa,numb;
	char a[]={'i',' ','l','o','v','e',' ','\0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char b[]={'s','t','u','d','y','\0'};
	printf("%s\n",a);
	printf("%s\n",b);
	lengtha= getline1(a,15);
	lengthb= getline1(b,6);
	numc=atof(a);
	// numa=atoi(a);
	// numb=atoi(b);
	// itoa(numb,a);
	// strncpy1(a,b,20);
	// strncat1(a,b,11);
	// numa= strindex(a,b);//返回a在b中出现的位置
	// cmpnum =strncmp1(a,b,5);
	printf("%s\n",a);
	printf("%s\n",b);
	printf("%lf\n",numc);
	// printf("%d\n",numa);
	// printf("%d\n",numb);
	return 0;
}

