#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node
{
	int cnt;
	int next[26],fail;
	void init()
	{
		cnt=0;
		fail=-1;
		memset(next,-1,sizeof(next));
	}
}trie[500005];
char str[5100005],tstr[5100005];
int cnt,ans;

void insert(char *str)
{
	int p=0,x;
	for(int i=0;str[i];i++)
	{
		x=str[i]-'A';
		if(trie[p].next[x]==-1)
		{
			trie[++cnt].init();
			trie[p].next[x]=cnt;
		}
		p=trie[p].next[x];
	}
	trie[p].cnt++;
}
void build_ac()//初始化fail，bfs
{
	queue<int> q;
	int root=0;
	q.push(0);
	while(!q.empty())
	{
		int p=q.front();
		int temp=0;
		q.pop();
		for(int i=0;i<26;i++)
		{
			int child=trie[p].next[i];
			if(child!=-1)
			{
				if(p==root)
					trie[child].fail=root;//第一个元素的fail指向根
				else
				{
					temp=trie[p].fail;//失败指针
					while(temp!=-1)//两种情况，空或者找到匹配
					{
						if(trie[temp].next[i]!=-1)//找到匹配
						{
							trie[child].fail=trie[temp].next[i];
							break;
						}
						temp=trie[temp].fail;
					}
					if(temp==-1)//为空则从头匹配
						trie[child].fail=root;
				}
				q.push(child);
			}
		}
	}
}

int query(char *str)
{
	int index,len,result,root=0;
	int p=root;
	result=0;
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		index=str[i]-'A';
		while(trie[p].next[index]==-1&&p!=root)
			p=trie[p].fail;
		p=trie[p].next[index];
		if(p==-1) p=root;
		int temp=p;
		while(temp!=root&&trie[temp].cnt!=-1)
		{
			result+=trie[temp].cnt;
			trie[temp].cnt=-1;
			temp=trie[temp].fail;
		}
	}
	return result;
}

int main()
{
	int ca;
	int n;
	char tmp[1285];
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		trie[0].init();//根为0
		cnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",tmp);
			insert(tmp);
		}
		build_ac();
		scanf("%s",tstr);
		int i,j,r;
		for(i=0,j=0;tstr[i];i++)
		{
			if(tstr[i]>='A'&&tstr[i]<='Z')
				str[j++]=tstr[i];
			else if(tstr[i]=='[')
			{
				int num=0;
				while(tstr[++i]>='0'&&tstr[i]<='9')
				{
					num=num*10+tstr[i]-'0';
				}
				r=0;
				for(;tstr[i]!=']';i++)
					tmp[r++]=tstr[i];
				i--;
				for(int k=0;k<num;k++)
				{
					for(int ii=0;ii<r;ii++)
						str[j++]=tmp[ii];
				}
			}
		}
		str[j]='\0';
		int ans=0;
		ans+=query(str);
		j=strlen(str);
		tstr[j--]='\0';

		for(i=0;str[i];i++,j--)
		{
			tstr[j]=str[i];
		}
		ans+=query(tstr);
		printf("%d\n",ans);
	}
	return 0;
}
