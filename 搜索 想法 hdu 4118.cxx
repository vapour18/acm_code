#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 100005
using namespace std;
struct EDGE{
	int v,w,next;
}edge[maxn*2];
int head[maxn],en,n;
int ind[maxn];
long long ans;
bool vis[maxn];
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
void init()
{
	memset(head,-1,sizeof(head));
	memset(ind,0,sizeof(ind));
	memset(vis,0,sizeof(vis));
	en=0;
	ans=0;
}
int dfs(int u)
{
	int son=1,cnt;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!vis[v])
		{
			cnt=dfs(v);
			ans+=min(cnt,n-cnt)*2LL*edge[i].w;
			son+=cnt;
		}
	}
	
	return son;
}
int main()
{
	int cas,u,v,w;
	scanf("%d",&cas);
	for(int ca=1;ca<=cas;ca++)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{	
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
			ind[u]++,ind[v]++;
		}
		printf("Case #%d: ",ca);
		if(n==2)
		{
			printf("%d\n",2*edge[1].w);
			continue;
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
