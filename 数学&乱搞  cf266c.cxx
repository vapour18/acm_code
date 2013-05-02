//关键:以行为顺序处理.找从i到n中1最少的行,可以证明,到第i行,1最少的行的1的个数小于等于i-1
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int maxn = 1005;
vector<int> at,ai,aj;
int sr[maxn] = {0},n,ans = 0;
bool g[maxn][maxn];
bool vis[maxn];//为啥放里面会re?不解
int main()
{
	int u,v,m,misdf

	
	stack<int> sta;
	if(!sta.empty()) sta.pop();
	memset(g,0,sizeof(g));
	scanf("%d",&n);
	for(int i = 1;i <n ;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v] = 1;
		sr[u]++;
	}	
	for(int i = 1; i <= n ; i++)
	{
		m = sr[i],mi = i;
		for(int j = i+1; j <= n; j++)
			if(sr[j] < m)	m = sr[j], mi = j;
		if(mi!=i)
		{
			swap(g[i],g[mi]);
			swap(sr[i],sr[mi]);
			at.push_back(1);
			ai.push_back(i),aj.push_back(mi);
		}
		for(int j = 1; j < i ;j++)
		{
			if(g[i][j] == 0 &&!vis[j]) sta.push(j);
			else vis[j] = 1;
		}
		for(int j = i; j <= n; j++)
		{
			if(g[i][j])
			{
				int t = sta.top();sta.pop();
				for(int k = 1; k <= n; k++)
					swap(g[k][t],g[k][j]);
				vis[t] = 1;
				at.push_back(2);
				ai.push_back(t),aj.push_back(j);
			}
		}
	}
	printf("%d\n",at.size());
	for(int i = 0; i<(int)at.size() ; i++)
		printf("%d %d %d\n",at[i],ai[i],aj[i]);
	return 0;
}