//限制边数的最短路,边可以重复走
//拆点,把一个点拆成50个,做SPFA
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 5005
#define inf 111111111
using namespace std;
int n,m;
int head[maxn],en;
struct Edge{
	int v,w,next;
}edge[100005*2];
struct Q{
    int num,u;
}tmp;
int dist[maxn][60];
void addedge(int u,int v,int w)
{
    edge[en].v=v,edge[en].w=w;
    edge[en].next=head[u];
    head[u]=en++;
    swap(u,v);
    edge[en].v=v,edge[en].w=w;
    edge[en].next=head[u];
    head[u]=en++;
}
void spfa(int s,int k)
{
	queue<Q> q;
	bool vis[maxn][60];
	int u,v,num;
	for(int i=0;i<=n;i++)
		for(int j=0;j<60;j++)
			 dist[i][j]=inf,vis[i][j]=0;
	tmp.num=0,tmp.u=s;
	dist[s][0]=0;
	vis[s][0]=1;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		u=tmp.u,num=tmp.num;
		vis[u][num]=0;
		for(int e=head[u];e!=-1;e=edge[e].next)
		{
			v=edge[e].v;
			if(num+1<56&&dist[v][num+1]>dist[u][num]+edge[e].w)
			{
				dist[v][num+1]=dist[u][num]+edge[e].w;
				if(!vis[v][num+1])
				{
					tmp.num=num+1,tmp.u=v;
					q.push(tmp);
					vis[v][num+1]=1;
				}
			}
		}
	}
}

int main()
{
	int u,v,w,s,t,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(head,-1,sizeof(head));
		en=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		scanf("%d%d%d",&s,&t,&k);
		if(k%10)	k=k/10+1;
		else	k/=10;
		spfa(s,k);
		int ans=inf;
		for(int i=k;i<=55;i++)
			if(dist[t][i]<ans)		ans=dist[t][i];
		if(ans==inf)		printf("-1\n");
		else	printf("%d\n",ans);
	}
	return 0;
}
