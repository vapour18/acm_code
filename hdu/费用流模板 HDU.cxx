#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1105
#define inf 99999999
using namespace std;
struct EDGE{
	int u,v,cap,next,cost,flow;
}edge[1300000*2];
int n,m,k,p;
int head[maxn],en;
inline void addedge(int u,int v,int cap,int cost)
{
	edge[en].u=u,edge[en].v=v,edge[en].cap=cap,edge[en].cost=cost;
	edge[en].flow=0;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].u=u,edge[en].v=v,edge[en].cap=0,edge[en].cost=-cost;
	edge[en].flow=0;
	edge[en].next=head[u];
	head[u]=en++;
}

int mcmf(int s,int t)
{
	int c=0,f=0,v;
	queue<int> q;
	int dis[maxn],pre[maxn];
	while(1)
	{
		bool vis[maxn];
		memset(vis,0,sizeof(vis));
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<=t;i++)
			dis[i]=(i==s? 0:inf);
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			vis[u]=0;
			for(int i=head[u];i!=-1;i=edge[i].next)
			{
				v=edge[i].v;
				if(edge[i].cap&&dis[v]>dis[u]+edge[i].cost)
				{
					dis[v]=dis[u]+edge[i].cost;
					pre[v]=i;
					if(!vis[v])
					{
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
		if(dis[t]==inf)	break;
		int a=inf;
		for(int i=pre[t];i!=-1;i=pre[edge[i].u])
			if(edge[i].cap<a)
				a=edge[i].cap;
		f+=a;
		for(int i=pre[t];i!=-1;i=pre[edge[i].u])
		{
			edge[i].cap-=a;
			edge[i^1].cap+=a;
		}
		c+=dis[t]*a;
	}
	return c;
}
int main()
{
	int u,v,w,s,t;
	while(scanf("%d%d%d%d",&n,&m,&k,&p)!=EOF)
	{
		s=0,t=n+m+1;
		en=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&u);
			addedge(s,u,1,0);
			addedge(u,s,1,0);
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,inf,w);
			addedge(v,u,inf,w);
		}
		for(int i=1;i<=p;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(v,u+m,1,w);
		}
		for(int i=1;i<=n;i++)
			addedge(i+m,t,1,0),addedge(t,i+m,1,0);
		printf("%d\n",mcmf(s,t));
	}
	return 0;
}
