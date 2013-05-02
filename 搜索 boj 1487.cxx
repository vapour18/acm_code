//搜索
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn = 1005;
int num[15],l,fx,ans,gx,x;
void dfs(int f,int g,int cur,int dep,int sum)
{
	if(cur >= x) return;
	if(f <= fx&&g >= gx)
	{
		gx = g;
		if(cur > ans) ans = cur;
	}
	if(dep==-1) return ;
	if(g+(dep+1)*9<gx) return;//重要简单有效的剪枝
	for(int i = 0;i <= 9; i++)
		if(cur*10+i <= sum*10+num[dep])
			dfs(f^i,g+i,cur*10+i,dep-1,sum*10+num[dep]);
}
int main()
{
	int ca,n;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		l = 0,fx = gx = ans = 0;
		x = n;
		while(n)
		{
			num[l++] = n%10;
			fx^=(n%10);
			n/=10;
		}
		dfs(0,0,0,l-1,0);
		printf("%d\n",ans);
	}
	return 0;
}
