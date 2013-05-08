#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define inf 1111111111
using namespace std;
struct node{
	int cnt,fail;
	int next[5];
	void init()
	{
		cnt=fail=0;
		memset(next,0,sizeof(next));
	}
}trie[2005];
int cnt;
char str[1005];
int dp[1005][1005],mp[200];
void insert(char *str)
{
	int p=0,x;
	for(int i=0;str[i];i++)
	{
		x=mp[(int)str[i]];
		if(!trie[p].next[x])
		{
			trie[++cnt].init();
			trie[p].next[x]=cnt;
		}
		p=trie[p].next[x];
	}
	trie[p].cnt++;
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
				if(p==0)	trie[child].fail=0;//为根节点
				else
				{
					temp=trie[p].fail;//该节点的失败指针
					for(;temp&&!trie[temp].next[i];temp=trie[temp].fail);//构造fail指针
					if(trie[temp].next[i])
						trie[child].fail=trie[temp].next[i];
					else
						trie[child].fail=0;
					
				}
				if(trie[trie[child].fail].cnt)//注意！！本题的坑。
					trie[child].cnt++;
			}
			else
				trie[p].next[i]=trie[trie[p].fail].next[i];
		}
	}
}
void solve()
{
	int cur;
	dp[0][0]=0;
	for(int i=1;str[i];i++)
	{
		for(int j=0;j<=cnt;j++)
		{
			if(trie[j].cnt)	continue;
			for(int k=0;k<4;k++)
			{
				cur=trie[j].next[k];
				if(trie[cur].cnt)	continue;
				if(k==mp[(int)str[i]])
					dp[i][cur]=min(dp[i][cur],dp[i-1][j]);
				else
					dp[i][cur]=min(dp[i][cur],dp[i-1][j]+1);
			}
		}
	}
	int ans=inf,len=strlen(str+1);
	for(int i=0;i<=cnt;i++)
	{
		if(trie[i].cnt)	continue;
		ans=min(ans,dp[len][i]);
	}
	if(ans==inf)	printf("-1\n");
	else
		printf("%d\n",ans);
}
int main()
{
	int n,ca=1;
	char tmp[35];
	mp['A']=0,mp['C']=1,mp['G']=2,mp['T']=3;
	while(scanf("%d",&n)&&n)
	{
		trie[0].init();
		cnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",tmp);
			insert(tmp);
		}
		build_ac();
		//cout<<cnt<<endl;
		scanf("%s",str+1);
		for(int i=0;i<=(int)strlen(str+1);i++)
			for(int j=0;j<=1500;j++)
				dp[i][j]=inf;
		printf("Case %d: ",ca++);
		solve();
	}
	return 0;
}
