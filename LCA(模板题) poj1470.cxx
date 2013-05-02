#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=1005;
int fa[maxn],rank[maxn],ind[maxn],ancestor[maxn],ans[maxn];
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
	memset(ans,0,sizeof(ans));
}

int find(int x)//并查集
{
	if(fa[x]==x)	return x;
	else return fa[x]=find(fa[x]);
}
void Union(int x,int y)
{//启发式合并
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
		ancestor[find(u)]=u;//给下面的集合找祖先
	}
	vis[u]=1;
	for(int i=0;i<(int)query[u].size();i++)
		if(vis[query[u][i]])//这个点为最近公共祖先的次数
			ans[ancestor[find(query[u][i])]]++;
}
int main()
{
	int u,v,n,m;
	char tmp;
	while(scanf("%d",&n)!=EOF)
	{
		init(n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d:(%d)",&u,&m);
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&v);
				tree[u].push_back(v);
				ind[v]++;
			}
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			while(scanf("%c",&tmp)&&tmp!='(');
			scanf("%d%d",&u,&v);
			query[u].push_back(v);
			query[v].push_back(u);
			while(scanf("%c",&tmp)&&tmp!=')');
		}
		for(int i=1;i<=n;i++)
		{
			if(!ind[i])
			{
				tarjan(i);
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(ans[i])
				printf("%d:%d\n",i,ans[i]);
		}
	}
	return 0;
}



