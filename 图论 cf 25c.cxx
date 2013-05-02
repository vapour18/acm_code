#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=305;
int main()
{
	int n,m,g[maxn][maxn],u,v,w;
	long long total=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]),total+=g[i][j];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(g[u][v]<=w)	printf("%lld ",total/2);
		else
		{
			g[u][v]=g[v][u]=w;
			total=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					g[i][j]=g[j][i]=min(g[i][j],min(g[i][u]+g[u][v]+g[v][j],g[i][v]+g[v][u]+g[u][j]));
					total+=g[i][j];
				}
			}
			
			
			printf("%lld ",total/2);
		}
		
	}
	return 0;
}
