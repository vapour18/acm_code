#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=4005;
const int inf=1111111111;
struct Edge{
	int v,w,next;
}edge[maxn*4];
int head[maxn],en;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
int dfs1(int u,int f)
{
	int ret=0;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v==f)	continue;
		ret+=dfs1(v,u)+edge[i].w;
	}
	return ret;
}
int dfs2(int u,int f,int sum)
{
	sum=max(0,sum);
	int ret=sum;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v==f)	continue;
		ret=max(ret,dfs2(v,u,sum+(edge[i].w? 1:-1)));
	}
	return ret;
} 
int main()
{
	int n;
	int u,v;
	while(scanf("%d",&n)!=EOF)
	{
		memset(head,-1,sizeof(head));
		en=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v,0);
			addedge(v,u,1);
		}
		int ans=inf;
		for(int i=1;i<=n;i++)
		{
			//cout<<dfs1(i,0)<<" "<<dfs2(i,0,0)<<endl;
			ans=min(ans,dfs1(i,0)-dfs2(i,0,0));
		}
		printf("%d\n",ans);
	}	
	return 0;
}



