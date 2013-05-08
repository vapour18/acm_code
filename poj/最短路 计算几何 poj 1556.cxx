//一个10*10密室，其中有n堵墙，墙上有两个门，求从（0，5）到（10，5）的最短路的长度
//先用线段相交之类的判断任意两点之间的连通性和距离。
//然后就求最短路就好了
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
const int maxn = 105;
const int inf = 1111111111;
const double eps = 1e-8;
using namespace std;
struct Point{
	double x,y;
}p[maxn];
struct{
	Point v[6];
}wall[maxn];
int n,m;
double g[maxn][maxn],dist[maxn];

double mydist(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));
}
double mult(Point sp, Point ep, Point op)
{
	return (sp.x - op.x)*(ep.y - op.y) - (ep.x - op.x)*(sp.y - op.y);
}
bool isintersected(Point s1,Point e1,Point s2, Point e2)
{
	if( min(s1.x, e1.x) <= max(s2.x,e2.x)&&
		min(s1.y, e1.y) <= max(s2.y,e2.y)&&
		min(s2.x, e2.x) <= max(s1.x,e1.x)&&
		min(s2.y, e2.y) <= max(s1.y,e1.y)&&
		mult(s2,e2,s1)*mult(s2,e2,e1) <= 0&&
		mult(s1,e1,s2)*mult(s1,e1,e2) <= 0)
		return 1;
	return 0;
}
bool islink(int a,int b)
{
	int i = 0;
	if(a) i = (a - 1)/4 +1;
	for(; i < (b - 1)/4 ; i++)
	{
		if( isintersected(p[a],p[b],wall[i].v[0],wall[i].v[1])||
			isintersected(p[a],p[b],wall[i].v[2],wall[i].v[3])||
			isintersected(p[a],p[b],wall[i].v[4],wall[i].v[5]))
			return 0;
	}
	return 1;
}
double spfa(int s)
{
	bool vis[maxn] = {0};
	queue<int> q;
	for(int i = 0; i <= n; i++)	dist[i] = inf;
	dist[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(g[u][i]!=0&&dist[i] > dist[u] + g[u][i])
			{
				dist[i] = dist[u] + g[u][i];
				if(!vis[i])
				{
					vis[i] = 1;
					q.push(i);
				}
			}
		}
	}
	return dist[n];
}
int main()
{
	double x,y;
	while(scanf("%d",&m)&&m!=-1)
	{
		n = 4*m + 1;
		p[0].x = 0,p[0].y = 5;
		p[n].x = 10, p[n].y = 5;
		for(int k = 1,i = 0; i < m; i++)
		{
			scanf("%lf",&x);
			wall[i].v[0].x = x, wall[i].v[0].y = 0;
			wall[i].v[5].x = x, wall[i].v[5].y = 10;
			for(int j = 1; j <= 4; j++)
			{
				p[k].x = x;
				scanf("%lf",&p[k].y);
				wall[i].v[j] = p[k++];
			}
		}
		memset(g,0,sizeof(g));
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < i; j++)
				if(islink(j,i))
					g[i][j] = g[j][i] = mydist(p[i],p[j]);
		printf("%.2f\n",spfa(0));
	}
	return 0;
}