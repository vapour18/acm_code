//������ϸ�ȡһ�������ʺ��Ƿ���Ϊ0
//���öԲ��������ö�ٵ��㷨
//����1,2���ϵĺͺ�3,4���ϵĺͣ��ڽ������򣬵�������ж��Ƿ��ܵõ�5���ϵ��෴��
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
		if(sum1[i]+sum2[j]==x)	return 1;//�÷������൱��λ����λ�ã�Ȼ���ƶ�ָ��
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
