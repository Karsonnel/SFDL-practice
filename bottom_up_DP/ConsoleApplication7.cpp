// ConsoleApplication7.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int bootm_up_dp(int a[],int n);
int max(int a,int b);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[11];
	for(int i=1;i<=10;i++)
	{
		cin>>a[i];
	}
	cout<<bootm_up_dp(a,10)<<endl;

	return 0;
}
int bootm_up_dp(int a[],int n)
{
	int r[11];
	for(int i=1;i<=n;i++)
	{
		r[i] = -1;
	}
	r[0] = 0;
	for(int j = 1;j<=n;j++)//j��ʾ�ܳ���
	{
		int q = -1;
		for(int i = 1;i<=j;i++)// j-i��ʾ�ֽ�������ĳ���
		{
			q= max(q,a[i]+r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
}
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//����ʼǣ��Ե����ϰ汾�Ķ�̬�滮�����Ž⣬���ҿ����������ǰ��Զ����µĵݹ�������������Ž�ķ���ͨ��forѭ�����в�������������洢��r[]�У��������첻��
