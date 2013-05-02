#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500005;
struct Node{
	int x,y,z;
	bool operator <(const Node &a)const{
		if(x == a.x) return y > a.y;
		return x < a.x;
	}
}b[maxn];
int n,c[maxn],q[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int num)
{
	while(x<=n)
	{
		c[x] = max(c[x],num);
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ret = 0;
	while(x > 0)
	{
		ret = max(ret,c[x]);
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
	int qn=0,ans=0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&b[i].x);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&b[i].y);
		q[qn++] = b[i].y;
	}
	for(int i = 0; i < n; i++) scanf("%d",&b[i].z);
	sort(b,b+n);
	sort(q,q+qn);
	memset(c,0,sizeof(c));
	for(int i = n-1; i >= 0; i--)
	{
		int pos = n- (lower_bound(q,q+qn,b[i].y)-q);
		int tmp = query(pos);
		if(query(pos-1) > b[i].z) ans++;
		update(pos,b[i].z);
	}
	printf("%d\n",ans);
	return 0;
}
