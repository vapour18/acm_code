//求n位k进制数没有两个相邻的0且没有前导0的个数
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long dp[20];
	int k,n;
	scanf("%d%d",&n,&k);
	dp[0]=1,dp[1]=k-1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
