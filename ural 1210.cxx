//简单的最短路，读题和读入略纠结
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxn 1005
#define inf 1111111111
using namespace std;
struct Edge{
	int v,w,next;
}edge[30000];
int head[3000],en,n,dist[3000];
bool vis[3000]={0};
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
void spfa(int s)
{
	queue<int> q;
	for(int i=0;i<=n+50;i++)		dist[i]=inf;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(dist[v]>dist[u]+edge[i].w)
			{
				dist[v]=dist[u]+edge[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	int c,nexm,u,w,m;
	char str[5];
	scanf("%d",&c);
	memset(head,-1,sizeof(head));
	en=0;
	m=n=1;
	while(c)
	{
		scanf("%d",&nexm);
		for(int i=0;i<nexm;i++)
		{
			while(scanf("%d",&u)&&u)
			{
				scanf("%d",&w);
				addedge(n+u-1,n+m+i,w);

			}			
		}
		n+=m;
		m=nexm;
		if(c!=1)	scanf("%s",str);
		c--;
	}
	int ans=inf;
	spfa(1);
	for(int i=0;i<m;i++)
	{
		
		if(ans>dist[n+i])	ans=dist[n+i];	
	}

	printf("%d\n",ans);
}

