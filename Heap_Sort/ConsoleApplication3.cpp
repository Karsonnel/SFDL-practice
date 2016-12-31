// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void max_Heap(int a[], int i,int length);
void build_Heap( int a[],int length);
void heap_Sort(int a[],int length);
int left( int i);
int right( int i);
int parent( int i);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[10];
	for( int i=0;i<10;i++)
	{
		cin>>a[i];
	}
    heap_Sort(a,10);
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
	
}
int left( int i )
{

	if(i ==0)
	{
		return 1;
	}
	else
	{
		return 2*i+1;
	}
	
}
int right(int i )
{
	if(i==0)
	{
		return 2;
	}
	else
	{
		return 2*i+2;
	}
}
int parent( int i )
{
	return i/2;
}
void max_Heap(int a[], int i,int length)
{
	
	int largest;
	int l = left(i);
	int r = right(i);
	if(l < length && a[l] > a[i])
	{
		 largest = l;
	}
	else 
	{
		largest = i;
	}
	if(r < length && a[r] > a[largest])
	{
		largest = r;
	}
	if( largest != i)
	{
		int b;
		b = a[i];
		a[i] = a[largest];
		a[largest] = b;
		max_Heap(a,largest,length);
	}
	
}
void build_Heap(int a[],int length)
{

	
	for(int i=(length/2)-1;i>=0;i--)
	{
	
		max_Heap(a,i,length);
	}
}
void heap_Sort(int a[],int length)
{

	build_Heap(a,length);

	for(int i = length - 1 ; i >= 1 ; i--)
	{
			
		int b;
		b = a[0];
		a[0] = a[i];
		a[i] = b;

		max_Heap(a,0,i);

	}
}


	

