// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
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
	for(int j = 1;j<=n;j++)//j表示总长度
	{
		int q = -1;
		for(int i = 1;i<=j;i++)// j-i表示分解子问题的长度
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

//代码笔记：自底向上版本的动态规划求最优解，在我看来本质上是把自定上下的递归求解子问题最优解的方法通过for循环进行操作，并将结果存储在r[]中，其他差异不大。
