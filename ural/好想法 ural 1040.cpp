//题意：一个无向图，给每条边标号，使得每个顶点延伸出的所有边的标号互质。
//曾神的神思路：只要保证一个点延伸出的两条边互质，就可以保证所有都互质。而两个连续的整数都是互质的，所以只要dfs一遍就可以了
//ym！！
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=75;
struct Edge{
	int v,next,id;
}edge[maxn*maxn];
int head[maxn],en,num=0;
bool vis[maxn]={0},ve[maxn*maxn]={0};
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int u)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!ve[i]&&!ve[i^1])	ve[i]=1,edge[i].id=++num;
		if(!vis[v])
		{
			vis[v]=1;
			dfs(v);
		}
	}
}
int main()
{
	int n,m;
	int u,v;
	memset(head,-1,sizeof(head));
	en=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1);
	printf("YES\n");
	for(int i=0;i<2*m;i+=2)
		printf("%d ",edge[i].id?edge[i].id:edge[i^1].id);
	printf("\n");
	return 0;
}