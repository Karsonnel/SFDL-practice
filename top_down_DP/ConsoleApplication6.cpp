// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;
//
int memoized_cut_rod(int p[],int n );//r[]数组初始化函数 并返回长度n的最优解
int memoized_cut_rod_aux(int p[],int n, int r[]); //计算不同长度n的最优解
int max(int a,int b);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	cout<<"optimum solution: ";
	cout<<memoized_cut_rod(a,10)<<endl;
	//memoized_cut_rod(a,10);

	return 0;
}
int memoized_cut_rod(int p[],int n)
{
	int r[10];
	for(int i = 0 ;i<n;i++)
	{
		r[i] = -1;
	}

    return memoized_cut_rod_aux(p, n ,r);
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
int memoized_cut_rod_aux(int p[],int n, int r[])
{
	int q;
	if(n==0)
	{
		return 0;
	}
	else
	{
	if(r[n-1]>=0)
	{
		return r[n-1];
	}
	if(n==0)
	{
		q = 0;
	}
	else
	{
		q = -1;
		for(int i = 0 ;i<n;i++)
		{
			q = max(q,p[i]+memoized_cut_rod_aux(p,n-i-1,r));
			//cout<<" q : "<<q<<" i: "<<i<<endl;
		}
	}
	r[n-1] = q;
	//cout<<" n: "<<n<<" q: "<<q<<endl;
	return q;
	}
}

//代码笔记： 因为数组下标从0开始，所以在记录长度为0 的时候不能使用r[n-1]来存储，直接返回0即可。 r[0]来存储长度为1的最优解，之后依次类推。 
//程序核心思想为从递归的方式，将一个问题分解为多个子问题。并在每次计算时保存子问题的最优解，这样当另一个问题遇到相同子问题时即可直接查找存储在数组中的最优解，免除计算过程，优化程序运行效率。
//是一种带备忘的自顶向下的递归实现动态规划的方法。 除此方法之外，还有自底向上的动态规划方法。





