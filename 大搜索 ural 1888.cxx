#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1005;
const int inf = 111111111;
int g[maxn][maxn],n,m;
int vis[maxn],ans,id[maxn],tid[maxn];
bool flag;
void dfs(int u,int c)//考察是否有奇数环,有则无解
{
	vis[u] = c;
	for(int i = 1; i <=n; i++)
		if(g[u][i])
		{
			if(vis[i] != -1&&vis[i]!=(vis[u]^1))
			{
				flag = 0;
				return;
			}
			else if(vis[i] == -1)	dfs(i,vis[u]^1);
		}
}
void bfs1(int x)
{
	queue<int> q;
	memset(tid,0,sizeof(tid));
	q.push(x);tid[x] = 1;
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i = 1; i <= n; i++)
		{
			if(g[u][i]&&!tid[i])
			{
				tid[i] = tid[u] + 1;
				q.push(i);
			}
		}
	}
	int tmp = 0;
	for(int i = 1; i <= n; i++)
		tmp = max(tmp,tid[i]);
	if(ans < tmp - 1)
	{
		ans = tmp - 1;
		for(int i = 1; i <= n; i++)	id[i] = tid[i];
	}
}
void bfs2(int x)
{
	queue<int> q;
	memset(tid,0,sizeof(tid));
	q.push(x);tid[x] = id[x] = 50;
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i = 1; i <= n; i++)
		{
			if(g[u][i]&&!tid[i])
			{
				tid[i] = tid[u] -1;
				id[i] = tid[i];
				q.push(i);
			}
		}
	}
	
}
int main()
{
	int u,v;
	vector<int> a;
	scanf("%d%d",&m,&n);
	memset(g,0,sizeof(g));
	memset(vis,-1,sizeof(vis));
	flag = 1;
	for(int i = 0 ; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v] = g[v][u] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= n&&flag;i++)
	{
		if(vis[i] == -1)
		{
			dfs(i,1);
			a.push_back(i);
			cnt++;
		}
	}
	if(flag == 0)	printf("-1\n");
	else
	{
		ans = 0;
		if(cnt == 1)			
			for(int i = 1; i <= n; i++)
				bfs1(i);//只有一个连通分量时,以某一个点做为根,找最大差值
		else
		{
			bfs1(1);
			ans = 49;//存在大于1个连通分量则最大差值一定为49
			for(int i = 1; i < (int)a.size();i++)
				bfs2(a[i]);//考察每个连通分量
		}
		printf("%d\n",ans);
		for(int i = 1; i < n;i++)
			printf("%d ",id[i]);
		printf("%d\n",id[n]);
	}
	return 0;
}





