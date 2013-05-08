//悬线法求最大子矩阵
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int g[maxn][maxn],dp[maxn][maxn],r[maxn],l[maxn],h[maxn];
int ans,n,m;
void solve(int x)
{
	int tl,tr;
	for(int i=1;i<=m;i++)
		r[i]=m,l[i]=1,h[i]=0;
	for(int i=1;i<=n;i++)//从上到下遍历
	{
		tl=1,tr=m;
		for(int j=1;j<=m;j++)
		{
			if(x==g[i][j])//颜色相同
			{
				h[j]++;//记录当前高度
				if(l[j]<tl)	l[j]=tl;
			}
			else
				h[j]=0,r[j]=m,l[j]=1,tl=j+1;//不合法时要修改当前左起始点
		}
		for(int j=m;j>0;j--)
		{
			if(h[j])
			{
				if(r[j]>tr)	r[j]=tr;
				ans=max(ans,(h[j]+r[j]-l[j]+1)*2);//计算当前答案是否最佳
			}
			else tr=j-1;//不合法要修改右终点,即右边左移
		}
	}
}
int main()
{
	char str[maxn];
	int t;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",&str[1]);
			for(int j=1;j<=m;j++)
			{
				g[i][j]=(str[j]=='B');
			}
		}
		int cnt;
		for(int i=1;i<=n;i++)//找出白蓝相间的最大块
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=1;//注意初始化!!
				if(g[i][j-1]!=g[i][j]&&g[i-1][j]!=g[i][j])
				{
					cnt=min(dp[i][j-1],dp[i-1][j]);
					if(g[i][j-1]!=g[i-1][j]||g[i-cnt][j-cnt]==g[i][j])//判断是否能构成边长可加一正方形
						cnt++;
					dp[i][j]=max(dp[i][j],cnt);
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans=max(ans,dp[i][j]*4);
		solve(0);
		solve(1);
		printf("Case #%d: ",ca);
		printf("%d\n",ans);
	}
}




