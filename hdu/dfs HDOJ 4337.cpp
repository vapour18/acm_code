//给出朋友的组合，判断所有人是否能和朋友坐一起，注意桌子是圆形的，首尾必须是朋友！
//dfs
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans[155];
bool a[155][155],vis[155],flag;
void dfs(int x,int dep)
{
	
	if(dep>=n)
	{
		if(a[ans[n-1]][ans[0]]==0)//首尾必须是朋友！
			return;
		flag=1;
		for(int i=0;i<n;i++)
		{
			if(i==0)
				printf("%d",ans[i]);
			else
				printf(" %d",ans[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<=n&&!flag;i++)
	{
		if(a[x][i]&&!vis[i])
		{
			vis[i]=1;
			ans[dep]=i;
			dfs(i,dep+1);
			vis[i]=0;
		}
	}
}
int main()
{
	int u,v;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		flag=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			a[u][v]=a[v][u]=1;
		}
		dfs(1,0);
		if(flag==0)
			printf("no solution\n");
	}
	
	return 0;
}
