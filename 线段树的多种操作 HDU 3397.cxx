//线段树的多种操作
//区间更新，异或，区间合并
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100010;
using namespace std;
int num1[maxn<<2],num0[maxn<<2];//区间元素和
int lsum1[maxn<<2],rsum1[maxn<<2],sum1[maxn<<2];//最长连续1
int lsum0[maxn<<2],rsum0[maxn<<2],sum0[maxn<<2];//最长连续0
int col[maxn<<2],xo[maxn<<2];//两类延迟标记
int tmp;
void pushup(int rt,int len)
{//左右合并
	num0[rt]=num0[rt<<1]+num0[rt<<1|1];
	num1[rt]=num1[rt<<1]+num1[rt<<1|1];
		
	lsum0[rt]=lsum0[rt<<1];
	rsum0[rt]=rsum0[rt<<1|1];
	if(lsum0[rt]==len-(len>>1))	lsum0[rt]+=lsum0[rt<<1|1];
	if(rsum0[rt]==len>>1)	rsum0[rt]+=rsum0[rt<<1];
	sum0[rt]=max(lsum0[rt<<1|1]+rsum0[rt<<1],max(sum0[rt<<1],sum0[rt<<1|1]));
	
	lsum1[rt]=lsum1[rt<<1];
	rsum1[rt]=rsum1[rt<<1|1];
	if(lsum1[rt]==len-(len>>1))	lsum1[rt]+=lsum1[rt<<1|1];
	if(rsum1[rt]==len>>1)	rsum1[rt]+=rsum1[rt<<1];
	sum1[rt]=max(lsum1[rt<<1|1]+rsum1[rt<<1],max(sum1[rt<<1],sum1[rt<<1|1]));
	
}
void cover(int rt,int len,int tp)//区间染色
{
	num0[rt]=lsum0[rt]=rsum0[rt]=sum0[rt]=len*(1-tp);
	num1[rt]=lsum1[rt]=rsum1[rt]=sum1[rt]=len*tp;
}
void change(int rt)
{
	swap(num0[rt],num1[rt]);
	swap(lsum0[rt],lsum1[rt]);
	swap(rsum0[rt],rsum1[rt]);
	swap(sum0[rt],sum1[rt]);
}
void pushdown(int rt,int len)
{//向下传递和处理延迟标记
	if(col[rt]!=-1)
	{
		col[rt<<1]=col[rt<<1|1]=col[rt];
		xo[rt<<1]=xo[rt<<1|1]=0;
		cover(rt<<1,len-(len>>1),col[rt]);
		cover(rt<<1|1,(len>>1),col[rt]);
		col[rt]=-1;
	}
	else if(xo[rt])
	{
		if(col[rt<<1]!=-1)
		{
			col[rt<<1]^=1;
			cover(rt<<1,len-(len>>1),col[rt<<1]);
		}
		else
		{
			xo[rt<<1]^=1;
			change(rt<<1);
		}
		if(col[rt<<1|1]!=-1)
		{
			col[rt<<1|1]^=1;
			cover(rt<<1|1,(len>>1),col[rt<<1|1]);
		}
		else
		{
			xo[rt<<1|1]^=1;
			change(rt<<1|1);
		}
		xo[rt]=0;
	}
}
void build(int l,int r,int rt)
{
	col[rt]=-1,xo[rt]=0;
	if(l==r)
	{
		scanf("%d",&tmp);
		num0[rt]=lsum0[rt]=rsum0[rt]=sum0[rt]=(tmp==0);
		num1[rt]=lsum1[rt]=rsum1[rt]=sum1[rt]=(tmp==1);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt,r-l+1);
}
void update(int L,int R,int tp,int l,int r,int rt)
{
	if(l>=L&&R>=r)
	{
		if(tp<=1)
		{
			col[rt]=tp;
			xo[rt]=0;
			cover(rt,r-l+1,tp);
		}
		else
		{
			if(col[rt]!=-1)
			{
				col[rt]^=1;
				cover(rt,r-l+1,col[rt]);
			}
			else
			{
				xo[rt]^=1;
				change(rt);
			}
		}
		return;
	}
	pushdown(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m)	update(L,R,tp,lson);
	if(R>m)	update(L,R,tp,rson);
	pushup(rt,r-l+1);
}
int query1(int L,int R,int l,int r,int rt)
{
	if(l>=L&&R>=r)	return num1[rt];
	pushdown(rt,r-l+1);//不要忘了！！
	int m=(l+r)>>1,ret=0;
	if(L<=m)	ret+=query1(L,R,lson);
	if(R>m)	ret+=query1(L,R,rson);
	return ret;
}
int query2(int L,int R,int l,int r,int rt)
{
	if(l>=L&&R>=r)	return	sum1[rt];
	pushdown(rt,r-l+1);//不要忘了！！
	int m=(l+r)>>1,ret;
	if(L>m)	return	query2(L,R,rson);
	if(R<=m)	return	query2(L,R,lson);
	int ll=query2(L,R,lson);
	int rr=query2(L,R,rson);	
	ret=max(ll,rr);
	ret=max(ret,min(rsum1[rt<<1],m+1-L)+min(lsum1[rt<<1|1],R-m));
	return ret;
}
int main()
{
	int t,n,m,op,a,b;
	scanf("%d",&t);
	while(t--)
	{
		memset(col,-1,sizeof(col));
		memset(xo,0,sizeof(xo));
		scanf("%d%d",&n,&m);
		build(0,n-1,1);
		while(m--)
		{
			scanf("%d%d%d",&op,&a,&b);
			if(op<=2)
				update(a,b,op,0,n-1,1);
			else if(op==3)
				printf("%d\n",query1(a,b,0,n-1,1));
			else
				printf("%d\n",query2(a,b,0,n-1,1));
		}
	}
	return 0;
}
