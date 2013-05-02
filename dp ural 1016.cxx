//题意抽的要死的dp
//加滚动数组优化
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1005
using namespace std;
const double d=sqrt(2.0);
bool map[maxn][maxn];
double dp[2][maxn];
int main()
{
	int n,m,x,y,k;
	memset(map,0,sizeof(map));
	memset(dp,0,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	m++,n++;
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
	for(int i=2;i<=max(n,m);i++)	dp[0][i]=i-1;
	for(int i=2;i<=n;i++)//0 代表上一层，1代表当前层
	{
		dp[1][1]=i-1;
		for(int j=2;j<=m;j++)
			if(map[i-1][j-1])
				dp[1][j]=min(min(dp[0][j-1]+d,dp[1][j-1]+1),dp[0][j]+1);
			else
				dp[1][j]=min(dp[1][j-1],dp[0][j])+1;
		memcpy(dp[0],dp[1],sizeof(dp[1]));
	}
	printf("%.0f\n",dp[0][m]*100);
}
