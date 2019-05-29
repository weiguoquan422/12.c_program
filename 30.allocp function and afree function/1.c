/*
 * @Author: Guoquan Wei 1940359148@qq.com 
 * @Date: 2018-01-11 20:57:28 
 * @Last Modified by: Guoquan Wei
 * @Last Modified time: 2018-01-11 21:07:09
 */
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

void afree(char *p)
/* 将指针设为p，释放存储区域 */
{
	if (p>=allocbuf&&p<allocbuf+ALLOCSIZE)
	{
		allocp=p;
	}
}