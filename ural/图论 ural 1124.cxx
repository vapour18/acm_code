//题意：将颜色块移动到本身的位置手需要移动的最少步数
//放错位置的加一条边，ans=边数+联通分量个数-1
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
struct Edge{
	int next,v;
}edge[500*500];
int head[1505],en,f[1505];
bool vis[1505]={0},h[505][505],flag;
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!vis[v]){
			flag=1;
			dfs(v);
		}
	}
	
}
int solve(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		if(!vis[i]&&head[i]!=-1)
		{
			dfs(i);
			if(flag)cnt++;
		}
	}
	return cnt;
}
int main()
{
	int n,m,ans=0;
	int color;
	scanf("%d%d",&m,&n);
	memset(head,-1,sizeof(head));
	memset(h,0,sizeof(h));
	en=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&color);
			if(color!=i)
			{
				ans++;
				addedge(i,color),h[i][color]=1;
			}
		}
	}
	ans+=solve(m);
	if(ans) ans--;
	printf("%d\n",ans);
	return 0;
}
