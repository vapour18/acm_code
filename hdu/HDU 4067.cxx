//费用流
/*1.对于u到v，如果a<=b，就保留那条边，也就是构建一条v到u的边，容量为1，费用为b-a，并且在答案ans上加a，
并且u的出度加1，v的入度加1，这条边的意义就是如果这条保留下来的边要删除的话需要b-a的费用，因为咱们是先累加a了
2.对于u到v，如果a>b，就去掉那条边，也就是构建一条u到v的边，容量为1，费用为a-b，并且在答案ans上加b，
 并且u的入度加1，v的出度加1，这条边的意义就是如果这条删掉的边要恢复的话需要a-b的费用
3.为了保证起点和终点的条件，虚构一条边从终点到起点，也就是起点的出度加1，终点的入度加1，
（不能真的把这条边加进图里，因为这是不可改的边）
4.增加源点S和汇点T，如果点I入度大于出度的话就是增加一条边从源点S到点I，容量为入度-出度，费用为0，
相反的就是建一条边从点I到汇点T，容量为出度-入度，费用为0
5.求最小费用流，此时最大流如果=到汇点的所有容量之和，就是有解，*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 500
#define inf 1111111111
using namespace std;
struct EDGE{
	int u,v,cap,next,cost;
}edge[200*2005*2];
int head[maxn],en,c;
inline void addedge(int u,int v,int cap,int cost)
{
	edge[en].u=u,edge[en].v=v,edge[en].cap=cap,edge[en].cost=cost;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].u=u,edge[en].v=v,edge[en].cap=0,edge[en].cost=-cost;
	edge[en].next=head[u];
	head[u]=en++;
}
int mcmf(int s,int t)
{
	int f=0,v;
	queue<int> q;
	int dis[maxn],pre[maxn];
	while(1)
	{
		bool vis[maxn];
		memset(vis,0,sizeof(vis));
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<=t;i++)
			dis[i]=(i==s? 0:inf);
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			vis[u]=0;
			for(int i=head[u];i!=-1;i=edge[i].next)
			{
				v=edge[i].v;
				if(edge[i].cap&&dis[v]>dis[u]+edge[i].cost)
				{
					dis[v]=dis[u]+edge[i].cost;
					pre[v]=i;
					if(!vis[v])
					{
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
		if(dis[t]==inf)	break;
		int a=inf;
		for(int i=pre[t];i!=-1;i=pre[edge[i].u])
			if(edge[i].cap<a)
				a=edge[i].cap;
		f+=a;
		for(int i=pre[t];i!=-1;i=pre[edge[i].u])
		{
			edge[i].cap-=a;
			edge[i^1].cap+=a;
		}
		c+=dis[t]*a;
	}
	return f;
}
int main()
{
	int cas,n,m,s,t;
	int u,v,a,b,in[maxn],cnt;
	scanf("%d",&cas);
	for(int ca=1;ca<=cas;ca++)
	{
		scanf("%d%d%d%d",&n,&m,&s,&t);
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		c=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&u,&v,&a,&b);
			if(a>b)
			{
				c+=b;
				addedge(u,v,1,a-b);
			}
			else
			{
				c+=a;
				addedge(v,u,1,b-a);
				in[u]--,in[v]++;
			}
		}
		in[s]++,in[t]--;//设了超级源点和汇点
		s=0,t=n+1;
		cnt=0;
		for(int u=1;u<=n;u++)//这个点需要去掉“入度-出度”条指向他的边才能满足条件
		{
			if(in[u]>0)addedge(s,u,in[u],0);
            if(in[u]<0)addedge(u,t,-in[u],0),cnt-=in[u];//cnt为理论上的最大流
		}
		printf("Case %d: ",ca);
		if(mcmf(s,t)==cnt)	printf("%d\n",c);
		else printf("impossible\n");
	}
	return 0;
}
