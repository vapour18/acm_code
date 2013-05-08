#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10005;
const int inf = 1111111111;
struct Edge{
	int v,next,w;
}edge[maxn*50];
struct Q{
	int tp,u;
}tmp;
int n,m;
int head[maxn],en;
void addedge(int u,int v,int w)
{
	edge[en].v = v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
	swap(u,v);
}
int spfa(int s,int t)
{
	queue<Q> q;
	bool vis[maxn][2];
	int dist[maxn][2];
	int u,v,w,tp;
	for(int i = 0; i <= n; i++)
	{
		vis[i][0]=vis[i][1] = 0;
		dist[i][0]=dist[i][1] = inf;
	}
	tmp.tp = 0,tmp.u = s;
	dist[s][0] = 0;
	q.push(tmp);
	tmp.tp = 1,tmp.u = s;
	dist[s][1] = 0;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		tp = tmp.tp, u = tmp.u;
		vis[u][tp] = 0;
		for(int e = head[u]; e!= -1;e = edge[e].next)
		{
			v = edge[e].v;
			w = edge[e].w;
			if(dist[v][w]>dist[u][tp]+(w != tp))
			{
				dist[v][w] = dist[u][tp]+(w != tp);
				if(!vis[v][w])
				{
					vis[v][w] = 1;
					tmp.tp = w,tmp.u = v;
					q.push(tmp);
				}
			}
			
		}
	}
	return min(dist[t][0],dist[t][1]);
}
int main()
{
	int u,v,s,t;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	en = 0;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v,1);
		addedge(v,u,0);
	}
	scanf("%d%d",&s,&t);
	printf("%d\n",spfa(s,t));
	return 0;
}