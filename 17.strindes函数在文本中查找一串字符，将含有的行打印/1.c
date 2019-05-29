/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 10时03分38秒
 ************************************************************************/

#include<stdio.h>
#define MAXLINE 1000

int getline1(char line[],int lim);
int strindex(char s[],char t[]);

char pattern[]="ould";

int main()
{
    char line[MAXLINE];
    int found=0;

    while(getline1(line,MAXLINE)>0){
        if(strindex(line,pattern)>=0){
            printf("%s",line);
            found++;
        }
    }
    return found;
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


// strindex函数：返回t在s中的位置，若未找到，返回-1
int strindex(char s[],char t[])
{
    int i,j,k;
    for (i=0 ; s[i]!='\0' ; i++ )
    {
        for (j=i,k=0 ; t[k]!='\0'&&s[j]==t[k] ; j++,k++ )
        {
            ;   
        }
        if (k>0&&t[k]=='\0')
        {
            return i;
        }       
    }
    return -1;
}