//有两面的圆画线段，可以在正面，也可以在反面，问是否能不相交
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=5005;
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
	low[v]=dfn[v]=num++;
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
	for(int i=0;i<2*m;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<m;i++)
	{
		if(id[i*2]==id[i*2+m])
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int a[maxn],b[maxn];
	scanf("%d%d",&n,&m);
	en=0;
	memset(head,-1,sizeof(head));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>b[i])	swap(a[i],b[i]);
	}
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
		{
			if((a[i]<a[j]&&b[i]<b[j]&&a[j]<b[i])||(a[i]>a[j]&&b[i]>b[j]&&b[j]>a[i]))
			{
				addedge(i,j+m);
				addedge(i+m,j);
				addedge(j+m,i);
				addedge(j,i+m);
			}
		}
	if(solve())
		printf("panda is telling the truth...\n");
	else
		printf("the evil panda is lying again");
	return 0;
}




