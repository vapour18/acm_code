// 从1,2,3出发到某点的最短路边不重复的符合要求的点的个数
//枚举每条边是否被重复走过，若有，则其右端点不是合法点
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
const int inf=1111111111;
const int maxn=3005;
const int maxm=200010;
using namespace std;
struct Edge{
	int u,v,w,next;
}edge[maxm*2];
int head[maxn],en;
void addedge(int u,int v,int w)
{
	edge[en].u=u,edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
void spfa(int s,int dist[])
{
	queue<int> q;
	bool vis[maxn]={0};
	for(int i=0;i<=3001;i++)	dist[i]=inf;
	dist[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int fr=q.front();
		q.pop(),vis[fr]=0;
		for(int e=head[fr];e!=-1;e=edge[e].next)
		{
			int v=edge[e].v;
			if(dist[v]>dist[fr]+edge[e].w)
			{
				dist[v]=dist[fr]+edge[e].w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return;
}
int main()
{
	int n,m,u,v,w;
	int dist1[maxn],dist2[maxn],dist3[maxn];
	bool flag[maxn];
	vector<int> ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(head,-1,sizeof(head));
		en=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		spfa(1,dist1);
		spfa(2,dist2);
		spfa(3,dist3);
		ans.clear();
		memset(flag,1,sizeof(flag));
		for(int i=0;i<en;i++)
		{
			u=edge[i].u;
			v=edge[i].v;
			w=edge[i].w;
			if(dist1[u]+w==dist1[v]&&dist2[u]+w==dist2[v])
				flag[v]=0;
			if(dist1[u]+w==dist1[v]&&dist3[u]+w==dist3[v])
				flag[v]=0;
			if(dist3[u]+w==dist3[v]&&dist2[u]+w==dist2[v])
				flag[v]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(dist1[i]!=inf&&dist2[i]!=inf&&dist3[i]!=inf&&flag[i])
				ans.push_back(i);
		}
		if(ans.size()==0)	printf("impossible\n");
		else
		{
			printf("%d\n",ans.size());
			for(int i=0;i<(int)ans.size();i++)
				if(i==0)
					printf("%d",ans[i]);
				else
					printf(" %d",ans[i]);
			printf("\n");
		}
	}
	return 0;
}

