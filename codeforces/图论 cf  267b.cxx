//题意：相当于一根棍子的两端有数字0~7，只有数字相同才能相邻，可以翻转，问如何摆符合要求，或者无解
/*
思路：记录每种首尾的个数，用于之后的dfs。并且如果度为奇数超过2个则肯定不可行，dfs记录编号顺序，之后就暴力找
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 105;
int g[maxn][maxn],n,u[maxn],v[maxn];
vector<int> ans;
void dfs(int x)
{
	for(int i = 0; i < 7;i++)
	{
		if(g[x][i]) 
		{
			g[x][i]--,g[i][x]--;
			dfs(i);
		}
	}
	ans.push_back(x);
}
int main()
{
	int ind[maxn]={0},s;
	bool flag = 1,vis[maxn]={0};
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]][v[i]]++,g[v[i]][u[i]]++;
		ind[u[i]]++,ind[v[i]]++;
		s = u[i];
	}
	int cnt = 0;
	for(int i = 0;i < 7; i++)
		if(ind[i]%2) s = i,cnt++;
	dfs(s);
	if(cnt > 2 ||ans.size()!=n+1) printf("No solution\n");
	else
	{
		for(int i = 0; i < n ; i++)
			for(int j = 0; j < n; j++)
			{
				if(vis[j]) continue;
				
				if(ans[i]==u[j]&&ans[i+1]==v[j])
				{
					vis[j] = 1;
					printf("%d +\n",j+1);
					break;
				}
				else if(ans[i]==v[j]&&ans[i+1]==u[j])
				{
					vis[j] = 1;
					printf("%d -\n",j+1);
					break;
				}
			}
	}
}