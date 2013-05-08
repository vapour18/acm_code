#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=100101;
struct Edge{
	int v,next;
}edge[maxn*3];
int head[maxn],en,s;
int n,m,k;
bool vis[maxn],flag;
vector<int>ans;
void init()
{
	memset(head,-1,sizeof(head));
	en=0;
	flag=0;
	memset(vis,0,sizeof(vis));
}
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int u,int dep)
{
	if(flag)	return;
	ans.push_back(u);
	for(int i=head[u];i!=-1&&!flag;i=edge[i].next)
	{
		int v=edge[i].v;
		if(v==s&&dep>k)
		{
			flag=1;
			printf("%d\n",dep);
			for(int i=0;i<(int)ans.size();i++)
				printf("%d ",ans[i]);
			printf("\n");
			return;
		}
		if(!vis[v])
		{
			vis[v]=1;
			dfs(v,dep+1);
		}
	}
	ans.pop_back();
}
int main()
{
	int u,v;
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v),addedge(v,u);
	}
	vis[1]=1;
	for(int i=1;i<=n&&!flag;i++)
		memset(vis,0,sizeof(vis)),s=i,dfs(i, 1);
	return 0;
}