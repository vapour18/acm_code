/*最小点权覆盖,把一个点拆成两个,一个连源点,一个连汇点*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 205*205
#define inf 1e9
using namespace std;
int head[maxn],en,n,m,s,t;
int gap[maxn],h[maxn];
bool vis[maxn];
struct ED{
	int v,next,w;
}edge[maxn*20];
inline void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
}
int dfs(int pos ,int cost)
{
	if(pos==t)
		return cost;
	int minh=n-1,lv=cost,d;
	for(int j=head[pos];j!=-1;j=edge[j].next)
	{
		int v=edge[j].v,w=edge[j].w;
		if(w>0)
		{
			if(h[v]+1==h[pos])
			{
				d=min(lv,w);
				d=dfs(v,d);
				edge[j].w-=d;
				edge[j^1].w+=d;
				lv-=d;
				if(h[s]>=n)
					return cost-lv;
				if(lv==0)
					break;
			}
			if(h[v]<minh)
				minh=h[v];
		}
	}
	if(lv==cost)
	{
		gap[h[pos]]--;
		if(gap[h[pos]]==0)
			h[s]=n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int st,int ed)
{
	
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[st]<n)
		ret+=dfs(st,inf);
	return ret;
}
void find(int x)
{
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].w&&!vis[edge[i].v])
			find(edge[i].v);
	}
}
int main()
{
	int w,u,v;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	s=0,t=n*2+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		addedge(i+n,t,w);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		addedge(s,i,w);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v+n,inf);
	}
	int nn=n;
	n=1+t;
	printf("%d\n",sap(s,t));
	find(s);
	int ans=0;
	n=nn;
	for(int i=1;i<=n;i++)
		ans+=(!vis[i])+vis[i+n];
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])	printf("%d -\n",i);
		if(vis[i+n])	printf("%d +\n",i);
	}
	return 0;
}









