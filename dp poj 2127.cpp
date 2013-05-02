//求最长上升公共子序列
//在求最长公共子序列的基础上求最长上升子序列
//dp[i][j]: 以a[i]为结尾的两个串的最长上升公共子序列，所以说a是基准串
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=505;
int a[maxn],b[maxn],dp[maxn][maxn],pre[maxn][maxn];
int n,m;	
void output(int pos,int m)
{
	if(pos==0||m==0)	return;
	if(a[pos]!=b[m])	output(pos,m-1);//因为a[pos]一定要用到
	else
	{
		for(int i=pos-1;i>0;i--)
		{
			if(a[i]<a[pos]&&dp[i][m]+1==dp[pos][m])
			{
				output(i,m);
				break;
			}
		}
		printf("%d ",a[pos]);
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)	scanf("%d",&b[i]);
		memset(dp,0,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i]==b[j])
				{
					dp[i][j]=max(dp[i][j],1);
					for(int k=1;k<i;k++)
					{
						if(a[k]<a[i]&&dp[i][j]<dp[k][j]+1)
							dp[i][j]=dp[k][j-1]+1;
					}
				}
				else dp[i][j]=dp[i][j-1];
			}
		}
		int pos=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(dp[i][m]>ans)
			{
				ans=dp[i][m];
				pos=i;
			}
		}
		printf("%d\n",ans);
		output(pos,m);
		printf("\n");
	}
	return 0;
}