//普通的2-sat，就是要输出解
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
const int maxn=5005;
int n,m;
int low[maxn],dfn[maxn],id[maxn];
int color[maxn],ha[maxn],ind[maxn];
bool vis[maxn];
int num,scc;
stack<int> sta;
queue<int> q;
vector<int> g[maxn],dag[maxn];
void tarjan(int v)//求强连通分量
{
	low[v]=dfn[v]=++num;
	sta.push(v);
	vis[v]=1;
	for(int i=0;i<(int)g[v].size();i++)
	{
		int x=g[v][i];
		if(!dfn[x])
		{
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else if(vis[x])
			low[v]=min(low[v],dfn[x]);
	}
	if(low[v]==dfn[v])
	{
		scc++;
		int x;
		do
		{
			x=sta.top();
			sta.pop();
			vis[x]=0;
			id[x]=scc;
		}while(x!=v);
	}
}
void ini()
{
	scc=1,num=0;
	for(int i=0;i<2*n;i++)
	{
		g[i].clear();
		dag[i].clear();
	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(ind,0,sizeof(ind));
	memset(color,0,sizeof(color));
	while(!sta.empty())	sta.pop();
	while(!q.empty())	q.pop();	
}
void build()
{//建图
	for(int u=0;u<2*n;u++)
	{
		for(int i=0;i<(int)g[u].size();i++)
		{
			int v=g[u][i];
			if(id[u]!=id[v])	
			{
				dag[id[v]].push_back(id[u]);
				ind[id[u]]++;
			}
		}
	}
}
void topsort()
{//拓扑排序，染色
	for(int i=1;i<=scc;i++)
		if(ind[i]==0)	q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(!color[u])	color[u]=1,color[ha[u]]=2;
		for(int i=0;i<(int)dag[u].size();i++)
		{//更改与之相邻点的出度
			int v=dag[u][i];
			ind[v]--;
			if(ind[v]==0)	q.push(v);
		}
	}
}
void solve()
{
	for(int i=0;i<2*n;i++)
		if(!dfn[i])	tarjan(i);
	for(int i=0;i<n;i++)
		if(id[2*i]==id[2*i+1])
		{//不存在符合要求的
			printf("bad luck\n");
			return;
		}	
		else
		{//记录下对应的点，可认为是hash
			ha[id[2*i]]=id[2*i+1];
			ha[id[2*i+1]]=id[2*i];
		}
	build();
	topsort();
	//输出解
	for(int i=2;i<2*n;i+=2)
	{
		if(color[id[i]]==color[id[0]])
			printf("%dw ",i/2);
		else	printf("%dh ",i/2);
	}
	printf("\n");
}
int main()
{
	char c1,c2;
	int x,y,a0,b0,a1,b1;
	while(scanf("%d%d",&n,&m)&&n+m)
	{
		ini();
		while(m--)
		{
			scanf("%d%c %d%c",&x,&c1,&y,&c2);
			if(c1=='h')	
				a0=2*x,a1=2*x+1;
			else	a1=2*x,a0=2*x+1;
			if(c2=='h')	
				b0=2*y,b1=2*y+1;
			else	b1=2*y,b0=2*y+1;
			g[a1].push_back(b0);
			g[b1].push_back(a0);
		}
		g[0].push_back(1);
		solve();
	}
	return 0;
}
