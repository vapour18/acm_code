#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int f[50];
void solve(int x,int k)
{
	if(x>=0&&k>0)
	{
		if(f[x]>=k)
		{
			printf("0");
			solve(x-1,k);
		}
		else
		{
			if(x!=0)	printf("10");
			else	printf("%d",k-1);//x==0 递归的终点了
			solve(x-2,k-f[x]);//x-2是因为确定了下一位已经确定为0了
		}
	}
}
int main()
{
	int n,k;
	f[0]=1,f[1]=2;
	for(int i=2;i<=45;i++)	f[i]=f[i-1]+f[i-2];
	scanf("%d%d",&n,&k);
	if(k>f[n])	printf("-1");
	else		solve(n-1,k);
	printf("\n");
}
