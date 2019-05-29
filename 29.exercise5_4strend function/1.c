/*
 * @Author: weiguoquan 09970140229 
 * @Date: 2017-06-11 14:26:15 
 * @Last Modified by: weiguoquan 09970140229
 * @Last Modified time: 2017-06-11 14:26:37
 */
#include <stdio.h>

// strcat function:concatenate t to the end of s
void strcat1(char *s, char *t)
{
	while (*s)
	{
		s++;
	}
	while ((*s++ = *t++)) //此处要多加一个括号，编译器才能识别，否则有warning
	{
		;
	}
}
// strend function:return 1 if string t occurs at the end of s
int strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;
	// remember beginging of strings

	for (; *s; s++)
	{
		;
	}
	for (; *t; t++)
	{
		;
	}
	for (; *s == *t; s--, t--)
	{
		if (t == bt || s == bs)
		{
			break;
		}
	}
	if (*s == *t && t == bt && *s != '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char s[20] = "hello";
	char t[20] = "world";
	int a;
	printf("%s\n", s);
	printf("%s\n", t);
	a = strend(s, t);
	printf("%d\n", a);
	strcat1(s, t);
	printf("%s\n", s);
	printf("%s\n", t);
	a = strend(s, t);
	printf("%d\n", a);
}