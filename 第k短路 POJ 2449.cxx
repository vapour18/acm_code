//裸的第k短路,用优先队列加A*,A*算是一个重要优化,就当模板用吧
/* 所谓A*就是启发是搜索..说白了就是给BFS搜索一个顺序使得搜索更加合理减少无谓的搜索.
 也就是用一个值来表示这个值为f[x]..每次搜索取f[x]最小的拓展..
 .那么这个f[x]=h[x]+g[x]其中这个h[x]就是当前搜索时的代价..如求K段路这个就是前一个点的h[x']+边的长度...
 * 而g[x]是一个估价函数..估价函数要小于是对当前点到目标的代价的估计..这个估计必须小于等于实际值~~否则会出错...
 * A*的关键也就是构造g[x]..*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 111111111
#define maxn 1005
using namespace std;
struct node{
	int v,g,h;
	bool operator < (const node a) const
	{
		return a.h+a.g<h+g;
	}
}tmp,fr;
struct Edge{
	int v,w,next;
}edge[100005],redge[100005];
int head[maxn],rhead[maxn],en=0,rn=0;
int s,t,k,dist[maxn],n,m;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
void addredge(int u,int v,int w)
{
	redge[rn].v=v,redge[rn].w=w;
	redge[rn].next=rhead[u];
	rhead[u]=rn++;
}
void spfa(int s)//先找该点到终点的最短距离
{
	queue<int> q;
	bool vis[maxn]={0};
	int fr;
	for(int i=1;i<=n;i++)		dist[i]=inf;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		fr=q.front(),q.pop();
		vis[fr]=0;
		for(int e=rhead[fr];e!=-1;e=redge[e].next)
		{
			int v=redge[e].v;
			if(dist[v]>dist[fr]+redge[e].w)
			{
				dist[v]=dist[fr]+redge[e].w;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return;
}
int astar()
{
	priority_queue<node> q;
	int cnt[maxn]={0};
	tmp.v=s,tmp.h=0,tmp.g=0;
	q.push(tmp);
	if(s==t)	k++;//起点和终点相同是个大坑
	while(!q.empty())
	{
		fr=q.top(),q.pop();
		cnt[fr.v]++;
		if(cnt[t]==k)	return fr.g+fr.h;//终点入队列k次即第k短路
		if(cnt[fr.v]>k)		continue;
		for(int e=head[fr.v];e!=-1;e=edge[e].next)
		{
			int v=edge[e].v;
			tmp.v=v;
			tmp.h=fr.h+edge[e].w;
			tmp.g=dist[v];
			q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(rhead,-1,sizeof(rhead));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addredge(v,u,w);
	}
	scanf("%d%d%d",&s,&t,&k);
	spfa(t);
	if(dist[1]==inf)	printf("-1\n");
	else	printf("%d\n",astar());
	return 0;
}





