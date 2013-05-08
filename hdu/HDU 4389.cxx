//数位DP模板
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pow[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int num[11],dp[10][82][82][82];//d[l][i][j][k]表示前l位和为i模j的结果为k的数的个数
int dfs(int l,int s,int m,int r,bool e)//e表示最高位是否有限制
{
	if(l==-1)	return s==0&&r==0;
	if(!e&&dp[l][s][m][r]!=-1)	return dp[l][s][m][r];
	if(s>(l+1)*9)	return  dp[l][s][m][r]=0;//神剪枝,减去大量不可行!
	int u= min(s,e?num[l]:9),res=0;//当前位最大是多少
	for(int d=0;d<=u;d++)
		res+=dfs(l-1,s-d,m,(r+m-d*pow[l]%m)%m,e&&d==u);
	return e? res:dp[l][s][m][r]=res;//如果有限制就不能记忆化了
}
int solve(int n)
{
	int l=0,ans=0;
	while(n)
	{
		num[l++]=n%10;//记下每一位的数值
		n/=10;
	}
	for(int i=1;i<=81;i++)
		ans+=dfs(l-1,i,i,0,1);
	return ans;
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	for(int ca=1;ca<=t;ca++)
	{
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",ca,solve(b)-solve(a-1));
	}
}
