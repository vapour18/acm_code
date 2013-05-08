//求最小割，并按字典序输出割边
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=40000;
const int inf=1111111111;
struct Edge{
	int v,next;
	int w;
}edge[maxn*2];
int head[500],en;
int h[500],gap[500];
int g[500][500],ng[500][500];
int s,t,n;
int a,b,c;
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
void buildgraph()
{
	memset(head,-1,sizeof(head));
	en=0;
	for(int i=1;i<=n;i++)
	{
		addedge(i,i+n,1);
		for(int j=1;j<=n;j++)
			if(i!=j&&g[i][j])
				addedge(i+n,j,inf);
	}
	addedge(s,s+n,inf);
	addedge(t-n,t,inf);
}
void change(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ng[i][j]=g[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==x||j==x)	g[i][j]=0;
}
int main()
{
	int flow,tmp,ans[400],num;
	scanf("%d%d%d",&n,&a,&b);
	s=a,t=b+n;
	num=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	if(g[a][b])	printf("NO ANSWER!\n");
	else
	{
		buildgraph();
		flow=sap(s,t,2*n);
		printf("%d\n",flow);
		for(int i=1;i<=n;i++)
		{
			if(i==a||i==b)	continue;
			change(i);
			buildgraph();
			tmp=sap(s,t,2*n);
			if(tmp<flow)
			{
				flow=tmp;//更改最大流
				ans[num++]=i;
			}
			else//这个点没被割过，把图复原
			{
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						g[i][j]=ng[i][j];
			}
			if(tmp==0)	break;//割断了。。
		}
		for(int i=0;i<num;i++)
			if(i==0)	printf("%d",ans[i]);
			else	printf(" %d",ans[i]);
		printf("\n");
	}
}
