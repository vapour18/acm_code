#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
const int maxm = 300005;
const int maxn = 50005;
const int inf = 1111111111;
using namespace std;
struct Edge{
	int v,w,next;
}edge[maxm*3];
struct Node{
	int a,w;
	bool operator < (const Node &a) const
	{
		return a.w<w;
	}
}tmp,te;

int n,m;
int head[maxn],en;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
int dij(int s)
{
	int dis[maxn];
	priority_queue<Node> q;
	for(int i = 0;i <= n;i++)
		dis[i]=inf;
	bool vis[maxn]={0};
	dis[s]=0;
	te.a=s,te.w=0;
	q.push(te);
	while(!q.empty())
	{
		te=q.top();
		q.pop();
		if(!vis[te.a])
		{
			for(int i = head[te.a];i != -1;i = edge[i].next)
			{
				if(!vis[edge[i].v]&&dis[edge[i].v]>dis[te.a]+edge[i].w)
				{
					dis[edge[i].v] = dis[te.a]+edge[i].w;
					tmp.a = edge[i].v;
					tmp.w = dis[edge[i].v];
					q.push(tmp);
				}
			}
			vis[te.a]=1;
		}
	}
	return dis[n];
}

int main()
{
	int u,v,w;
	memset(head,-1,sizeof(head));
	en = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	printf("%d\n",dij(1));
}