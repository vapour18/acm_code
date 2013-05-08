#include<cstdio>
#include<cstring>
#include<cstring>
#include<vector>
using namespace std;
struct Edge
{
	int v,next;
}edge[2*1505];

int dp[1505][2],head[1505];
int n,en;
bool flag[1505];
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int x)
{
	flag[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!flag[v])
		{
			dfs(v);
			dp[x][0]+=dp[v][1];
			dp[x][1]+=(min(dp[v][0],dp[v][1]));
		}
	}
}
int main()
{
	int num,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		memset(flag,0,sizeof(flag));
		memset(head,-1,sizeof(head));
		en=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d:(%d)",&a,&num);
			while(num--)
			{
				scanf("%d",&b);
				addedge(a,b);
				addedge(b,a);
			}
		}
		for(int i=0;i<=n;i++)
			dp[i][0]=0,dp[i][1]=1;
		dfs(0);
		printf("%d\n",min(dp[0][0],dp[0][1]));
	}	
}
