#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define inf 1111111111
using namespace std;
const int maxn=155*2;
struct Edge{
	int u,v,cap,cost,next;
}edge[maxn*maxn*4];
int head[maxn],en;
inline void addedge(int u,int v,int cap,int cost)
{
	edge[en].u=u,edge[en].v=v,edge[en].cap=cap,edge[en].cost=cost;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].u=u,edge[en].v=v,edge[en].cap=0,edge[en].cost=-cost;
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
	int n;
	int g[155][155],sum[155]={0};
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	en=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			sum[j]+=g[i][j];
	for(int i=1;i<=n;i++)
	{
		addedge(0,i,1,0);
		for(int j=1;j<=n;j++)
		{
			addedge(i,j+n,1,sum[i]-g[i][j]);	
			//cout<<sum[i]-g[i][j]<<endl;		
		}
		addedge(i+n,2*n+1,1,0);
	}
	printf("%d\n",mcmf(0,2*n+1));
	return 0;
}
