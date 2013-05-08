#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
const int maxm = 1200000;
const int maxn = 1200;
const int inf = 1111111111;
struct point{
	int x,y,z;
}p[maxn];
struct Edge{
	int u,v,w;
}edge[maxm];
int pre[maxn],id[maxn],vis[maxn],in[maxn];
int n,m;
void addedge(int u,int v, int w)
{
	edge[m].u = u,edge[m].v = v,edge[m++].w = w;
}
int dist(point a,point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}
int directed_mst(int root)
{
	int res = 0,nv = n;
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
			if(in[i] == inf) return -1;
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
	return res;
}
int main()
{
	int x,y,z;
	while(scanf("%d%d%d%d",&n,&x,&y,&z)&&(x+y+z+n))
	{
		m = 0;
		n++;
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
			addedge(0,i,x*p[i].z);
		}
		for(int i = 1; i < n; i++)
		{
			int k,t;
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&t);
				if(t==i) continue;
				int cost = dist(p[i],p[t])*y;
				if(p[t].z>p[i].z) cost+=z;
				addedge(i,t,cost);
			}
		}
		printf("%d\n",directed_mst(0));
	}
	return 0;
}