//求第k大的数
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int val[20][maxn],sorted[maxn],lessmid[20][maxn],len;
struct node{
	int l,r;
}tr[maxn*4];
void build(int l,int r,int root,int d)
{
	tr[root].l=l,tr[root].r=r;
	if(l==r)	return;
	int m=(l+r)>>1;
	int lsame=m-l+1;//表示和sorted[m]相等且分到左边
	for(int i=l;i<=r;i++)
		if(val[d][i]<sorted[m])	lsame--;//得出实际能放几个相同的数
	int tl=l,tr=m+1,same=0;
	for(int i=l;i<=r;i++)
	{
		if(i==l)	lessmid[d][i]=0;
		//lessmid[d][i]表示在[l，i]内有几个数小于等于sorted[m]
		else	lessmid[d][i]=lessmid[d][i-1];
		if(val[d][i]<sorted[m])//分到左边
		{
			lessmid[d][i]++;
			val[d+1][tl++]=val[d][i];
		}
		else if(val[d][i]>sorted[m])//分到右边
		{
			val[d+1][tr++]=val[d][i];
		}
		else
		{
			if(same<lsame)//有lsame个数分到左边,考察左边是不是分满了
			{
				same++,lessmid[d][i]++;
				val[d+1][tl++]=val[d][i];
			}
			else	val[d+1][tr++]=val[d][i];
		}
	}
	build(l,m,root*2,d+1);
	build(m+1,r,root*2+1,d+1);
}
int query(int l,int r,int root,int d,int k)
{
	if(l==r)	return val[d][l];
	int s,ss;//s表示 [l,r]有多少个分到左边,ss表示[tr[root].l,l-1]有多少个分到左边
	if(l==tr[root].l)
	{
		s=lessmid[d][r];
		ss=0;
	}
	else
	{
		s=lessmid[d][r]-lessmid[d][l-1];
		ss=lessmid[d][l-1];
	}
	if(s>=k)//有多于k个被分到左边,显然去左边找第k个
		return query(tr[root].l+ss,tr[root].l+ss+s-1,root*2,d+1,k);
		//映射,缩小区间
	else
	{
		int m=(tr[root].l+tr[root].r)>>1;
		int bb=l-tr[root].l-ss;//[tr[root].l, l-1]有几个被分到右边
		int b=r-l+1-s;//[l,r]有几个被分到右边
		return query(m+bb+1,m+bb+b,2*root+1,d+1,k-s);
	}
}
int main()
{
	int n,m,l,r,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&val[1][i]);//初始化第一层
			sorted[i]=val[1][i];
		}
		sort(sorted+1,sorted+1+n);
		build(1,n,1,1);
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",query(l,r,1,1,k));
		}
	}
	return 0;
}
