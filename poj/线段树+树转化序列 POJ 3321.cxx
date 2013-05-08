#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 100005
using namespace std;
struct Edge{
	int v,next;
}edge[maxn*2];
int ri[maxn],le[maxn],head[maxn],sum[maxn<<2];
int en,sn;
bool vis[maxn];
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int x)
{
	le[x]=++sn;
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
		if(!vis[edge[i].v])
			dfs(edge[i].v);
	ri[x]=sn;
}
void pushup(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int p,int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=(1^sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	if(p<=m)	update(p,lson);
	else	update(p,rson);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{

	if(L<=l&&r<=R)
	{
		return sum[rt];
	}
	int m=(l+r)>>1;
	int ret = 0;
	if (L<=m) ret+=query(L,R,lson);
	if (R>m)ret+=query(L,R,rson);
	return ret;
}
int main()
{
	int n,m,u,v,q;
	char str[3];
	while(scanf("%d",&n)!=EOF)
	{
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		en=sn=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1);
		build(1,sn,1);
		scanf("%d",&m);
		int ans;
		while(m--)
		{
			scanf("%s%d",str,&q);
			if(str[0]=='Q')
			{
				ans=query(le[q],ri[q],1,sn,1);
				printf("%d\n",ans);
			}
			if(str[0]=='C')
				update(le[q],1,sn,1);
		}
	}
	return 0;
}



