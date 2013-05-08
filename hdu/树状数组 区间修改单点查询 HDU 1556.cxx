#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
const int maxn = 100005;
using namespace std;
int n,a[maxn],c[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void update(int pos,int num)
{
	while(pos <= n)
	{
		c[pos]+=num;
		pos+=lowbit(pos);
	}
}
int query(int pos)
{
	int sum = 0;
	while(pos > 0)
	{
		sum+=c[pos];
		pos-=lowbit(pos);
	}
	return sum;
}

int main()
{
	int u,v;
	while(scanf("%d",&n)&&n)
	{
		memset(c,0,sizeof(c));
		for(int i = 1; i <= n;i++)
		{
			scanf("%d%d",&u,&v);
			update(u,1);//保证只有u到v被更新了
			update(v+1,-1);
		}
		for(int i = 1; i <= n;i++)
		{
			if(i == 1) printf("%d",query(i));
			else printf(" %d",query(i));
		}
		printf("\n");
	}
	return 0;
}
