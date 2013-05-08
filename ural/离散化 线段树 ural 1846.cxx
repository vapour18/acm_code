#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100005;
int tree[maxn<<2],x[maxn<<2],pos[maxn],cnt[maxn];
bool tp[maxn];
int gcd(int a,int b)
{
	if(a==0||b==0) return a+b;
	return gcd(b,a%b);
}
void update(int p,int v,int l,int r,int rt)
{
	if(l == r)
	{
		tree[rt] = v;
		return;
	}
	int m = (l+r)>>1;
	if(p <= m) update(p,v,lson);
	else update(p,v,rson);
	tree[rt] = gcd(tree[rt<<1],tree[rt<<1|1]);
	//cout<<tree[rt]<<"*******"<<endl;
}
int main()
{
	int q,xn=0;
	char op[5];
	scanf("%d",&q);
	for(int i = 0; i < q; i++)
	{
		scanf("%s%d",op,&pos[i]);
		tp[i] = (op[0]=='+');
		x[xn++] = pos[i];
	}
	int s =0;
	sort(x,x+xn);
	xn = unique(x,x+xn) - x;
	memset(cnt,0,sizeof(cnt));
	for(int i = 0; i < q; i++)
	{
		int u = lower_bound(x,x+xn,pos[i]) - x;
		if(tp[i])
		{
			s++;
			cnt[u]++;
			if(cnt[u] == 1) update(u+1,x[u],1,xn,1);
		}
		else
		{
			s--;
			cnt[u]--;
			if(cnt[u] == 0) update(u+1,0,1,xn,1);
		}
		if(s == 0) printf("1\n");
		else printf("%d\n",tree[1]);
	}
	
	return 0;
}