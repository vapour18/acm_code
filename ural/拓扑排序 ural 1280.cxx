//给出一个序列,询问是否是拓扑序列
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int map[maxn][maxn],indegree[maxn]={0},sequence[maxn],n;
bool toposort()
{
	for(int i=1;i<=n;i++)
	{
		if(indegree[sequence[i]])//key
			return 0;
		for(int j=1;j<=n;j++)
			if(map[sequence[i]][j])
				indegree[j]--;
	}
	return 1;
}
int main()
{
	int m,u,v;
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		if(map[u][v]==0)	indegree[v]++;//防重边
		map[u][v]=1;	
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&sequence[i]);
	if(toposort())	printf("YES\n");
	else	printf("NO\n");
	return 0;
}
