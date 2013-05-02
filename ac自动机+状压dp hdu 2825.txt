#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
const int mod=20090717;
using namespace std;
struct node{
	int cnt,fail;
	int next[26];
	void init()
	{
		cnt=fail=0;
		memset(next,0,sizeof(next));
	}
}trie[100005];
int cnt;
int dp[27][115][1<<10];
int n,m,v;

void insert(char *str,int k)
{
	int p=0,x;
	for(int i=0;str[i];i++)
	{
		x=str[i]-'a';
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
		for(int i=0;i<26;i++)
		{
			child=trie[p].next[i];
			if(child)
			{
				q.push(child);
				if(p)//´´½¨Ê§°ÜÖ¸Õë
				{
					temp=trie[p].fail;
					trie[child].fail=trie[temp].next[i];
				}
				trie[child].cnt|=trie[trie[child].fail].cnt;
			}
			else
				trie[p].next[i]=trie[trie[p].fail].next[i];
		}
	}
}
bool find(int x)
{
	int num=0;
	while(x)
	{
		num+=(x&1);
		x>>=1;
	}
	return num>=v;
}
void solve()
{
	int p;
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<=cnt;j++)
		{
			for(int r=0;r<(1<<m);r++)
			{
				if(!dp[i][j][r])	continue;
				for(int k=0;k<26;k++)
				{		
					p=trie[j].next[k];
					dp[i+1][p][trie[p].cnt|r]+=dp[i][j][r];
					dp[i+1][p][trie[p].cnt|r]%=mod;
				}
			}
		}
	}
	//cout<<"****\n";
	int ans=0;
	for(int i=0;i<(1<<m);i++)
	{
		bool flag=find(i);
		for(int j=0;j<=cnt&&flag;j++)
		{
			ans+=dp[n][j][i];
			ans%=mod;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	char tmp[15];
	while(scanf("%d%d%d",&n,&m,&v)&&(n+m+v))
	{
		trie[0].init();
		cnt=0;
		for(int i=0;i<m;i++)
		{
			scanf("%s",tmp);
			insert(tmp,i);
		}
		
		build_ac();
		
		solve();
	}
}



