#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<stack>
#include<iostream>
using namespace std;
const int maxn=6005;
struct Edge{
	int v,next;
}edge[1000005];
int head[maxn],low[maxn],dfn[maxn],id[maxn];
int en,n,num,scc,add=32;
bool vis[maxn],flag;
stack<int> sta;
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void tarjan(int v)
{
	low[v]=dfn[v]=++num;
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
		do{
			x=sta.top(),sta.pop();
			vis[x]=0;
			id[x]=scc;
		}while(x!=v);
	}
}
void solve()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	while(!sta.empty())	sta.pop();
	num=0,scc=1;
	for(int i=0;i<2*(n-1);i++)
		if(!dfn[i])	tarjan(i);
	for(int i=0;i<n;i++)
	{
		if(id[i*2]==id[i*2+1])
		{
			flag=0;
			break;
		}
	}
	
}
void build(int tp,int m,int x,int y)
{
	if(tp==1)
	{
		if(m==0)
		{			
			addedge(2*x+1,2*x);
			addedge(2*y+1,2*y);
		}
		else
		{
			addedge(2*x,2*y+1);
			addedge(2*y,2*x+1);
		}
	}
	else if(tp==2)
	{
		if(m==0)
		{
			addedge(2*x+1,2*y);
			addedge(2*y+1,2*x);
		}
		else
		{
			addedge(2*x,2*x+1);
			addedge(2*y,2*x+1);
		}
	}
	else
	{
		if(m==0)
		{
			addedge(2*x,2*y);
			addedge(2*x+1,2*y+1);
			addedge(2*y,2*x);
			addedge(2*y+1,2*x+1);
		}
		else
		{
			addedge(2*x,2*y+1);
			addedge(2*x+1,2*y);
			addedge(2*y,2*x+1);
			addedge(2*y+1,2*x);
		}
	}
}
int main()
{
	int b[505][505];
	
	while(scanf("%d",&n)!=EOF)
	{
		flag=1;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&b[i][j]);
		for(int i=0;i<n&&flag;i++)
		{
			if(b[i][i])	flag=0;
			for(int j=i+1;j<n&&flag;j++)
				if(b[i][j]!=b[j][i])
					flag=0;
		}
		for(int bit=0;bit<31&&flag;bit++)
		{
			en=0;
			memset(head,-1,sizeof(head));
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j) continue;
					int x=b[i][j]&(1<<bit),tp;

					if(i%2==1&&j%2==1) tp=1;
					else if(i%2==0&&j%2==0)	tp=2;
					else tp=3;
					build(tp,x,i,j);
				}
			}
			solve();
		}
		if(flag)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
