/*
 * @Author: Guoquan Wei 1940359148@qq.com 
 * @Date: 2017-12-26 22:57:06 
 * @Last Modified by:   Guoquan Wei 
 * @Last Modified time: 2017-12-26 22:57:06 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

int getop(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);
void clear1(void);
void mathfnc(char s[]);

int main()
{
	int type, i, var = 0;
	double op2, op1, v;
	char s[MAXOP];
	double variaable[26];

	for (i = 0; i < 25; i++)
	{
		variaable[i] = 0.0;
	}
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NAME:
			mathfnc(s);
			break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() / op2);
			}
			else
			{
				printf("error:zero divisor\n");
			}
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(fmod(pop(), op2));
			}
			else
			{
				printf("error:zero divisor\n");
			}
			break;
		case '?':
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'c':
			clear1();
			break;
		case 'd':
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '=':
			pop();
			if (var >= 'A' && var <= 'Z')
			{
				variaable[var - 'A'] = pop();
			}
			else
			{
				printf("error:no variaable name\n");
			}
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		case 'v':
			push(v);
			break;
		default:
			if (type >= 'A' && type <= 'Z')
			{
				push(variaable[type - 'A']);
			}
			else
			{
				printf("error:unknow command %s\n", s);
			}
			break;
		}
		var = type;
	}
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error:stack full,can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
}

// getop function:获取下一个运算号或值操作数
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
	{
		;
	}
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-' && !islower(c))
	{
		return c;
	}
	if (islower(c))
	{
		while (islower(s[++i] = c = getch()))
		{
			;
		}
		s[i] = '\0';
		if (c != EOF)
		{
			ungetch(c);
		}
		if (strlen(s) > 1)
		{
			return NAME;
		}
		else
		{
			return s[--i];
		}
	}
	else if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
		{
			s[++i] = c;
			while (isdigit(c = getch()) || c == '.')
			{
				s[++i] = c;
			}
			if (c != EOF)
			{
				ungetch(c);
				return NUMBER;
			}
		}
		else if (c != EOF)
		{
			ungetch(c);
		}
		return '-';
	}
	else if (isdigit(c))
	{

		while (isdigit(s[++i] = c = getch()))
		{
			;
		}

		if (c == '.')
		{
			while (isdigit(s[++i] = c = getch()))
			{
				;
			}
		}
		s[i] = '\0';
		if (c != EOF)
		{
			ungetch(c);
		}
	}
	else
	{

		while (isdigit(s[++i] = c = getch()))
		{
			;
		}

		s[i] = '\0';
		if (c != EOF)
		{
			ungetch(c);
		}
	}
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return ((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
	if (bufp >= BUFSIZ)
	{
		printf("ungetch:too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

// clear function:clear the stack
void clear1(void)
{
	sp = 0;
}

void mathfnc(char s[])
{
	double op2;
	if (strcmp(s, "sin") == 0)
	{
		push(sin(pop()));
	}
	else if (strcmp(s, "cos") == 0)
	{
		push(cos(pop()));
	}
	else if (strcmp(s, "pow") == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else if (strcmp(s, "exp") == 0)
	{
		push(pow(pop(), op2));
	}
	else
	{
		printf("error:%s not supported\n", s);
	}
}
