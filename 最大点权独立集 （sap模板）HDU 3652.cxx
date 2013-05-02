#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 4000
#define inf 1111111111
using namespace std;
struct Edge{
	int v,next,w;
}edge[200000];
int head[60000],map[160][160],en;
int gap[60000],h[60000];//gap这个高度的有几个，h该点的高度
int n,m,k,node,s,t,a,sum;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
}
int dfs(int s,int t,int pos,int n,int cost)
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
				d=dfs(s,t,v,n,d);
				edge[j].w-=d, edge[j^1].w+=d;
				lv-=d;
				if(h[s]>=n)	return cost-lv;
				if(lv==0)	break;
			}
			if(h[v]<minh)	minh=h[v];
		}
	}
	if(lv==cost)
	{
		gap[h[pos]]--;
		if(gap[h[pos]]==0)	h[s]=n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int st,int ed,int n)
{
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[st]<n)
		ret+=dfs(st,ed,st,n,inf);
	return ret;
}
int main()
{
	
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		sum=en=0;
		s=0,t=n*m+1;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&map[i][j]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				node=(i-1)*m+j;
				a=map[i][j];
				sum+=a;
				if((i+j)%2)
				{
					addedge(s,node,a);
					if(i>1)	addedge(node,node-m,2*(a&map[i-1][j]));
					if(i<n)	addedge(node,node+m,2*(a&map[i+1][j]));
					if(j>1)	addedge(node,node-1,2*(a&map[i][j-1]));
					if(j<m)	addedge(node,node+1,2*(a&map[i][j+1]));
				}
				else addedge(node,t,a);
			}
		}
		int x,y;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&x,&y);
			node=(x-1)*m+y;
			if((x+y)%2)
				addedge(s,node,inf);
			else
				addedge(node,t,inf);
		}
		printf("%d\n",sum-sap(s,t,t+1));
	}
	return 0;
}
