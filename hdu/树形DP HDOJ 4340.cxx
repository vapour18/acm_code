//树形DP
//注意是多组数据!
/*显然题中给图的是一颗树。问题可以抽象成对树的每个点都染色，有两中颜色可以选择。
我们可以知道，如果某一个连通的点集染的是同一种颜色，则这个集合中只要而且必须有一个点取完整的费用，
其他的点都只需要对应费用的一半。
状态：dp[i][j][k] (0 <= i <= n, 0<=j<=1, 0 <= k <= 1) 表示以i为根的子树的费用，其中i节点被染成了
第j种颜色，且子树中与i染成同一种颜色的与i连通的点集有k个点选取了完整的费用。
若选取1为根节点，则最后需要的结果为： min(dp[1][0][1], dp[1][1][1]}。
状态转移方程：
v为i节点的儿子节点。令 S = sum{min(dp[v][j][0], dp[v][1-j][1])}
det = min{dp[v][j][1] - min(dp[v][j][0], dp[v][1-j][1])}; 
dp[i][j][0] = cost[i][j]/2 + S; 
dp[i][j][1] = min(cost[i][j] + S， cost[i][j]/2 + S + det); 

*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#define maxn 105
#define inf 2e9
using namespace std;
vector<int> g[maxn];
int cost[maxn][2],dp[maxn][2][2];
bool vis[maxn]={0};
void dfs(int x)
{
	if(g[x].empty())//叶子节点,dp的起始点
	{
		dp[x][0][0]=cost[x][0]/2;
		dp[x][0][1]=cost[x][0];
		dp[x][1][0]=cost[x][1]/2;
		dp[x][1][1]=cost[x][1];
		return;
	}
	for(int i=0;i<g[x].size();i++)
		dfs(g[x][i]);
	for(int i=0;i<=1;i++)
	{
		int s=0,det=inf;
		for(int j=0;j<g[x].size();j++)
		{
			int v=g[x][j];
			s+=min(dp[v][i][0],dp[v][1-i][1]);//i征服该点的子节点需要的最短时间
			det=min(det,dp[v][i][1]-min(dp[v][i][0],dp[v][1-i][1]));//变色,为与父亲节点颜色不同做准备
		}
		dp[x][i][0]=cost[x][i]/2+s;//与父亲节点同色
		dp[x][i][1]=min(cost[x][i]+s,cost[x][i]/2+s+det);//与父亲节点不同色
	}
}
int main()
{
	int u,v,root=0,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)	scanf("%d",&cost[i][0]);
		for(int i=1;i<=n;i++)	scanf("%d",&cost[i][1]);
		for(int i=1;i<n;i++)
		{
			memset(vis,0,sizeof(vis));
			scanf("%d%d",&u,&v);
			if(i==1)	root=u;
			if(!vis[v])//建一棵树
			{
				g[u].push_back(v);
				vis[u]=1;
			}
			else	g[v].push_back(u);
		}
		dfs(root);
		printf("%d\n",min(dp[root][0][1],dp[root][1][1]));
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
	return 0;
}




