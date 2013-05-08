//最大流加二分答案!
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int maxn=405;
const int inf=1111111111;
struct Edge{
	int v,w,next,len;
}edge[40005*5];
int head[maxn],h[maxn],gap[maxn],en;
void addedge(int u,int v,int len)
{
	edge[en].v=v,edge[en].len=len;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].len=inf;
	edge[en].next=head[u];
	head[u]=en++;
}

void init()
{
	en=0;
	memset(head,-1,sizeof(head));
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
	int n,p,total,s,t;
	int u,v,len;
	int e1,e2;
	int left=inf,right=0,mid,ans=inf;
	scanf("%d%d%d",&n,&p,&total);
	init();
	s=0,t=n+1;
	for(int i=0;i<p;i++)
	{
		scanf("%d%d%d",&u,&v,&len);
		addedge(u,v,len);
		addedge(v,u,len);
		left=min(left,len);//如果直接把left=0,right=inf会tle!!
		right=max(right,len);
	}
	addedge(s,1,0);
	e1=en-2;
	
	addedge(n,t,0);
	
	e2=en-2;
	
	while(left<=right)
	{
		mid=(left+right)>>1;
		//cout<<mid<<endl;
		edge[e1].w=total;
		edge[e2].w=total;
		for(int i=0;i<en-4;i++)	
			if(edge[i].len<=mid)	edge[i].w=1;
			else edge[i].w=0;
		int tmp=sap(s,t,t+1);
		//cout<<tmp<<endl;
		if(tmp<total)	left=mid+1;
		else right=mid-1,ans=min(ans,mid);
	}
	printf("%d\n",ans);
	return 0;
}