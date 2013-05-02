//给n组钥匙和m组门，每组两个，钥匙每组只能取一把， 门开一扇就能通过，但要按顺序，求最多能开几扇门
//将一扇门拆成开与不开两种情况，再二分答案
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
int akey[maxn],bkey[maxn],adoor[maxn],bdoor[maxn];
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
		else if(vis[x])// 如果节点v还在栈内
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
	while(!sta.empty())	sta.pop();
	num=0,scc=1;
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=2*n;i++)
		if(id[i]==id[i+2*n])
		{
			flag=0;
			break;
		}
	return flag;
}
void build(int m)
{
	en=0;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
	{
		addedge(akey[i],bkey[i]+2*n);
		addedge(bkey[i],akey[i]+2*n);
	}
	for(int i=1;i<=m;i++)
	{
		addedge(adoor[i]+2*n,bdoor[i]);
		addedge(bdoor[i]+2*n,adoor[i]);
	}
}
int main()
{
	int l,r,mid,ans;
	while(scanf("%d%d",&n,&m)&&n+m)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&akey[i],&bkey[i]);
			akey[i]++,bkey[i]++;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&adoor[i],&bdoor[i]);
			adoor[i]++,bdoor[i]++;
		}
		l=0,r=m;
		ans=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			//cout<<mid<<endl;
			build(mid);
			if(solve())	ans=max(mid,ans),l=mid+1;
			else	r=mid-1;
		}
		printf("%d\n",ans);
	}	
	return 0;
}



