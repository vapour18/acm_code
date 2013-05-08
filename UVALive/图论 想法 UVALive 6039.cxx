#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 200005;
struct Edge{
	int v,w,next;
}edge[maxn];
int head[maxn],en;
void addedge(int u,int v,int w)
{
	edge[en].v = v;edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
}
int main()
{
	int cas,n,u,v,w,ans;
	bool vis[maxn];
	scanf("%d",&cas);
	for(int ca = 1; ca <= cas; ca++)
	{
		init();
		ans = 0;
		scanf("%d",&n);
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		//cout<<"pp\n";
		memset(vis,0,sizeof(vis));
		vis[1] = 1;
		queue<pair<int,int> > q;
		q.push(make_pair(1,0));
		while(!q.empty())
		{
			u = q.front().first,w = q.front().second;
			q.pop();
			int sum = 0, mx = w;
			for(int i = head[u]; i!=-1;i = edge[i].next)
			{
				v = edge[i].v;
				if(vis[v]) continue;
				if(edge[i].w > mx)
				{
					sum+=mx;
					mx = edge[i].w;
				}
				else sum+=edge[i].w;
				vis[v] = 1;
				q.push(make_pair(v,edge[i].w));
			}
			if(mx >= sum) ans+=mx-w;
			else if((sum+mx+1)/2 - w> 0)ans+=(sum+mx+1)/2-w;
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}