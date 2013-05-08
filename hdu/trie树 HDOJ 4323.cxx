//trieÊ÷
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Tree{
	char str[15];
	int next[15];
}tree[1505];
int dp[15][15],cnt;
int lcs(char s1[],char s2[])
{
	int l1=strlen(s1);
	int l2=strlen(s2);
	dp[0][0]=0;
	for(int i=1;i<=l1;i++)	dp[i][0]=i;
	for(int i=1;i<=l2;i++)	dp[0][i]=i;
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			if(s1[i]==s2[j])
				dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j]+1,dp[i][j-1]+1));
			else
				dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j]+1,dp[i][j-1]+1));
		}
	}
	if(l1>l2)	return l1-dp[l1][l2];
	else return l2-dp[l1][l2];
}
void build(char s[],int x)
{
	int co=lcs(s,tree[x].str);
	if(tree[x].next[co]==-1)
	{
		tree[x].next[co]=++cnt;
		memset(tree[cnt].next,-1,sizeof(tree[cnt].next));
		strcpy(tree[cnt].str,s);
		return;
	}
	build(s,tree[x].next[co]);
}
int solve(char s[],int n,int x)
{
	int co=lcs(s,tree[x].str);
	int ans=0,i,ed;
	if(co<=n)	ans++;
	if(co-n<0)	i=0;
	else	i=co-n;
	if(co+n>15)		ed=15;
	else	ed=co+n;
	for(;i<=ed;i++)
		if(tree[x].next[i]!=-1)
			ans+=solve(s,n,tree[x].next[i]);
	return ans;
}
int main()
{
	int t,n,m,a;
	char tmp[15];
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{
		cnt=0;
		scanf("%d%d",&n,&m);
		scanf("%s",tree[0].str);
		memset(tree[0].next,-1,sizeof(tree[0].next));
		for(int i=1;i<n;i++)
		{
			scanf("%s",tmp);
			build(tmp,0);
		}
		printf("Case #%d:\n",ca);
		for(int i=0;i<m;i++)
		{
			scanf("%s%d",tmp,&a);
			printf("%d\n",solve(tmp,a,0));
		}
	}
}
