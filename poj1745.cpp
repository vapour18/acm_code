#include <cstdio>
#include <cstdio>
#include <cstring>
int main()
{
	//(a+b+c+d.....)%k=(a%k+b%k+c%k+d%k...)%k
	//dp[i][j]	前i个数运算有余数j
	int dp[10005][201],num[10005],n,k;
	while(scanf("%d %d", &n, &k) !=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			num[i]=num[i]%k;// 只有k种余数
		}
		memset(dp,0,sizeof(dp));
		dp[0][num[0]%k+100]=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<201;j++)
			{
				if(dp[i-1][j])
				{
					dp[i][(j-100+num[i])%k+100]=1;//两种情况，加或者减
					dp[i][(j-100-num[i])%k+100]=1;
				}
			}
		}
		 if(dp[n - 1][100]) printf("Divisible\n");
        else printf("Not divisible\n");
	}
}
