// ConsoleApplication6.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"

using namespace std;
//
int memoized_cut_rod(int p[],int n );//r[]�����ʼ������ �����س���n�����Ž�
int memoized_cut_rod_aux(int p[],int n, int r[]); //���㲻ͬ����n�����Ž�
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

//����ʼǣ� ��Ϊ�����±��0��ʼ�������ڼ�¼����Ϊ0 ��ʱ����ʹ��r[n-1]���洢��ֱ�ӷ���0���ɡ� r[0]���洢����Ϊ1�����Ž⣬֮���������ơ� 
//�������˼��Ϊ�ӵݹ�ķ�ʽ����һ������ֽ�Ϊ��������⡣����ÿ�μ���ʱ��������������Ž⣬��������һ������������ͬ������ʱ����ֱ�Ӳ��Ҵ洢�������е����Ž⣬���������̣��Ż���������Ч�ʡ�
//��һ�ִ��������Զ����µĵݹ�ʵ�ֶ�̬�滮�ķ����� ���˷���֮�⣬�����Ե����ϵĶ�̬�滮������





