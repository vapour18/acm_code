#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
const int maxn=2005;
struct Edge
{
	int v,next;
}edge[100010];
int en,head[maxn],low[maxn],dfn[maxn],id[maxn],num,scc;
bool vis[maxn];
int n,m;
stack<int> sta;
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void tarjan(int v)
{
	dfn[v]=low[v]=num++;
	sta.push(v);
	vis[v]=1;
	for(int i=head[v];i!=-1;i=edge[i].next)
	{
		int x=edge[i].v;
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
	return;
}
bool solve()
{
	bool flag=1;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	for(int i=0;i<=2*(n-1);i++)//求强连通分量
	{
		if(!dfn[i])
			tarjan(i);
	}
	for(int i=0;i<n;i++)
	{
		if(id[i*2]==id[i*2+1])//判断是否矛盾
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int a,b,c,d;
	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		en=0;
		num=0,scc=1;
		if(!sta.empty())	sta.pop();
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(id,0,sizeof(id));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			addedge(a*2+c,b*2+1-d);
			addedge(b*2+d,a*2+1-c);
		}
		if(solve())	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
