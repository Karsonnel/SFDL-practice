// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void merge(int a[],int p,int q,int r);
void mergeSort(int a[],int p,int r);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[8];
	for(int i=0;i<8;i++)
	{
		cin>>a[i];
	}

	mergeSort(a,0,7);
	for(int i=0;i<8;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
void merge(int a[],int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int b[10];
	int c[10];
	for(int i=0;i<10;i++)
	{
		b[i]=0;
		c[i]=0;
	}
	for(int i=0;i<n1;i++)
	{
		b[i]=a[p+i];
	}
	b[n1] = 100;
	for(int i=0;i<n2;i++)
	{
		c[i]=a[q+i+1];
	}
	c[n2] = 100;
	int i=0;
	int j=0;
	for(int k=p;k<=r;k++)
	{
		if(b[i]<c[j])
		{
			a[k] = b[i];
			i++;
		}
		else
		{
			a[k] = c[j];
			j++;
		}
	}
}
void mergeSort(int a[],int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);

}

