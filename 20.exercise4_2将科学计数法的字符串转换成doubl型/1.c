#include <ctype.h>
#include <stdio.h>
#define MAXLINE 1000

// atof:convert string s to double
double atof(char s[])
{
	double val,power;
	int exp,i,sign;

	for (i=0 ; isspace(s[i]) ; i++ )
	{
		;
	}
	sign=(s[i]=='-')? -1:1;
	if (s[i]=='+'||s[i]=='-')
	{
		i++;
	}
	for (val=0.0 ; isdigit(s[i]) ; i++ )
	{
		val=10.0*val+(s[i]-'0');
	}
	if (s[i]=='.')
	{
		i++;
	}
	for (power=1.0 ; isdigit(s[i]) ; i++ )
	{
		val=10.0*val+(s[i]-'0');
		power=power*10;
	}
	val=sign*val/power;

	if (s[i]=='e'||s[i]=='E')
	{
		sign=(s[++i]=='-'? -1:1);
		if (s[i]=='+'||s[i]=='-')
		{
			i++;
		}
		for (exp=0 ; isdigit(s[i]) ; i++ )
		{
			exp=10*exp+(s[i]-'0');	
		}
		if (sign==1)
		{
			while (exp-- >0)
			{
				val=val*10;
			}
		}else
		{
			while (exp-- >0)
			{
				val=val/10;
			}
		}
	}
	return val;
}

// 将行保存到s中，并返回该行长度
int getline1(char line[],int lim){
    int c,i;
    i=0;
    while(--lim>0&&(c=getchar())!=EOF&&c!='\n'){
        line[i++]=c;
    }
    line[i]='\0';
    return i;
}


int main()
{
	double sum;
	char line[MAXLINE];
	sum=0;
	while (getline1(line,MAXLINE)>0)
	{
		printf("\t%g\n",sum=sum+atof(line));
	}
	return 0;
}