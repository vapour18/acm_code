/*
Ҫ�������ϵ�Ӳ�����ӣ���Ҫ�ù��ӷ��õ�λ�����屣�ֵ���
dp[i][j]��ʾ����������i��Ӳ��ʱ������ܵ���j��Ӳ�ҵ������
����dp[i][j]=dp[i-1][j]*j+sum(dp[i-1][k])(i<k<j);
����Ҫ�ù��������Ż��������mle
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
