//hdu 3652,比3555难一点,多了一个余数为0的条件
//dp[l][pre][s][r] 前l位,前一个数为pre,flag当前数是否有13,r表示余数是多少
#include<cstdio>
#include<cstring>
#include<algorithm>
#define m 13
using namespace std;
int pow[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int num[11],dp[10][10][2][13];
int dfs(int l,int pre,int flag,int r,int e)
{
	if(l==-1)	return flag==1&&r==0;
	if(!e&&dp[l][pre][flag][r]!=-1)		return dp[l][pre][flag][r];
	int u= e?num[l]:9,res=0;
	for(int i=0;i<=u;i++)
	{
		if(pre==1&&i==3)
			res+=dfs(l-1,i,1,(m+r-i*pow[l]%m)%m,e&&i==u);
		else
			res+=dfs(l-1,i,flag,(m+r-i*pow[l]%m)%m,e&&i==u);
	}
	return e? res:dp[l][pre][flag][r]=res;
}
int solve(int n)
{
	int l=0;
	while(n)
	{
		num[l++]=n%10;
		n/=10;
	}
	return dfs(l-1,0,0,0,1);
}
int main()
{
	int a;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&a)!=EOF)
	{
		printf("%d\n",solve(a));
	}
	return 0;
}
