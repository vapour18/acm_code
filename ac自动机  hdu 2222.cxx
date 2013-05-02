#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define maxn 500010
char str[1000010];
struct node
{
	node *fail,*next[26];
	int count;
	node()
	{
		fail=NULL;
		count=0;
		for(int i=0;i<26;i++)	next[i]=NULL;
	}
};
node *root;

void insert(char *str)//建立trie树
{
	int temp,len;
	node *p=root;
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		temp=str[i]-'a';
		if(p->next[temp]==NULL)
			p->next[temp]=new node();
		p=p->next[temp];
	}
	p->count++;
}

void build_ac()//初始化fail，bfs
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *p=q.front();
		node *temp=NULL;
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(p->next[i]!=NULL)
			{
				if(p==root)
					p->next[i]->fail=root;//第一个元素的fail指向根
				else
				{
					temp=p->fail;//失败指针
					while(temp!=NULL)//两种情况，空或者找到匹配
					{
						if(temp->next[i]!=NULL)//找到匹配
						{
							p->next[i]->fail=temp->next[i];
							break;
						}
						temp=temp->fail;
					}
					if(temp==NULL)//为空则从头匹配
						p->next[i]->fail=root;
				}
				q.push(p->next[i]);
			}
		}
	}
}

int query()
{
	int index,len,result;
	node *p=root;
	result=0;
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		index=str[i]-'a';
		while(p->next[index]==NULL&&p!=root)
			p=p->fail;
		p=p->next[index];
		if(p==NULL)
			p=root;
		node *temp=p;
		while(temp!=root&&temp->count!=-1)
		{
			result+=temp->count;
			temp->count=-1;
			temp=temp->fail;
		}
	}
	return result;
}
int main()
{
	int ca,num;
	char keyword[51];
	scanf("%d",&ca);
	while(ca--)
	{
		root=new node();
		scanf("%d",&num);
		for(int i=0;i<num;i++)
		{
			scanf("%s",keyword);
			insert(keyword);
		}
		build_ac();
		scanf("%s",str);
		printf("%d\n",query());
	}
	return 0;
}



