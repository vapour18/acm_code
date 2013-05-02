//线段树，区间合并
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 1000005
using namespace std;
int rsum[maxn<<2],lsum[maxn<<2];
char str1[maxn],str2[maxn];
void pushup(int m,int len,int rt)
{
	lsum[rt]=lsum[rt<<1];
	rsum[rt]=rsum[rt<<1|1];
	if(lsum[rt]==len-(len>>1))	lsum[rt]+=lsum[rt<<1|1];
	if(rsum[rt]==len>>1)	rsum[rt]+=rsum[rt<<1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		if(str1[l]==str2[l])
			lsum[rt]=rsum[rt]=1;
		else	lsum[rt]=rsum[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(m,r-l+1,rt);
}
void update(int pos,int st,char c,int l,int r,int rt)
{
	if(l==r)
	{
		if(st==1)	str1[pos]=c;
		else	str2[pos]=c;
		lsum[rt]=rsum[rt]=(str1[pos]==str2[pos]);
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)	update(pos,st,c,lson);
	else	update(pos,st,c,rson);
	pushup(m,r-l+1,rt);
}
int query(int pos,int l,int r,int rt)
{
	if(l==r)	return pos+1;
	int m=(l+r)>>1;
	if(pos<=m)
	{
		if(rsum[rt<<1]>=m-pos)	
			return m+lsum[rt<<1|1]+1;
		else	return query(pos,lson);
	}
	else	return query(pos,rson);
}
int main()
{
	int t,q,n;
	int op,a,b;
	char c[5];
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{
		scanf("%s%s",str1,str2);
		n=max(strlen(str1),strlen(str2));//还是不知道用min为什么不行
		build(0,n-1,1);
		scanf("%d",&q);
		printf("Case %d:\n",ca);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d%s",&a,&b,c);
				update(b,a,c[0],0,n-1,1);
			}
			else
			{
				scanf("%d",&a);
				if(str1[a]!=str2[a])	printf("0\n");
				else printf("%d\n",query(a,0,n-1,1)-a);
			}
		}
	}
	return 0;
}
