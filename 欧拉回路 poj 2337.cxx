/*
将所有单词首尾相连，一开始往哈密顿回路方向想，然后没有很好的实现方法。
后来发现可以把单词看成边，首尾的字母看成节点，然后就变成了26个节点的欧拉回路。
比较难实现的地方是要按字典序输出合法路径。普通的邻接表似乎实现不了这个功能，所以用vector数组记录边信息，然后排序就可以按顺序访问边
这题比较坑的地方是要判断图是否连通，可以用并查集判断。
最后就是欧拉回路的模板……
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int maxn=26;
char str[maxn][75];
struct Edge{
	int v,vis;
	char word[35];
	Edge()
	{
		vis=0;
		v=-1;
	}
	bool operator <(const Edge &n) const
	{
		return strcmp(word,n.word)<0;
	}
};
vector<Edge> head[35];//因为要排序,所以用vector
stack<char*> sta;
int f[maxn];
bool vis[maxn],flag;
void addedge(int u,int v,char str[])
{
	Edge tmp;
	tmp.v=v;
	strcpy(tmp.word,str);
	head[u].push_back(tmp);
}
int find(int x)
{
	if(x!=f[x])
		return f[x]=find(f[x]);
	return f[x];
}
void euler(int u)//o(e)的算法
{
	for(int i=0;i<(int)head[u].size();i++)
	{
		int v=head[u][i].v;
		if(!head[u][i].vis)
		{
			head[u][i].vis=1;
			euler(v);
			sta.push(head[u][i].word);
		}
	}
}
void init()
{
	for(int i=0;i<26;i++)
	{
		head[i].clear();
		f[i]=i;
	}
	memset(vis,0,sizeof(vis));
	flag=1;
	while(!sta.empty())	sta.pop();
}
void print()
{
	char *str=sta.top();
	sta.pop();
	printf("%s",str);
	while(!sta.empty())
	{
		str=sta.top();
		sta.pop();
		printf(".%s",str);
	}
	printf("\n");
}
int main()
{
	int ca,ind[maxn],ond[maxn],u,v,x,y,s,t,m;
	char str[35];
	scanf("%d",&ca);
	while(ca--)
	{
		init();
		scanf("%d",&m);
		memset(ind,0,sizeof(ind));
		memset(ond,0,sizeof(ond));
		for(int i=1;i<=m;i++)
		{
			scanf("%s",str);
			u=str[0]-'a';
			v=str[strlen(str)-1]-'a';
			addedge(u,v,str);
			ind[v]++,ond[u]++;
			vis[u]=1,vis[v]=1;
			x=find(u),y=find(v);//用并查集判断图是否连通
			if(x!=y)	f[y]=x;
		}
		int cnt=0;
		for(int i=0;i<26;i++)
			if(vis[i]&&f[i]==i)	cnt++;
		if(cnt!=1)	flag=0;

		cnt=0,s=-1,t=-1;
		for(int i=0;i<26&&flag;i++)
		{
			if(ind[i]!=ond[i])//判断入度和出度
			{
				cnt++;
				if(ind[i]+1==ond[i])
					s=i;
				else if(ind[i]==ond[i]+1)
					t=i;
				else if(abs(ind[i]-ond[i])>1||cnt>2)
					flag=0;
			}
		}
		if(cnt!=0&&(s==-1||t==-1))	flag=0;
		if(!flag)
		{
			printf("***\n");
			continue;
		}
		for(int i=0;i<26;i++)
			if(vis[i])	sort(head[i].begin(),head[i].end());
		if(s!=-1)
			euler(s);
		else
		{
			for(int i=0;i<26;i++)
				if(vis[i])
				{
					euler(i);
					break;
				}
		}
		print();
	}
	return 0;
}
