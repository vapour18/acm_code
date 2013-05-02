#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define inf 111111111
using namespace std;
int f[maxn][maxn],dist[maxn][maxn],g[maxn][maxn],ans[maxn],num;
void dfs(int i,int j)
{
	int k=f[i][j];
	if(k==0)
	{
		ans[num++]=j;
		return;
	}
	dfs(i,k);
	dfs(k,j);
}
int main()
{
	int n,m,u,v,w,mm;
	while(scanf("%d",&n)&&n!=-1)
	{
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dist[i][j]=g[i][j]=inf,f[i][j]=0;
		for(int i=0;i<=n;i++)		dist[i][i]=g[i][i]=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if(dist[u][v]>w)
				dist[u][v]=dist[v][u]=g[u][v]=g[v][u]=w;
		}
		mm=inf;//mm表示最小环的长度
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<k;i++)//先求环，为啥？
				for(int j=i+1;j<k;j++)
					if(dist[i][j]+g[i][k]+g[k][j]<mm)
					{
						mm=dist[i][j]+g[i][k]+g[k][j];
						num=0;
						ans[num++]=i;
						dfs(i,j);
						ans[num++]=k;
					}
			for(int i=1;i<=n;i++)//再松弛，保证环两端不是同一条路径
				for(int j=1;j<=n;j++)
				{
					if(dist[i][j]>dist[i][k]+dist[k][j])
					{
						dist[i][j]=dist[i][k]+dist[k][j];
						f[i][j]=k;//f[i][j]表示i到j经过k
					}
					
				}
		}
		if(mm==inf)	printf("No solution.");
		else 
			for(int i=0;i<num;i++)
				if(i==0)	printf("%d",ans[i]);
				else printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
