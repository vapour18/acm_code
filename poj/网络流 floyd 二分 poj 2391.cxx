//不要抽了想成费用流！
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=200000;
const int inf=1111111111;
struct Edge{
	int v,next;
	long long w;
}edge[maxn*4];
int head[500],en;
int cow[500],shelter[500];
int h[500],gap[500];
int n,p;
long long map[500][500];
void addedge(int u,int v,long long w)
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
void build(long long m,int s,int t)
{
	en=0;
	memset(head,-1,sizeof(head));	
	for(int i=1;i<=n;i++)
	{
		addedge(s,i,cow[i]);
		addedge(i+n,t,shelter[i]);
		addedge(i,i+n,inf);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]<=m&&i!=j)
				addedge(i,j+n,inf);
}
int main()
{
	int u,v,s,t,sum,tmp;
	long long w;
	sum=0;
	scanf("%d%d",&n,&p);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			map[i][j]=(long long)inf*10000;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&cow[i],&shelter[i]);
		sum+=cow[i];
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%lld",&u,&v,&w);
		if(map[u][v]>w)
			map[u][v]=map[v][u]=w;
	}
	tmp=0;
	long long l=0,r=0,m,ans=-1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][j]>map[i][k]+map[k][j])
				{
					map[i][j]=map[i][k]+map[k][j];
					r=max(r,map[i][j]);
				}
	s=0,t=n*2+1;
	r+=100;
	while(l<=r)
	{
		m=(l+r)>>1;
		build(m,s,t);
		tmp=sap(s,t,t+1);
		if(tmp==sum)	r=m-1,ans=m;
		else	l=m+1;
	}
	printf("%lld\n",ans);
	return 0;
}

