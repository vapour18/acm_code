#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
struct node{
	int next[55];
	int fail,cnt;
	void init()
	{
		memset(next,0,sizeof(next));
		fail=cnt=0;
	}
}trie[2555];
struct biginteger
{
	int bit[105];
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	biginteger operator+(const biginteger &pos)
	{
		biginteger res;
		res.init();
		for(int i=0;i<105;i++)
		{
			res.bit[i]+=bit[i]+pos.bit[i];
			res.bit[i+1]+=res.bit[i]/10;
			res.bit[i]%=10;
		}
		return res;
	}
	void print()
	{
		int i;
		for(i=104;i>0&&!bit[i];i--);
		for(int j=i;j>=0;j--)
			cout<<bit[j];
		cout<<endl;
	}
};

int cnt,n,m;
int mp[305];
char str[65];
biginteger dp[55][2555];
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
	trie[p].cnt=1;
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
		for(int i=0;i<n;i++)
		{
			child=trie[p].next[i];
			if(child)
			{
				q.push(child);
				if(p)
				{
					temp=trie[p].fail;
					trie[child].fail=trie[temp].next[i];
				}
				trie[child].cnt+=trie[trie[child].fail].cnt;
			}
			else
				trie[p].next[i]=trie[trie[p].fail].next[i];
		}
	}
}

void solve()
{
	int tmp;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=cnt;j++)
			dp[i][j].init();
	dp[0][0].bit[0]=1;

	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=cnt;j++)
		{
			if(trie[j].cnt)	continue;
			for(int k=0;k<n;k++)
			{
				tmp=trie[j].next[k];
				if(trie[tmp].cnt)	continue;
				dp[i][tmp]=dp[i][tmp]+dp[i-1][j];
			
			}
		}
	}
	biginteger ans;
	ans.init();
	for(int i=0;i<=cnt;i++)
		ans=ans+dp[m][i];
	ans.print();
}
int main()
{
	int p;
	char tmp[65];
	while(scanf("%d%d%d",&n,&m,&p)!=EOF)
	{
		getchar();
		gets(str);
		for(int i=0;i<n;i++)
			mp[(int)str[i]]=i;
		cnt=0;
		trie[0].init();
		while(p--)
		{
			scanf("%s",tmp);
			insert(tmp);
		}
		build_ac();
		solve();
	}
	return 0;
}






