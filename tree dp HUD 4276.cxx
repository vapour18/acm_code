#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge{
	int v,w,next;
}edge[300];
int dp[115][515],value[115];
int n,t,head[105],en,tt;
inline void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
bool flag;
void dfs1(int u,int pre,int cost)
{
	if(flag)	return;
	if(u==n)
	{
		t-=cost;
		flag=1;
		return ;
	}
	for(int i=head[u];i!=-1&&!flag;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v!=pre)
		{
			dfs1(v,u,cost+edge[i].w);
			if(flag)	edge[i].w=0;
		}
	}
}
void dfs(int u,int pre)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v==pre)	continue;
		dfs(v,u);
		int cost=edge[i].w*2;
		for(int i=t;i>=cost;i--)
			for(int j=i-cost;j>=0;j--)
				dp[u][i]=max(dp[u][i],dp[u][j]+dp[v][i-j-cost]);
	}	
	for(int i=0;i<=t;i++)	dp[u][i]+=value[u];
}
int main()
{
	int u,v,w;
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		memset(head,-1,sizeof(head));
		en=0;
		flag=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&value[i]);
		dfs1(1,-1,0);
		if(t<0)
		{
			printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
			continue;
		}
		dfs(1,-1);
		int ans=dp[1][t];
		printf("%d\n",ans);
	}
}
