//数位dp
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long dp[21][10][2];//dp[l][pre][s] 前l位,前一个数为pre,flag当前数是否有49
int num[21];
long long dfs(int l,int pre,bool flag,bool e)
{
	if(l==-1)	return flag==1;
	if(!e&&dp[l][pre][flag]!=-1)		return dp[l][pre][flag];
	int u= e?num[l]:9;
	long long res=0;
	for(int i=0;i<=u;i++)
	{
		if(pre==4&&i==9)	res+=dfs(l-1,i,1,e&&i==u);
		else res+=dfs(l-1,i,flag,e&&i==u);
	}
	return e? res:dp[l][pre][flag]=res;
}
long long solve(long long n)
{
	int l=0;
	while(n)
	{
		num[l++]=n%10;
		n/=10;
	}
	return dfs(l-1,0,0,1);
}
int main()
{
	int t;
	long long a;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		scanf("%lld",&a);
		printf("%lld\n",solve(a));
	}
}
