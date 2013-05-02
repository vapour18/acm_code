/*题意巨抽!
 一个图,点的半径是 1mm,边的长度是 8mm。是否存在这样的一个结构使得:
若两个点连通,则两点在三维空间的中心的距离(以 cm 计)等于两点最短距离上边的数量
其实就是直接相连的两点中心距离为 1cm,所以若要满足条件,那么一个连通子图需为一条直线或三角形或四面体。
注意两点不一定连通
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int maxn = 105;
using namespace std;
int g[maxn][maxn];
int n,m,num,vnum;
bool vis[maxn],line;
void dfs(int u)
{
	int cnt = 0;
	vis[u] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(g[u][i])
		{
			num++,cnt++;
			if(!vis[i])
			{
				vnum++;
				dfs(i);
			}
		}
	}
	if(cnt >2 ) line = 0;	
}
int main()
{
	int u,v;
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < m ;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v] = g[v][u] = 1;
	}
	bool flag = 1;
	for(int i = 1; i <= n&&flag; i++)
	{
		if(!vis[i])
		{
			num = 0, vnum = 1,line = 1;
			dfs(i);
			if((vnum == 3 && num == 6)||(vnum == 4 &&num == 12)||(line&&num/2 == vnum-1))	flag = 1;
			else flag = 0;
		}
	}
	if(flag) printf("Luck is possible\n");
	else printf("Unlucky Petr\n");
	return 0;
}