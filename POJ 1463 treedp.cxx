#include<cstdio>
#include<cstring>
#include<cstring>
#include<vector>
using namespace std;
vector<int> edge[1505];
int dp[1505][2];
int n;
bool flag[1505];
void dfs(int x)
{
	flag[x]=1;
	for(int i=0;i<edge[x].size();i++)
	{
		if(!flag[edge[x][i]])
		{
			dfs(edge[x][i]);
			dp[x][0]+=dp[edge[x][i]][1];
			dp[x][1]+=(min(dp[edge[x][i]][0],dp[edge[x][i]][1]));
		}
	}
}
int main()
{
	int num,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
		{
			scanf("%d:(%d)",&a,&num);
			while(num--)
			{
				scanf("%d",&b);
				edge[a].push_back(b);
				edge[b].push_back(a);
			}
		}
		for(int i=0;i<=n;i++)
			dp[i][0]=0,dp[i][1]=1;
		dfs(0);
		printf("%d\n",min(dp[0][0],dp[0][1]));
		for(int i=0;i<=n;i++)
			edge[i].clear();
	}	
}
