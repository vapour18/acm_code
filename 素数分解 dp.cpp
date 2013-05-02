/*题意：给n个数字，按顺序选出最多的数字，使得相邻的任意两个不互质
思路：可以用dp的思想，对于第i+1个数，找出这个数的每个素因子和记录的素因子的最大值，即dp[num[i+1]的每个素因子]=max(dp[0~cnt]的每个素因子)+1；
所以可以先预处理出每个数的素因子
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100005;
int prim[maxn],dp[maxn],have[maxn][15],cnt，p[maxn];
//素数分解模板
void init()
{
	for(int i=2;i<maxn;i++)
	{
		if(!prim[i])
		{
			++have[i][0];
			p[++cnt]=i;//记录素数，并给其编号
			have[i][have[i][0]]=cnt;
			for(int j=2;i*j<maxn;j++)
			{
				int tmp=i*j;
				prim[tmp]=1;
				have[tmp][++have[tmp][0]]=cnt;
			}
		}
	}
}

int main()
{
	int ca,n,a,tmp;
	scanf("%d",&ca);
	init();
	while(ca--)
	{
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			tmp=0;
			for(int j=1;j<=have[a][0];j++)
				tmp=max(tmp,dp[have[a][j]]);
			tmp+=1;
			for(int j=1;j<=have[a][0];j++)
				dp[have[a][j]]=tmp;
		}
		int ans=1;
		for(int i=1;i<=cnt;i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
