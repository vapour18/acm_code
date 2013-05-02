#include<cstdio>
#include<cstring>
#include<algorithm>
//ls sb ls sb ls sb ls sb
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int maxn=3005;
const int inf=1111111111;
struct Edge{
	int v,w,next;
}edge[maxn*maxn];
int head[maxn],en,n,m,dist[maxn],circle,ind[maxn];
pair<int,int> ans;
int mlen;
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
void init()
{
	en=0;
	memset(head,-1,sizeof(head));
	memset(ind,0,sizeof(ind));//记录入度
	mlen=0;
	circle=0;
}
void input()
{
	int u,v,w;
	printf("输入节点的数量n，边的数量m\n");
	scanf("%d%d",&n,&m);
	printf("输入m条边的起点终点和权值，格式 u v w\n");
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
}
void spfa(int s)
{
	queue<int> q;
	bool vis[maxn]={0};
	for(int i=0;i<=n;i++)	dist[i]=inf;
	dist[s]=0,vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(dist[v]>dist[u]+edge[i].w)
			{
				dist[v]=dist[u]+edge[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dist[i]!=inf&&dist[i]>mlen)
		{
			mlen=dist[i];
			ans=make_pair(s,i);
		}
	}
}
bool toposort()
{
	int count=0;
	stack<int> sta;
	for(int i=1;i<=n;i++)
		if(ind[i]==0)	sta.push(i);
	while(!sta.empty())
	{
		int u=sta.top();
		sta.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(!(--ind[v]))	sta.push(v);
		}
	}
	return n==count;

}
void solve()
{
	if(!toposort())
	{
		circle=1;
		return;
	}
	for(int i=1;i<=n;i++)
		spfa(i);
	printf("u: %d v: %d 距离：%d\n",ans.first,ans.second,mlen);
}
int main()
{
	bool go=1;
	while(go)
	{
		init();
		input();
		solve();
		if(circle)	printf("该图有环！！！！！！\n");
		printf("是否继续计算 是 1 否 0");
		cin>>go;
	}
	cout<<"end!\n";
	return 0;
}
