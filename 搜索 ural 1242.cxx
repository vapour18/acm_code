#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#define maxn 1005
using namespace std;
vector<int> g[maxn],rg[maxn];
int n;
bool vis[maxn]={0};
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<(int)g[u].size();i++)
	{
		int v=g[u][i];
		if(!vis[v])
			dfs(v);
	}
}
void dfs2(int u)
{
	vis[u]=1;
	for(int i=0;i<(int)rg[u].size();i++)
	{
		int v=rg[u][i];
		if(!vis[v])		
			dfs2(v);
	}
}
int main()
{
	char tmp[15];
	int u,v,victims[maxn];
	bool ans[maxn]={0};
	scanf("%d",&n);
	
	while(scanf("%s",tmp)&&tmp[0]!='B')
	{
		u=0;
		for(int i=0;tmp[i];i++)
			u=u*10+tmp[i]-'0';//注意拼装啊！！
		scanf("%d",&v);
		g[v].push_back(u);
		rg[u].push_back(v);
	}
	int vn=0;

	while(scanf("%d",&u)!=EOF)
		victims[vn++]=u;
	for(int i=0;i<vn;i++)
		if(!vis[victims[i]])	dfs(victims[i]);
	for(int i=1;i<=n;i++)
		ans[i]|=vis[i];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<vn;i++)
		if(!vis[victims[i]])	dfs2(victims[i]);
	for(int i=1;i<=n;i++)
		ans[i]|=vis[i];
	bool fi=1;
	for(int i=1;i<=n;i++)
		if(!ans[i])
		{
			if(fi)		printf("%d",i),fi=0;
			else	printf(" %d",i);
		}
	if(fi)	printf("0");
	printf("\n");
	return 0;
}
