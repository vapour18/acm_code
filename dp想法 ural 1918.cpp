/*
要让桌子上的硬币增加，就要让棍子放置的位置总体保持递增
dp[i][j]表示当桌子上有i个硬币时，最多能到达j个硬币的情况数
所以dp[i][j]=dp[i-1][j]*j+sum(dp[i-1][k])(i<k<j);
但是要用滚动数组优化，否则会mle
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
const int mod=1000000007;
long long dp[2][maxn];
int main()
{
	int n;
	int x=0,y=1;
	long long sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		sum=0;
		for(int i=2;i<=n;i++)	dp[x][i]=1;
		for(int i=2;i<=n;i++)
		{
			x^=1,y^=1;
			sum=0;
			for(int j=i;j<=n;j++)
			{
				dp[x][j]=(dp[y][j]*j+sum)%mod;
				sum=(sum+dp[y][j])%mod;
			}
		}
		printf("%lld\n",dp[x][n]);
	}
	return 0;
}
