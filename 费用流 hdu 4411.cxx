#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxn 1000
#define inf 1000000
using namespace std;
struct EDGE{
	int u,v,cap,next,cost;
}edge[300000*2];
int head[maxn],en;
int g[115][115];
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
		bool vis[maxn]={0};
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
	int n,m,w,s,t;
	int a,b,c;
	while(scanf("%d%d%d",&n,&m,&w)&&(n+m+w))
	{
		memset(head,-1,sizeof(head));
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				g[i][j]=inf;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(g[a][b]>c)	g[a][b]=g[b][a]=c;
		}
		for(int k=0;k<=n;k++)
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		s=n*2+1,t=s+1;
		addedge(s,0,w,0);
		addedge(0,t,w,0);//不出发的队伍相当与直接回到终点
		for(int i=1;i<=n;i++)
		{
			addedge(0,i,1,g[0][i]);
			addedge(i,i+n,1,-inf);//加很小的费用保证一定往这边流！
			addedge(i+n,t,1,g[i][0]);
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				addedge(i+n,j,1,g[i][j]);
		printf("%d\n",mcmf(s,t)+inf*n);
	}
	return 0;
}
