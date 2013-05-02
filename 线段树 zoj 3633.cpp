#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 500005 
using namespace std;
int x[maxn<<2],pre[maxn];//x表示与x[i]重复的左边的第一个数的位置
struct NODE{
	int pos,val;
	bool operator < (const NODE a) const{//排序，第一关键字为数值，第二关键字为位置
		if(a.val!=val)	return a.val>val;
		else return a.pos>pos;
	}
}num[maxn];
void build(int l,int r,int rt)
{
	x[rt]=0;
	if(l==r)
		return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void update(int w,int pos,int l,int r,int rt)
{
	if(l==r)
	{
		x[rt]=w;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)	update(w,pos,lson);
	else		update(w,pos,rson);
	x[rt]=max(x[rt<<1],x[rt<<1|1]);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
		return x[rt];
	int m=(l+r)>>1;
	int ret=0;
	if(L<=m)	ret=max(ret,query(L,R,lson));
	if(R>m)	ret=max(ret,query(L,R,rson));
	return ret;
}
int main()
{
	int n,q;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i].val);
			num[i].pos=i;
			pre[i]=num[i].val;
		}
		build(1,n,1);
		sort(num+1,num+1+n);
		for(int i=1;i<n;i++)
		{
			if(num[i].val==num[i+1].val)
				update(num[i].pos,num[i+1].pos,1,n,1);//遇到相同的就更新
		}
		scanf("%d",&q);
		int a,b,ans;
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&a,&b);
			ans=query(a,b,1,n,1);
			if(ans<a)	printf("OK\n");
			else	printf("%d\n",pre[ans]);
		}
		printf("\n");
	}
	return 0;
}