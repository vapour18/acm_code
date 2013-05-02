#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn=100005;
const int inf=1111111111;
struct Edge{
	int v,next;
}edge[maxn*33];
int n,m,en;
int w[maxn],head[maxn],ind[maxn],ond[maxn],dp[maxn];
void addedge(int u,int v)
{
	edge[en].v=v; 
	edge[en].next=head[u];
	head[u]=en++;
}
void init()
{
	memset(head,-1,sizeof(head));
	memset(ind,0,sizeof(ind));
	memset(ond,0,sizeof(ond));
	for(int i=0;i<=n;i++)	dp[i]=-inf;
	en=0;
}
void solve()
{
	int u;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(ind[i]==0)	q.push(i);
	while(!q.empty())
	{
		u=q.front(),q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			ind[v]--;
			dp[v]=max(dp[v],dp[u]+w[v]);
			if(ind[v]==0)q.push(v);
		}
	}
}
int main()
{
	int u,v;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=1;i<=n;i++)	scanf("%d",&w[i]);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			ind[v]++,ond[u]++;
		}
		for(int i=1;i<=n;i++)	
			if(ind[i]==0)	dp[i]=w[i];
		solve();
		int ans=-inf;
		for(int i=1;i<=n;i++)
			if(ond[i]==0)	ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}