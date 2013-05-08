//五个集合各取一个数，问和是否能为0
//采用对部分求和再枚举的算法
//先求1,2集合的和和3,4集合的和，在将其排序，倒叙相加判断是否能得到5集合的相反数
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 205
using namespace std;
int n,sn1,sn2;
long long sum1[maxn*maxn],sum2[maxn*maxn];
long long num[6][maxn];
bool solve(long long x)
{
	int i=0,j=sn2-1;
	while(i<sn1&&j>=0)
	{
		if(sum1[i]+sum2[j]==x)	return 1;//好方法，相当定位两个位置，然后移动指针
		if(sum1[i]+sum2[j]<x)	i++;
		else	j--;
	}
	return 0;
}
int main()
{
	int t;
	bool flag;
	cin>>t;
	while(t--)
	{
		sn1=sn2=0;
		flag=0;
		scanf("%d",&n);
		for(int i=0;i<5;i++)
			for(int j=0;j<n;j++)
				cin>>num[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				sum1[sn1++]=num[0][i]+num[1][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				sum2[sn2++]=num[2][i]+num[3][j];
		sort(sum1,sum1+sn1);
		sort(sum2,sum2+sn2);
		for(int i=0;i<n;i++)
		{
			if(solve(-num[4][i]))
			{
				flag=1;
				break;
			}
		}
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
}
