//最近公共祖先模板
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=10005;
int fa[maxn],rank[maxn],ind[maxn],ancestor[maxn];
bool vis[maxn];
vector<int> tree[maxn],query[maxn];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		rank[i]=1;
		tree[i].clear();
		query[i].clear();
	}
	memset(ind,0,sizeof(ind));
	memset(vis,0,sizeof(vis));
}

int find(int x)
{
	if(fa[x]==x)	return x;
	else return fa[x]=find(fa[x]);
}
void Union(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)	return;
	else if(rank[fx]<=rank[fy])
	{
		fa[fx]=fy;
		rank[fy]+=rank[fx];
	}
	else
	{
		fa[fy]=fx;
		rank[fx]+=rank[fy];
	}
	return;
}
void tarjan(int u)
{
	int v;
	ancestor[u]=u;
	for(int i=0;i<(int)tree[u].size();i++)
	{
		v=tree[u][i];
		tarjan(v);
		Union(u,v);
		ancestor[find(u)]=u;
	}
	vis[u]=1;
	for(int i=0;i<(int)query[u].size();i++)
	{
		if(vis[query[u][i]])
		{
			printf("%d\n",ancestor[find(query[u][i])]);
			return;
		}
	}
}
int main()
{
	int u,v,n,ca;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		init(n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			tree[u].push_back(v);
			ind[v]++;
		}
		scanf("%d%d",&u,&v);
		query[u].push_back(v);
		query[v].push_back(u);
		for(int i=1;i<=n;i++)
			if(ind[i]==0)
			{
				tarjan(i);
				break;
			}
	}
	return 0;
}



