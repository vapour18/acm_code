#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
const int maxn=1005;
using namespace std;
struct Edge{
	int v,next;
}edge[maxn*2];
int head[maxn],en;
int n,id;
bool vis[maxn]={0};
pair<int,int> ans[maxn];
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void bfs(int s)
{
	int u,v;
	int nx,ny;
	queue<int>q;
	q.push(s);
	vis[s]=1;
	nx=-1000,ny=-1000;
	ans[s]=make_pair(nx,ny);
	while(!q.empty())
	{
		u=q.front(),q.pop();	
		nx=ans[u].first+2;
		for(int i=head[u],j=0;i!=-1;i=edge[i].next,j++)
		{
			v=edge[i].v;
			if(vis[v])	continue;
			ny+=2;
			ans[v]=make_pair(nx,ny);
			q.push(v);
			vis[v]=1;
		}
	}
}

int main()
{
	int u,v;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	en=0;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	bfs(1);
	id=-1000;
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}