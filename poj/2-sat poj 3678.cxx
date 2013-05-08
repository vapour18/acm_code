//加边表示条件强制必须满足，不管是否能有成功结果
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=2005;
struct Edge{
	int v,next;
}edge[1000005];
int head[maxn],low[maxn],dfn[maxn],id[maxn];
int en,m,n,num,scc;
bool vis[maxn];
stack<int> sta;
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void tarjan(int v)
{
	low[v]=dfn[v]=num++;
	sta.push(v);
	vis[v]=1;
	for(int i=head[v];i!=-1;i=edge[i].next)
	{
		int x=edge[i].v;
		if(!dfn[x])
		{
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else if(vis[x])// 如果节点v还在栈内
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
bool solve()
{
	bool flag=1;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	for(int i=0;i<=2*(n-1);i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<n;i++)
	{
		if(id[i*2]==id[i*2+1])
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int a,b,c;
	char op[5];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		scc=1,en=0,num=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%s",&a,&b,&c,op);
			if(op[0]=='A')
			{
				if(c==1)//如果a=0，则比不成立，而必不成立的条件是a和a‘之间有边，其他同理
				{
					addedge(a*2,a*2+1);
					addedge(b*2,b*2+1);
				}
				else
				{
					addedge(a*2+1,b*2);
					addedge(b*2+1,a*2);
				}
			}
			else if(op[0]=='O')
			{
				if(c==1)
				{
					addedge(a*2,b*2+1);
					addedge(b*2,a*2+1);
				}
				else
				{
					addedge(a*2+1,a*2);
					addedge(b*2+1,b*2);
				}
			}
			else
			{
				if(c==1）
				{
					addedge(a*2,b*2+1);
					addedge(b*2,a*2+1);
					addedge(a*2+1,b*2);
					addedge(b*2+1,a*2);
				}
				else
				{
					addedge(a*2,b*2);
					addedge(a*2+1,b*2+1);
					addedge(b*2,a*2);
					addedge(b*2+1,a*2+1);
				}
			}
		}
		if(solve())	printf("YES\n");
		else	printf("NO\n");	
	}
	return 0;
}
