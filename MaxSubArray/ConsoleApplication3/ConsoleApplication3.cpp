// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

typedef struct 
{
	int low;
	int high;
	int sum;

}parm;
int cd;
parm findMax(int a[],int low,int high);
parm findCrossMax(int a[],int low,int mid,int high);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[16];
	for(int i =0; i<16;i++)
	{
	    cin>>a[i];
	}
	 
	cd = sizeof(a);
	parm mp;
	mp = findMax(a,0,15);
	cout<<mp.low<<" "<<mp.high<<" "<<mp.sum<<endl;
	return 0;
	
}
parm findCrossMax(int a[],int low, int mid,int high)
{
	int LeftSum = -10000;
	int sum = 0;
	int maxLeft;
	parm mp;
	for(int i=mid;i>=low;i--)
	{
		sum+= a[i];
		if(sum > LeftSum)
		{
			LeftSum = sum;
			maxLeft = i;
		}
	}
	int RightSum = -10000;
	 sum = 0;
	 int maxRight;
	for(int i=mid+1;i<=high;i++)
	{

		sum+= a[i];

		if(sum > RightSum)
		{
		maxRight = i;
		RightSum = sum;
		}
	}
	mp.low = maxLeft;
	mp.high = maxRight;
	mp.sum = RightSum + LeftSum;
	return mp;
}
parm findMax(int a[],int low,int high)
{
	parm mp;
	parm lp;
	parm rp;
	parm cp;
	if(low == high)
	{
		mp.low = low;
		mp.high = high;
		mp.sum = a[low];
		return mp;
	}
	else
	{
		int mid = (low+high)/2;
		lp = findMax(a,low,mid);
		rp = findMax(a,mid+1,high);
		cp = findCrossMax(a,low,mid,high);
		//下标变换
		if(lp.sum >= rp.sum && lp.sum >= cp.sum)
		{
			return lp;
		}
		else if(rp.sum >= lp.sum && rp.sum >= cp.sum)
		{
			return rp;
		}
		else
			return cp;
	}
}


		



