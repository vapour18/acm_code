#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
const int maxm = 120000;
const int maxn = 120;
const double inf = 1111111111;
struct point{
	double x,y;
}p[maxn];
struct Edge{
	int u,v;
	double w;
}edge[maxm];
int pre[maxn],id[maxn],vis[maxn];
double in[maxn];
int n,m;

double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void directed_mst(int root)
{
	int nv = n;
	double res = 0;
	while(1)
	{
		for(int i = 0; i < nv;i++)	in[i] = inf;
		for(int i = 0; i < m;i++)
		{
			int u = edge[i].u,v = edge[i].v;
			if(edge[i].w < in[v]&&u!=v)//找每个点最小的入边
			{
				pre[v] = u;
				in[v] = edge[i].w;
			}
		}
		for(int i = 0; i < nv; i++)//判断是否可到达
		{
			if(i == root) continue;
			if(in[i] == inf) 
			{
				printf("poor snoopy\n");
				return ;
			}
		}
		int cntnode = 0;
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		in[root] = 0;
		for(int i = 0; i < nv; i++)
		{
			res+=in[i];
			int v=i;
			while(vis[v]!=i&&id[v] == -1&&v!=root)
			{
				vis[v] = i;
				v = pre[v];
			}
			if(v != root && id[v] == -1)
			{
				for(int u = pre[v];u!=v;u = pre[u])
					id[u] = cntnode;
				id[v] = cntnode++;
			}
		}
		if(cntnode == 0) break;
		for(int i = 0; i < nv; i++)
		{
			if(id[i] == -1) id[i]=cntnode++;
		}
		for(int i = 0;i < m;i++)
		{
			int v= edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if(edge[i].u != edge[i].v) edge[i].w-=in[v];
		}
		nv = cntnode;
		root = id[root];
	}
	printf("%.2f\n",res);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d",&edge[i].u,&edge[i].v);
			edge[i].u--,edge[i].v--;
			edge[i].w = dist(p[edge[i].u],p[edge[i].v]);
		}
		directed_mst(0);
	}
	return 0;
}