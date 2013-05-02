//55棵线段树
//因为k=10,所有a%k只有55种余数结果
//对于不同的余数去更新线段树，最后把更新的总和与原数相加
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 50002
int add[maxn*3][55],num[maxn];

void update(int L,int R,int k,int c,int l,int r,int rt)
{
	if(l>=L&&R>=r)
	{	
		add[rt][k]+=c;
		return ;
	}
	int m=(l+r)>>1;
	if(L<=m)	update(L,R,k,c,lson);
	if(R>m)	update(L,R,k,c,rson);
}
int query(int p,int l,int r,int rt)
{
	int tmp,ret=0;	
	for(int k=1;k<=10;k++)
	{
		tmp=p%k;
		for(int i=1;i<k;i++)
			tmp+=i;
		ret+=add[rt][tmp];
	}	
	if(l==r)
	{	
		return ret;
	}
	
	int m=(l+r)>>1;
	if(p<=m)	ret+=query(p,lson);
	else	ret+=query(p,rson);
	return ret;
}
int main()
{
	int n,q,a,b,op,k,c,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		scanf("%d",&q);
		memset(add,0,sizeof(add));
		for(int i=1;i<=q;i++)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d%d%d",&a,&b,&k,&c);
				tmp=a%k;
				for(int i=1;i<k;i++)
					tmp+=i;
				update(a,b,tmp,c,1,n,1);
			}
			else
			{
				scanf("%d",&c);
				printf("%d\n",num[c]+query(c,1,n,1));
			}
		}
	}
	return 0;
}
