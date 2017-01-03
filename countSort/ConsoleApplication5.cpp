// ConsoleApplication5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <string.h>

using namespace std;
template <class T>
int getArrayLen(T& array)
{
return (sizeof(array) / sizeof(array[0]));
}
int getMax(int a[],int length);
void countSort(int a[],int b[],int k,int a_length);  //a 为输入数组，b为输出数组，k为数组长度
int _tmain(int argc, _TCHAR* argv[])
{
	int a[8];
	int b[8];
	for(int i=0;i<8;i++)
	{
		cin>>a[i];
	}
	
	countSort(a,b,getMax(a,getArrayLen(a))+1,getArrayLen(a));
	for(int i=0;i<8;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;

	return 0;
}
int getMax(int a[],int length)
{
	int max = -1;
	for(int i=0;i<length;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}

void countSort(int a[],int b[],int k,int a_length)
{

	///////////////////////////
	//getArrayLen(a);
	//!!!!!!!!!!!!!!!!!!!!!!!!!
	//数组作为参数传递后无法获取其长度！ 使用时注意
	int c[1000];
	for(int i=0;i<k;i++)
	{
		c[i] = 0;
	}
	
	for(int i = 0 ;i<a_length;i++)
	{
		 c[a[i]] +=1;
	}

	for(int i = 1;i<k;i++)
	{
		c[i]+=c[i-1];
	}
	for(int i=a_length-1;i>=0;i--)
	{
		//因为c[]数组内的值均大于一 考虑边界情况，故数组b 的下标为c[a[i]]-1,不然将会出现数组越界
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
}



//思想：计算数组内每个值在数组内的位置，一次遍历即可计算完成
//注意：临时存储数组c[]的大小以及下标需要注意以免数组越界。