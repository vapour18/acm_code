//UVAlive 3939
//优化的并查集,离线做法
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
#define inf 1e9
using namespace std;
int ans[1005][1005];
int s,t,n,m,r;
int f[1005],en;
bool flag[1005][1005];
struct Node{
	int u,v,w;
	bool operator <(const Node &b) const{
		return b.w<w;
	}
}a[1005*1005];

struct Que{
	int a,b,r,id;
	bool ans;
	bool operator<(const Que &b)const{
		return b.r<r;
	}
}query[1005*1005];
bool cmp(const Que &a,const Que &b)
{
	return a.id<b.id;
}
int find(int x)
{
	return f[x]==x? x:f[x]=find(f[x]);
}


int main()
{
	int ca=1;
	int x,y;
	while(scanf("%d%d%d",&n,&m,&r)!=EOF)
	{
		en=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		sort(a,a+m);

		for(int i=0;i<r;i++){
			scanf("%d%d%d",&query[i].a,&query[i].b,&query[i].r);
			query[i].id=i;
		}
		sort(query,query+r);
		for(int i=0;i<=n;i++)	f[i]=i;
		int j=0;
		for(int i=0;i<r;i++)
		{
			if(flag[query[i].a][query[i].b])
			{
				query[i].ans=1;
				continue;
			}
			for(;a[j].w>=query[i].r;j++)//每次是从上次的j开始查找,并不是0,否则超时
			{
				x=find(a[j].u),y=find(a[j].v);
				if(x!=y)	f[x]=y;
			}
			if(find(query[i].a)==find(query[i].b))
			{
				query[i].ans=1;
				flag[query[i].a][query[i].b]=flag[query[i].b][query[i].a]=1;
			}
			else   query[i].ans=0;
		}

		sort(query,query+r,cmp);
		printf("Case %d:\n",ca++);
		for(int i=0;i<r;i++)
		{
			if(query[i].ans)	printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
