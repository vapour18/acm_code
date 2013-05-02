
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 120
#define inf 111111111
using namespace std;
int n,map[maxn][maxn],c[maxn],d[maxn],p[maxn],h;
bool vis[maxn],flag;
void dfs(int pos,int dep,int money)
{
	if(flag)	return;
	if(dep==h)
	{
		if(money-map[pos][1]>=0) flag=1;
		return;
	}
	int v;
	for(int i=1;i<=h;i++)
	{
		v=p[i];
		if(!vis[v]&&(money-d[i]-map[pos][v]>=0))
		{
			vis[v]=1;
			dfs(v,dep+1,money-d[i]+c[i]-map[pos][v]);
			vis[v]=0;
		}
	}
	return;
}
int main()
{
	int ca,u,v,w;
	int m,money;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d%d%d",&n,&m,&money);
		flag=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				map[i][j]=inf;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]=min(map[u][v],w);
			map[v][u]=min(map[v][u],w);
		}
		for(int i=1;i<=n;i++)		map[i][i]=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&h);
		for(int i=1;i<=h;i++)
			scanf("%d%d%d",&p[i],&c[i],&d[i]);
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
		dfs(1,0,money);
		if(flag)		printf("YES\n");
		else 	printf("NO\n");
	}
}





