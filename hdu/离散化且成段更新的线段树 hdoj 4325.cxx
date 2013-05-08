//求区间被重复覆盖了几次
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 100005
using namespace std;
int li[maxn],ri[maxn],x[maxn*3],n,m;
int delta[maxn<<4],q[maxn];
void build(int l,int r,int rt)
{
	delta[rt]=0;
	if(l==r)	return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void pushdown(int rt)
{
	if(delta[rt])
	{
		delta[rt<<1]+=delta[rt];
		delta[rt<<1|1]+=delta[rt];
		delta[rt]=0;
	}
	return;
}
void update(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R) {
		delta[rt]++;
		return ;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R , lson);
	if (m < R) update(L , R  , rson);
}
int query(int q,int l,int r,int rt)
{
	if(l==r)
		return delta[rt];
	pushdown(rt);
	int m=(l+r)>>1;
	if(q<=m)	return query(q,lson);
	else return query(q,rson);
}
int main()
{
	int t,nn;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{
		nn=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&li[i],&ri[i]);
			x[nn++]=li[i];
			x[nn++]=ri[i];
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&q[i]);
			x[nn++]=q[i];
		}
		sort(x,x+nn);
		
		nn=unique(x,x+nn)-x;
		
		build(1,nn,1);
		for(int i=1;i<=n;i++)
		{
			li[i]=lower_bound(x,x+nn,li[i])-x+1;
			ri[i]=lower_bound(x,x+nn,ri[i])-x+1;
			update(li[i],ri[i],1,nn,1);
		}
		printf("Case #%d:\n",ca);
		for(int i=1;i<=m;i++)
		{
			q[i]=lower_bound(x,x+nn,q[i])-x+1;
			printf("%d\n",query(q[i],1,nn,1));
		}
	}
}



