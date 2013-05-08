#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct NODE{
	int x,c;
}node[1005];
int id[400010],num;
int pr[4000],pn,pprim[20];
bool prim[4010];
void findprim()
{
	memset(prim,0,sizeof(prim));
	pn=0;
	prim[1]=prim[0]=1;
	for(int i=2;i<=4000;i++)
		if(!prim[i])
		{
			pr[pn++]=i;
			for(int j=i*2;j<=4000;j+=i)
				prim[j]=1;
		}
}
int find(int p)
{
	int ans=0;
	for(int i=0;i<pn&&pr[i]<=p;i++)
	{
		if(p%pr[i]==0)	pprim[ans++]=pr[i];
		while(p%pr[i]==0)	p/=pr[i];
	}
	if(p!=1)	pprim[ans++]=p;
	return ans;
}
int gcd(int x,int y)
{//递归写法，学着点！！
	if(y==0)	return x;
	return gcd(y,x%y);
}
long long solve(int n,int p,long long x)
{//容斥原理，奇数加，偶数减
	//ans结果总数
	long long ans=x*(x+1)/2,tmp,tt;
	int choose,cn,k;
	for(int i=1;i<1<<n;i++)
	{//状压枚举素因子，找出不互质的数
		choose=i;
		k=cn=0;
		tmp=1;
		while(choose)
		{
			if(choose&1)
			{
				cn++;
				tmp*=pprim[k];
			}
			choose>>=1;
			k++;
		}
		tt=x/tmp;
		if(cn%2)	ans-=tmp*(1+tt)*tt/2;
		else	ans+=tmp*(1+tt)*tt/2;
	}
	for(int i=0;i<num;i++)
	{//被更新的地方。。。。
		if(node[i].x>x)	continue;
		int t1=gcd(node[i].x,p);
		int t2=gcd(node[i].c,p);
		if(t1==1)	ans-=node[i].x;
		if(t2==1)	ans+=node[i].c;
	}
	return ans;
}
int main()
{
	int ca,n,m;
	int op,x,y,c,p;
	scanf("%d",&ca);
	findprim();
	while(ca--)
	{
		scanf("%d%d",&n,&m);
		memset(id,-1,sizeof(id));
		num=0;	
		for(int i=0;i<m;i++)
		{
			scanf("%d",&op);
			if(op==2)
			{
				scanf("%d%d",&x,&c);
				if(id[x]==-1)
				{
					id[x]=num++;
					node[id[x]].x=x;
					node[id[x]].c=c;
				}
				else
					node[id[x]].c=c;
			}
			else
			{
				scanf("%d%d%d",&x,&y,&p);
				int tmp=find(p);
				printf("%I64d\n",solve(tmp,p,y)-solve(tmp,p,x-1));
			}
		}
	}
	return 0;
}


