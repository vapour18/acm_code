//把一个图分成两个点集，一个点集中的点到另一个集合至少有一条边
//用bfs拓展与该点相连的点，分成两个集合
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
bool map[105][105];
int state[105];
int n;
void solve()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(state[i]==-1)
		{
			state[i]=0;
			q.push(i);
			while(!q.empty())
			{
				q.pop();
				for(int j=1;j<=n;j++)
					if(map[i][j]&&state[j]==-1)
					{
						state[j]=1;
						q.push(j);
					}
			}
		}
	}
}
int main()
{
	int v;
	scanf("%d",&n);
	memset(map,0,sizeof(map));
	memset(state,-1,sizeof(state));
	for(int i=1;i<=n;i++)
	{
		
		while(scanf("%d",&v)&&v)
			map[i][v]=1;	
	}
	solve();
	int ans=0;
	for(int i=1;i<=n;i++)
		if(state[i]==1)		ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(state[i])		
			printf("%d ",i);
	printf("\n");
	return 0;
}

