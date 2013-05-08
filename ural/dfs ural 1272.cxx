#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
const int maxn=10005;
struct Edeg{
	int v,next;
}edge[12009*2*2];
using namespace std;
int head[maxn],en=0;
bool vis[maxn]={0};
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int u)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!vis[v])
		{
			vis[v]=1;
			dfs(v);
		}
		
	}
}
int main()
{
	int n,k,m;
	int u,v,ans=0;
	scanf("%d%d%d",&n,&k,&m);
	memset(head,-1,sizeof(head));
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	while(m--)	scanf("%d%d",&u,&v);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			ans++;
		}
	}
	if(ans)	ans--;
	printf("%d\n",ans);
	return 0;
}
