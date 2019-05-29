#include <stdio.h>
// qsort函数：以递增的顺序对v[left]...v[right]进行排序
void qsort(int v[],int left,int right)
{
	int i,last;
	void swap(int v[],int i,int j);

	if (left>=right)
	{
		return;
	}
	swap(v,left,(left+right)/2);
	last=left;
	for (i=left+1 ; i<=right ; i++ )
	{
		if (v[i]<v[left])
		{
			swap(v,++last,i);
		}
	}
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

void swap(int v[],int i,int j)
{
	int temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

int main()
{
	int a[6]={3,2,7,6,8,9};
	qsort(a,0,5);
}