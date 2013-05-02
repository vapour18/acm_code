#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,pay[35];
int ans;
bool cmp(const int &a,const int &b)
{
	return a>b;
}
void dfs(int dep,int s)
{
	
	if(s>m)	return;
	if(dep>=n)
	{
		ans=max(ans,s);
		return;
	}
	int tmp=s;
	for(int i=dep;i<n;i++)
	{
		tmp+=pay[i];
	}
	if(tmp<ans)		return;
	dfs(dep+1,s);
	dfs(dep+1,s+pay[dep]);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)	scanf("%d",&pay[i]);
		sort(pay,pay+n,cmp);
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
}
