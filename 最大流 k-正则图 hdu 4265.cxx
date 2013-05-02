//学长说是k-正则图的问题。k-正则图就是每个点度为k的无向图。
//题意：有n个人和n各位置，每个人可以在一定的位置上，求一共有多少种站法，且每个人都不在同一个位置，并输出解
//建图，超级源点向人加边，容量为m，人与座位若可以加一条边，座位和超级汇点加边，容量为m。若流量为n*m，则表示m可以增加，所以二分m就可以求出匹配的个数
//然后只要删除多余的边，然后每次把m设为1，求出每次的匹配及可以了
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=505;
const int inf=1111111111;
struct Edge{
	int v,w,next;
}edge[maxn*maxn*25];
int head[maxn],cur[maxn],en;
int h[maxn],gap[maxn];
bool g[maxn][maxn];
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=cur[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=cur[u]=en++;
}

int dfs(int s,int t,int pos,int n,int cost)
{
	if(pos==t)	return cost;
	int minh=n-1,lv=cost,d;
	for(int j=cur[pos];j!=-1;j=edge[j].next)
	{
		int v=edge[j].v,w=edge[j].w;
		if(w>0)
		{
			if(h[v]+1==h[pos])
			{
				cur[pos]=j;
				d=min(lv,w);
				d=dfs(s,t,v,n,d);
				edge[j].w-=d,edge[j^1].w+=d;
				lv-=d;
				if(h[s]>=n||lv==0)	return cost-lv;
			}
		}
	}
	if(lv==cost)
	{
		cur[pos]=head[pos];
		gap[h[pos]]--;
		int v;
		for(int i=head[pos];i!=-1;i=edge[i].next)
		{
			if(edge[i].w&&h[v=edge[i].v]<minh)
			{
				cur[pos]=i;
				minh=h[v];
			}
		}
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
void init()
{
	en=0;
	memset(head,-1,sizeof(head));
	memset(cur,-1,sizeof(head));
}

void buildgraph(int s,int t,int m,int n)
{
	init();
	for(int i=1;i<=n;i++)
	{
		addedge(s,i,m);
		addedge(i+n,t,m);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(g[i][j])
				addedge(i,j+n,1);
}
void Delete(int s,int t,int n,int x)
{
	for(int i=1;i<=n;i++)
		for(int e=head[i];e!=-1;e=edge[e].next)
			if(edge[e].w==x&&edge[e].v!=s)	g[i][edge[e].v-n]=0;
}

int main()
{
	int n,s,t;
	int l,r,m,ans[maxn];
	char str[maxn];
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str+1);
			for(int j=1;j<=n;j++)
				if(str[j]=='N')	g[i][j]=0;
				else g[i][j]=1;
		}
		l=0,r=n;
		s=0,t=2*n+1;
		while(l<=r)
		{
			m=(l+r)>>1;
			buildgraph(s,t,m,n);
			if(sap(s,t,n*2+2)==m*n) l=m+1;		
			else r=m-1;
		}
		buildgraph(s,t,r,n);
		sap(s,t,n*2+2);
		Delete(s,t,n,1);

		printf("%d\n",r);
		while(r--)
		{
			buildgraph(s,t,1,n);
			sap(s,t,n*2+2);
			for(int i=1;i<=n;i++)
			{
				for(int e=head[i];e!=-1;e=edge[e].next)
				{
					int v=edge[e].v;
					if(edge[e].w==0&&v!=s)	ans[v-n]=i;
				}
			}
			for(int i=1;i<n;i++)
				printf("%d ",ans[i]);
			printf("%d\n",ans[n]);
			Delete(s,t,n,0);
		}
	}
	return 0;
}