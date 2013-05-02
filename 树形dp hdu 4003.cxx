//题意:给一棵有根树,每条边与有边权.在根上放k个机器人,问遍历这棵树的最小边权和是多少
//贪心的方法想了很多都不行,只能是树形dp
//dp[i][j]表示以i为根的子树有j个机器人遍历的最小代价,dp[i][0]表示这棵子树只有一个机器人经过并且会回去
//然后按分组背包的形式去做,dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[v][k]+w*2),其中v为i的儿子
//初始化的条件为dp[i][j] = dp[v][0] + 2*w,这样就可以保证树被遍历
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 10005;
struct Edge{
	int v,next,w;
}edge[maxn*3];
int head[maxn],en,n,s,m;
int dp[maxn][15];
void addedge(int u,int v,int w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
	swap(u,v);
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	memset(head, -1 ,sizeof(head));
	memset(dp,0,sizeof(dp));
}
void dfs(int u,int pre)
{
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == pre) continue;
		dfs(v,u);
		for(int k = m; k >=0; k--)//分组背包
		{
			dp[u][k] += dp[v][0] + 2*edge[i].w;
			for(int j= 1; j <= k;j++)
				dp[u][k] = min(dp[u][k],dp[u][k-j]+dp[v][j]+j*edge[i].w);
		}
	}
}
int main()
{	
	int u,v,w;
	while(scanf("%d%d%d",&n,&s,&m)!=EOF)
	{
		init();
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		dfs(s,-1);
		printf("%d\n",dp[s][m]);
	}
	return 0;
}
