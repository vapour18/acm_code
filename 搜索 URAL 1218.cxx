#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 305;
int n,head[maxn],en;
bool vis[maxn],flag;
struct Edge{
	int v,next;
}edge[maxn*maxn*5];
struct Jedi{
	char name[55];
	int a,b,c;
	bool operator < (const Jedi &x)const{
		if(x.a<a&&x.b<b) return 1;
		if(x.c<c&&x.b<b) return 1;
		if(x.a<a&&x.c<c) return 1;
		return 0;
	}
}jedi[maxn];

void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}

bool bfs(int x)
{
	int u,cnt = 1;
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty())
	{
		u = q.front();q.pop();
		if(cnt == n) {flag = 1;return flag;}
		for(int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if(vis[v]) continue;
			q.push(v);
			vis[v] = 1;
			cnt ++;
		}
	}
	return flag;
}
int main()
{
	memset(head,-1,sizeof(head));
	en = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%s%d%d%d",jedi[i].name,&jedi[i].a,&jedi[i].b,&jedi[i].c);
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			if(jedi[i] < jedi[j]) addedge(i,j);
			else addedge(j,i);
		}
	for(int i = 0; i < n; i++)
	{
		memset(vis,0,sizeof(vis));
		flag = 0 , vis[i] = 1;
		if(bfs(i))
			printf("%s\n",jedi[i].name);
	}
}

