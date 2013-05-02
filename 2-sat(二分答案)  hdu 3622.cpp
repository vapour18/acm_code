//注意精度，先不要开方
//建图，二分答案。典型2-sat建图
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#define eps 1e-3
using namespace std;
const int maxn=1005;
struct Edge{
	int v,next;
}edge[1000005];
int head[maxn],low[maxn],dfn[maxn],id[maxn];
int en,m,n,num,scc;
int x[maxn],y[maxn];
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
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(id[i]==id[i+n])
		{
			flag=0;
			break;
		}
	return flag;
}

void init()
{
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	while(!sta.empty())	sta.pop();
	num=0,scc=1;
	en=0;
}
double cal(double x1,double y1,double x2,double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void build(double m)
{
	int u,v;
	for(int i=1;i<=n*2;i++)
	{
		for(int j=i+1;j<=n*2;j++)
		{
			if(i+n==j)	continue;
			if(cal(x[i],y[i],x[j],y[j])<m)
			{
				if(i<=n)	u=i+n;
				else u=i-n;
				if(j<=n)	v=j+n;
				else	v=j-n;
				addedge(i,v);
				addedge(j,u);
			}
		}
	}
}
int main()
{
	double l,r,mid,ans;
	
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",&x[i],&y[i],&x[i+n],&y[i+n]);
		l=0,r=20000*20000;
		while(r-l>=eps)
		{
			init();
			mid=(l+r)/2;
			build(mid);
			if(solve())	ans=mid,l=mid+eps;
			else r=mid-eps;
		}
		printf("%.2f\n",sqrt(ans)/2);
	}
	return 0;
}






