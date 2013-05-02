#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 80005;
int n,len[maxn];
double p[maxn],t[maxn];
struct Node{
	double p;
	int len;
	bool operator <(const Node &a)const{
		return a.p*a.len*(1.0-p)<p*len*(1.0-a.p);//ºËÐÄ£¡
	}
}xnode[maxn];
int main()
{
	int u;
	double v,ans,sum[maxn];
	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%lf",&u,&v);
			v/=100.0;
			xnode[i].len = u,xnode[i].p=v;
		}
		sort(xnode,xnode+n);
		sum[n-1]=0;
		for(int i = n-2;i>=0;i--)
			sum[i]=sum[i+1]+(1.0-xnode[i+1].p);
		for(int i = 0;i < n;i++)
			ans+=xnode[i].len+xnode[i].len*xnode[i].p*sum[i];
		printf("%.10lf\n",ans);
	}
	return 0;
}
