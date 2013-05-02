//题意是中文，还不清晰==，意思是，有任意一个队员走，队长必须留下，队长走，两个队员必须同时留下
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=7005;
struct Edge{
	int v,next;
}edge[1000005];
int head[maxn],low[maxn],dfn[maxn],id[maxn];
int en,m,n,num,scc;
bool vis[maxn];
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
		do
		{
			x=sta.top();
			sta.pop();
			vis[x]=0;
			id[x]=scc;
		}while(x!=v);
	}
}
bool solve()
{
	bool flag=1;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	scc=1,num=0;
	while(!sta.empty())	sta.pop();
	for(int i=0;i<2*n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<n;i++)
	{
		if(id[i*2]==id[i*2+1])
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int a,b,c,t;
	while(scanf("%d%d",&t,&m)!=EOF)
	{
		memset(head,-1,sizeof(head));
		en=0;
		n=t*3;
		for(int i=0;i<t;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addedge(a+n,b);
			addedge(a+n,c);
			addedge(b+n,a);
			addedge(c+n,a);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b+n);
			addedge(b,a+n);
		}
		if(solve())	printf("yes\n");
		else	printf("no\n");
	}
	return 0;
}




