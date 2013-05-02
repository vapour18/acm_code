#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 135;
int n,c[maxn][maxn][maxn];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int y,int z,int v)
{
	for(int i = x; i <=n; i+=lowbit(i))
		for(int j = y ; j <= n; j+=lowbit(j))
			for(int k = z; k <= n; k+=lowbit(k))
				c[i][j][k] += v;
}
long long query(int x,int y,int z)
{
	long long sum =0;
	for(int i = x; i > 0; i-=lowbit(i))
		for(int j = y ; j > 0; j-=lowbit(j))
			for(int k = z; k > 0; k-=lowbit(k))
				sum +=c[i][j][k];
	//cout<<sum<<endl;
	return sum;
}
long long solve(int x1,int y1,int z1,int x2,int y2,int z2)
{
	long long ans;
	ans = query(x2,y2,z2)-query(x1,y1,z1)-query(x2,y2,z1)-query(x1,y2,z2)-
		query(x2,y1,z2)+query(x1,y1,z2)+query(x1,y2,z1)+query(x2,y1,z1);
	return ans;
}
int main()
{
	int m,x1,x2,y1,y2,z1,z2,k;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	while(scanf("%d",&m)&&m!=3)
	{
		
		if(m == 1)
		{
			scanf("%d%d%d%d",&x1,&y1,&z1,&k);
			update(x1+1,y1+1,z1+1,k);
		}
		else
		{
			scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
			printf("%lld\n",solve(x1,y1,z1,x2+1,y2+1,z2+1));
		}
	}
	return 0;
}