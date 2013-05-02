#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
const int maxn = 50005;
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
	int cas,u,v;
	char str[15];
	scanf("%d",&cas);
	for(int ca = 1;ca <= cas; ca++)
	{
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for(int i = 1 ; i <= n; i++)
		{
			scanf("%d",&a[i]);
			update(i,a[i]);
		}
		printf("Case %d:\n",ca);
		while(scanf("%s",str)&&str[0]!='E')
		{
			scanf("%d%d",&u,&v);
			if(str[0] == 'Q')
				printf("%d\n",query(v)-query(u-1));
			else if(str[0] == 'A')
				update(u,v);
			else
				update(u,-v);
		}
	}
	return 0;
}
