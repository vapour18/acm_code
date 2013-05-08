#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 50005;
const int inf = 111111111;
struct Edge{
	int v,next,w;
}edge[maxn*15];
int n,en,head[maxn],d1[maxn],d2[maxn],num[maxn];
bool vis[maxn];
void addedge(int u,int v,int w)
{
	edge[en].v = v;edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}
void dfs1(int u, int pre)
{
	vis[u] = 1;
	d1[u] = d2[u] = 0;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v,w = edge[i].w;
		if(v == pre) continue;
		dfs1(v,u);
		if(d1[u] < d1[v] + w)
		{
			d2[u] = d1[u];
			d1[u] = d1[v] + w;
		}
		else if(d2[u] < d1[v] + w)
			d2[u] = d1[v] + w;
	}
}
void dfs2(int u,int pre)
{
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v,w = edge[i].w;
		if(v == pre) continue;
		if(d1[u] > d1[v] + w) d1[v] = d1[u] + w;
		else if(d1[v] < d2[u] + w) d1[v] = d2[u] + w;
		else if(d2[v] < d2[u] + w) d2[v] = d2[u] + w;
		dfs2(v,u);
	}
}
int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i = 2; i <= n; i++)
		{
			scanf("%d%d",&a,&b);
			addedge(i,a,b);
			addedge(a,i,b);
		}
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
				dfs1(i,-1),dfs2(i,-1);
		}
		for(int i = 1; i <= n; i++)
			printf("%d\n",d1[i]);
	}
	return 0;
}