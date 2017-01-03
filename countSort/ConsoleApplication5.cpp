// ConsoleApplication5.cpp : �������̨Ӧ�ó������ڵ㡣
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
void countSort(int a[],int b[],int k,int a_length);  //a Ϊ�������飬bΪ������飬kΪ���鳤��
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
	//������Ϊ�������ݺ��޷���ȡ�䳤�ȣ� ʹ��ʱע��
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
		//��Ϊc[]�����ڵ�ֵ������һ ���Ǳ߽������������b ���±�Ϊc[a[i]]-1,��Ȼ�����������Խ��
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
}



//˼�룺����������ÿ��ֵ�������ڵ�λ�ã�һ�α������ɼ������
//ע�⣺��ʱ�洢����c[]�Ĵ�С�Լ��±���Ҫע����������Խ�硣