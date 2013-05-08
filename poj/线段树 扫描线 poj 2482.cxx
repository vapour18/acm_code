//扫描线
//从每个点往右上方延伸得到一个h * w的矩形，可以得到~~这是一个很明显的，具有扫描线特性的图案
//把每个矩形的下边界加入线段树，并且，该线段赋值为v， 上边界加入线段树，并且，该线段赋值为-v
//线段树维护总的区间内最大的覆盖次数，把每次的sum[1]与ans作比较，能更新就更新。
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
#define maxn 60000
struct Seg
{
	LL l, r, h;
	int s;
	Seg(){}
	Seg(LL a, LL b, LL c, int d) : l(a), r(b), h(c), s(d){}
	bool operator < (const Seg &cmp) const
	{
		if(h == cmp.h) return s < cmp.s;
		return h < cmp.h ;
	}
}p[maxn<<2];
LL x[maxn<<2];
int sum[maxn<<2];
int add[maxn<<2];

void PushUp(int rt)
{
	sum[rt] =  max(sum[rt<<1] , sum[rt<<1|1]);
}

void PushDown(int rt)
{
	if(add[rt])
	{
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt];
		sum[rt<<1|1] += add[rt];
		add[rt] = 0;
	}
}

void update(int L, int R, int k, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		add[rt]+=k;
		sum[rt]+=k;
		return ;
	}
	int m=(l+r)>>1;
	PushDown(rt);
	if(L<= m)	update(L, R, k, lson);
	if(m<R)		update(L, R, k, rson);
	PushUp(rt);
}

int bin(LL key, int n)
{
	int l = 0,r=n-1;
	while(l <= r)
	{
		int m = (l+r) >> 1;
		if(key == x[m])		return m;
		if(x[m] < key)		l = m+1;
		else  				r = m-1;
	}
	return -1;
}

int main()
{
	int n;
	LL a, b, w, h;
	int c;
	while(scanf("%d%lld%lld", &n, &w, &h) != EOF)
	{
		int ans=0,k=0;
		memset(add, 0, sizeof(add));
		memset(sum, 0, sizeof(sum));
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lld%lld%d", &a, &b, &c);
			x[k] = a;
			p[k ++] = Seg(a, a+w, b, c);
			x[k]=a+w;
			p[k ++] = Seg(a, a+w, b+h, -c);
		}
		sort(x, x+k);
		sort(p, p+k);
		int m = 1;
		for(int i = 1; i < k; i ++ )//离散化
		{
			if(x[i]!= x[i-1])
				x[m ++]=x[i];
		}
		
		for(int i = 0; i < k-1; i ++)
		{//这棵线段树是左开右闭的
			int l = bin(p[i].l, m);
			int r = bin(p[i].r, m)-1;//边界
			if(l <= r)
				update(l, r, p[i].s, 0,m-1,1);
			if(ans < sum[1])
				ans = sum[1];
		}
		printf("%d\n", ans);
	}
	return 0;
}
