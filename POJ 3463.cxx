#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 111111111
#define maxn 1005
using namespace std;

struct Edge{
	int v,w,next;
}edge[10005];
int head[maxn],en=0;
int s,t,dist[maxn][2],way[maxn][2],n,m;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
int dijstra()
{
	bool vis[maxn][2],flag;
	for(int i=0;i<=n;i++)	
	{
		dist[i][0]=dist[i][1]=inf;
		way[i][0]=way[i][1]=0;
		vis[i][0]=vis[i][1]=0;
	}
	dist[s][0]=0,way[s][0]=1;
	for(int k=1;k<=2*n;k++)
	{
		int mi=inf,x;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i][0]&&mi>dist[i][0])
			{
				mi=dist[i][0];
				x=i;
				flag=0;
			}
			else if(!vis[i][1]&&mi>dist[i][1])
			{
				mi=dist[i][1];
				x=i;
				flag=1;
			}
		}
		if(mi==inf)	break;
		vis[x][flag]=1;
		for(int i=head[x];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(dist[v][0]>mi+edge[i].w)
			{
				dist[v][1]=dist[v][0];
				way[v][1]=way[v][0];
				dist[v][0]=mi+edge[i].w;
				way[v][0]=way[x][flag];
			}
			else if(dist[v][0]==mi+edge[i].w)
				way[v][0]++;
			else if(dist[v][1]>mi+edge[i].w)
			{
				dist[v][1]=mi+edge[i].w;
				way[v][1]=way[x][flag];
			}
			else if(dist[v][1]==mi+edge[i].w)
				way[v][1]++;
		}
	}
	if(dist[t][0]==dist[t][1]-1)	return way[t][0]+way[t][1];
	else	return way[t][0];
}
int main()
{
	int u,v,w,ca;
	scanf("%d",&ca);
	while(ca--)
	{
		en=0;
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));

		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		scanf("%d%d",&s,&t);
		printf("%d\n",dijstra());
	}
	return 0;
}
