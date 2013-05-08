#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 40005;
struct Node{
	int x,y;
	bool operator <(const Node &a)const{
		return max(x,y) < max(a.x,a.y);
	}
}a[maxn],b[maxn];
int main()
{
	int n,m,x1,x2,y1,y2,t,ca;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			a[i].x = x1, a[i].y = y1;
			a[i+n].x = x2, a[i+n].y = y2;
			b[i].x = x1, b[i].y = y2;
			b[i+n].x = x2, b[i+n].y = y1;
		}
		sort(a,a+n*2);
		sort(b,b+n*2);
		scanf("%d",&m);
		long long ans,ca,cb,pa,pb,i,j;
		i = j = 0;
		ca = cb = pa = pb = 0;
		while(m--)
		{
			scanf("%d",&t);
			for(; i < 2*n&&a[i].x<=t&&a[i].y<=t;i++)
			{
				ca += (long long)a[i].x+a[i].y;
				pa += (long long)a[i].x*a[i].y;
			}
			for(; j < 2*n&&b[j].x<=t&&b[j].y<=t;j++)
			{
				cb += (long long)b[j].x+b[j].y;
				pb += (long long)b[j].x*b[j].y;
			}
			ans = (i+1)*t*t-ca*t+pa;
			ans-=(j+1)*t*t-cb*t+pb;
			cout<<ans<<endl;
		}
	}
	return 0;
}