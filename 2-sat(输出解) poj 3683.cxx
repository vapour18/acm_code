//把每场婚礼当作一个节点然后枚举去构造出矛盾
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=3005;
int dfn[maxn],low[maxn],id[maxn],ha[maxn],ind[maxn],color[maxn];
int s[maxn],t[maxn],d[maxn];
int n,num,scc;
bool vis[maxn];
stack<int> sta;
queue<int> q;
vector<int> g[maxn],dag[maxn];
void init()
{
	num=0,scc=1;
	memset(dfn,0,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	memset(ind,0,sizeof(ind));
	memset(color,0,sizeof(color));
	while(!q.empty())	q.pop();
	while(!sta.empty())	sta.pop();
}
bool judge(int lx,int ly,int rx,int ry)
{
	if(lx>=rx&&lx<=ry)	return 1;
	if(ly>=rx&&ly<=ry)	return 1;
	if(rx>=lx&&rx<=ly)	return 1;
	if(ry>=lx&&ry<=ly)	return 1;
	return 0;
}
void build()
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(judge(s[i],s[i]+d[i]-1,s[j],s[j]+d[j]-1))
			{
				g[i].push_back(j+n);
				g[j].push_back(i+n);
			}
			if(judge(s[i],s[i]+d[i]-1,t[j]-d[j],t[j]-1))
			{
				g[i].push_back(j);
				g[j+n].push_back(i+n);
			}
			if(judge(t[i]-d[i],t[i]-1,s[j],s[j]+d[j]-1))
			{
				g[i+n].push_back(j+n);
				g[j].push_back(i);
			}
			if(judge(t[i]-d[i],t[i]-1,t[j]-d[j],t[j]-1))
			{
				g[i+n].push_back(j);
				g[j+n].push_back(i);
			}
		}
}
void tarjan(int v)
{
	low[v]=dfn[v]=++num;
	sta.push(v);
	vis[v]=1;
	for(int i=0;i<(int)g[v].size();i++)
	{
		int x=g[v][i];
		if(!dfn[x])
		{
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else if(vis[x])
			low[v]=min(low[v],dfn[x]);
	}
	if(low[v]==dfn[v])
	{
		scc++;
		int x;
		do
		{
			x=sta.top();
			sta.pop();
			vis[x]=0;
			id[x]=scc;
		}while(x!=v);
	}
}
void builddag()
{
	for(int u=0;u<2*n;u++)
	{
		for(int i=0;i<(int)g[u].size();i++)
		{
			int v=g[u][i];
			if(id[u]!=id[v])
			{
				dag[id[v]].push_back(id[u]);
				ind[id[u]]++;
			}
		}
	}
}
void topsort()
{
	for(int i=1;i<=scc;i++)
		if(ind[i]==0)	q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(!color[u])	color[u]=1,color[ha[u]]=2;
		for(int i=0;i<(int)dag[u].size();i++)
		{
			int v=dag[u][i];
			ind[v]--;
			if(ind[v]==0)	q.push(v);
		}
	}
}
void solve()
{
	int h1,m1,h2,m2;
	for(int i=0;i<n*2;i++)
		if(!dfn[i])	tarjan(i);
	for(int i=0;i<n;i++)
		if(id[i]==id[i+n])
		{
			printf("NO\n");
			return;
		}
		else ha[id[i]]=id[i+n],ha[id[i+n]]=id[i];
	builddag();
	topsort();
	printf("YES\n");
	for(int i=0;i<n;i++)
	{
		if(color[id[i]]==1)
		{
			h1=s[i]/60;
			m1=s[i]%60;
			h2=(s[i]+d[i])/60;
			m2=(s[i]+d[i])%60;
			printf("%02d:%02d %02d:%02d\n",h1,m1,h2,m2);
		}
		else
		{
			h2=t[i]/60;
			m2=t[i]%60;
			h1=(t[i]-d[i])/60;
			m1=(t[i]-d[i])%60;
			printf("%02d:%02d %02d:%02d\n",h1,m1,h2,m2);
		}
	}
}
int main()
{
	int hour,miniute;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i=0;i<n;i++)
		{
			scanf("%d:%d",&hour,&miniute);
			s[i]=hour*60+miniute;
			scanf("%d:%d",&hour,&miniute);
			t[i]=hour*60+miniute;
			scanf("%d",&d[i]);
		}
		build();
		solve();
	}	
	return 0;
}
