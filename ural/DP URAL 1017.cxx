
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long dp[510][510],ans;
int main()
{
	int n;
	
	scanf("%d",&n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
		for(int j=0;j<i;j++)
			dp[i][j]=dp[i-1][j];
	}
	
	printf("%lld\n",dp[n][n]-1);
}
