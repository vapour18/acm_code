//用五棵线段树记录五个区间
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 100010
using namespace std;
int cnt[maxn<<2],x[maxn],key[maxn];
long long ans[maxn<<2][5];
char op[maxn][10];
void build(int l,int r,int rt)
{
	cnt[rt]=0;
	for(int i=0;i<5;i++)	ans[rt][i]=0;
	if(l==r)	return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void pushup(int rt)
{
	for(int i=0;i<5;i++)
		ans[rt][i]=ans[rt<<1][i]+ans[rt<<1|1][((i-cnt[rt<<1])%5+5)%5];
}
void update(int pos,int flag,int l,int r,int rt)
{
	cnt[rt]+=2*flag-1;
	if(l==r)
	{
		ans[rt][0]=flag*key[pos];
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)	update(pos,flag,lson);
	else update(pos,flag,rson);
	pushup(rt);
}
int main()
{
	int n,u,sets;
	while(scanf("%d",&n)!=EOF)
	{
		u=sets=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",op[i]);
			if(op[i][0]!='s')
				scanf("%d",&x[i]),key[u++]=x[i];
		}
		sort(key,key+u);
		u=unique(key,key+u)-key;
		build(0,u-1,1);
		for(int i=0;i<n;i++)
		{
			int pos=lower_bound(key,key+u,x[i])-key;
			if(op[i][0]=='a')
			{
				sets++;
				update(pos,1,0,u-1,1);
			}
			else if(op[i][0]=='d')
			{
				sets--;
				update(pos,0,0,u-1,1);
			}
			else
			{
				if(sets)
					printf("%lld\n",ans[1][2]);
				else
					printf("0\n");
			}
		}
	}
	return 0;
}
