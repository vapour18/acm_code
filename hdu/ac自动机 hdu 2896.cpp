#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node
{
	int id;
	int next[100],fail;
	void init()
	{
		id=0;
		fail=0;
		memset(next,0,sizeof(next));
	}
}trie[100000];
char str[10005];
int cnt,ans;
bool mark[1005];
void insert(char *str,int id)
{
	int p=0,x;
	for(int i=0;str[i];i++)
	{
		x=str[i]-30;
		if(!trie[p].next[x])
		{
			trie[++cnt].init();
			trie[p].next[x]=cnt;
		}
		p=trie[p].next[x];
	}
	trie[p].id=id;
}
void build_ac()
{
	queue<int> q;
	int p,tmp,child;
	q.push(0);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(int i=0;i<100;i++)
		{
			child=trie[p].next[i];
			if(child)
			{
				q.push(child);
				if(p==0)	trie[child].fail=0;
				else
				{
					tmp=trie[p].fail;
					for(;tmp&&!trie[tmp].next[i];tmp=trie[tmp].fail);
					if(trie[tmp].next[i])
						trie[child].fail=trie[tmp].next[i];
					else
						trie[child].fail=0;
				}
			}
			else
				trie[p].next[i]=trie[trie[p].fail].next[i];
		}
	}
}
bool query(int num)
{
	int p=0,x,tmp;
	bool flag=0;
	for(int i=0;str[i];i++)
	{
		x=str[i]-30;
		if(trie[p].next[x])	p=trie[p].next[x];
		else
		{
			tmp=trie[p].fail;
			for(;tmp&&!trie[tmp].next[x];tmp=trie[tmp].fail);
			if(trie[tmp].next[x])
				p=trie[tmp].next[x];
			else
				p=0;
		}
		if(trie[p].id)
		{
			flag=1;
			mark[trie[p].id]=1;
			tmp=trie[p].fail;
			while(tmp&&!mark[trie[tmp].id])
			{
				mark[trie[tmp].id]=1;
				tmp=trie[tmp].fail;
			}
		}
	}
	if(flag)	return 1;
	return 0;
}
int main()
{
	int n,m;
	char temp[10005];
	while(scanf("%d",&n)!=EOF)
	{
		cnt=ans=0;
		trie[0].init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",temp);
			insert(temp,i);
		}
		//cout<<"0\n";
		build_ac();
		//cout<<"1\n";
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%s",str);
			memset(mark,0,sizeof(mark));
			if(query(i))
			{
				ans++;
				printf("web %d:",i);
				for(int j=1;j<=n;j++)
				{
					if(mark[j])
						printf(" %d",j);
				}
				printf("\n");
			}
		}
		 printf("total: %d\n",ans);
	}
}

