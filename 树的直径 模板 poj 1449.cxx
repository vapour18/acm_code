//������ֱ��
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 50005;
const int inf = 111111111;
struct Edge{
	int v,next;
}edge[maxn*15];
int n,en,head[maxn],d1[maxn],d2[maxn],num[maxn];
bool vis[maxn];
void addedge(int u,int v)
{
	edge[en].v = v;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
}
int gao(int x)
{
	int ret = 1;
	for(int i = 2; i*i <= x; i++)
	{
		if(x%i==0)
		{
			ret+=i;
			if(x/i!=i) ret += x/i;
		}	
		if(ret >= x) break;
	}
	return ret;
}
void find()
{
	num[1] = 1;
	for(int i = 2; i < maxn; i++)
		num[i] = gao(i);
}
void dfs1(int u,int pre)//d1[u]��d2[u]��ʾu��Ҷ�ӵ������ʹγ�����
{
	vis[u] = 1;
	d1[u] = d2[u] = 0;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == pre) continue;
		dfs1(v,u);
		if(d1[u] < d1[v]+1)
		{
			d2[u] = d1[u];
			d1[u] = d1[v]+ 1;
		}
		else if(d2[u] < d1[v]+1)
			d2[u] = d1[v]+1;
	}
}
void dfs2(int u,int pre)//�൱����һ��Ҷ�ӵ���һ��Ҷ�ӵľ��룬��d1
{
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == pre) continue;
		if(d1[u] > d1[v] + 1) d1[v] = d1[u] + 1;//v����u���������
		else if(d1[v] < d2[u] + 1) d1[v] = d2[u] + 1;//v����ϣ��γ�������
		else if(d2[v] < d2[u] + 1) d2[v] = d2[u] + 1;//����v�Ĵγ�
		dfs2(v,u);
	}
}
int main()
{
	int ca;
	scanf("%d",&ca);
	find();
	while(ca--)
	{
		init();
		scanf("%d",&n);
		for(int i = 2; i <= n; i ++)
		{
			if(num[i] < i)
				addedge(num[i],i),addedge(i,num[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])	dfs1(i,-1),dfs2(i,-1);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans,d1[i]);//���������������Ҷ��֮��ľ���
		printf("%d\n",ans);
	}
	return 0;
}