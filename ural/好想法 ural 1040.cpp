//���⣺һ������ͼ����ÿ���߱�ţ�ʹ��ÿ����������������бߵı�Ż��ʡ�
//�������˼·��ֻҪ��֤һ����������������߻��ʣ��Ϳ��Ա�֤���ж����ʡ��������������������ǻ��ʵģ�����ֻҪdfsһ��Ϳ�����
//ym����
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