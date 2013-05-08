#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100005;
vector<int> need[maxn],gain[maxn];
int cap[maxn];
int n,m;
int main()
{
	int ca,u;
	bool vis[maxn];
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		for(int i = 0;i <= n; i++)
		{
			need[i].clear();
			gain[i].clear();
		}
		for(int i = 0; i < m; i++) scanf("%d",&cap[i]);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&u);
				need[j].push_back(u);
			}
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&u);
				gain[j].push_back(u);
			}
		int ans = 0;
		bool flag = 1;
		memset(vis,0,sizeof(vis));
		while(ans < n&&flag)
		{
			flag = 0;
			for(int i = 0; i < n; i++)
			{
				int j;
				if(vis[i]) continue;
				for(j = 0; j < need[i].size(); j++)
				{
					if(cap[j] < need[i][j])	break;
				}
				if(j == need[i].size())
				{
					flag = 1;
					vis[i] = 1;
					ans++;
					for(int k = 0; k < j; k++)
						cap[k] += gain[i][k];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
