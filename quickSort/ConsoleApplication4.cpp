// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void quickSort( int a[],int p,int r);
int partition(int a[],int p,int r);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[8];
	for(int i = 0 ;i <8;i++)
	{
		cin>>a[i];
	}
	quickSort(a,0,8);
	for(int i=0;i<8;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;

}
void quickSort(int a[], int p,int r)
{
	if(p < r)
	{
		int q = partition(a,p,r);
		quickSort(a,p,q);
		quickSort(a,q+1,r);
	}
}
int partition(int a[],int p,int r)
{
	int x = a[r-1];
	int i = p-1;
	for(int j=p;j<r-1;j++)
	{
		if(a[j]<= x)
		{
			i = i+1;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i+1];
	a[i+1] = a[r-1];
	a[r-1] = temp;
	return i+1;
}

