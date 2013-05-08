#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
struct node{
	int cnt,fail;
	int next[4];
	void init()
	{
		cnt=fail=0;
		memset(next,0,sizeof(next));
	}
}trie[100005];
int cnt;
int dp[2][1005][1<<10];//滚动数组，dp后两个参数：在树上的状态为j，区字符状态压缩状态为k
int n,m,val[15];
int mp(char ch)
{
	if(ch=='A')	return 0;
	if(ch=='G')	return 1;
	if(ch=='C')	return 2;
	else	return 3;
}
void insert(char *str,int k)
{
	int p=0,x;
	for(int i=0;str[i];i++)
	{
		x=mp(str[i]);
		if(!trie[p].next[x])
		{
			trie[++cnt].init();
			trie[p].next[x]=cnt;
		}
		p=trie[p].next[x];
	}
	trie[p].cnt|=(1<<k);
}
void build_ac()
{
	queue<int> q;
	int temp,p=0,child;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			child=trie[p].next[i];
			if(child)
			{
				q.push(child);
				if(p)//创建失败指针
				{
					temp=trie[p].fail;
					trie[child].fail=trie[temp].next[i];
				}
				trie[child].cnt|=trie[trie[child].fail].cnt;//它的失败指针有可能指向给定串
			}
			else
				trie[p].next[i]=trie[trie[p].fail].next[i];
		}
	}
}
int get(int x)
{
	int ans=0;
	for(int i=0;i<n;i++)
		if(x&(1<<i))
			ans+=val[i];
	return ans;
}
void solve()
{
	int ans;
	memset(dp,0,sizeof(dp));//滚动数组
	dp[0][0][0]=1;//表示边界可到达
	for(int i=1;i<=m;i++)
	{
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int j=0;j<=cnt;j++)//自动机上的状态
			for(int k=0;k<4;k++)
				for(int r=0;r<(1<<n);r++)//取出的字符串的状态
					if(dp[(i+1)&1][j][r])//前一个状态可到达
						dp[i&1][trie[j].next[k]][trie[trie[j].next[k]].cnt|r]=1;//取出的字符是累加的！
	}
	ans=-1;
	for(int j=0;j<(1<<n);j++)
		for(int i=0;i<=cnt;i++)
			if(dp[m&1][i][j])
			{
				ans=max(ans,get(j));
				break;
			}
	if(ans<0)		printf("No Rabbit after 2012!\n");
	else	printf("%d\n",ans);
}
int main()
{
	char tmp[15];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		trie[0].init();
		cnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s%d",tmp,&val[i]);
			insert(tmp,i);
		}
		build_ac();
		solve();
	}
}

