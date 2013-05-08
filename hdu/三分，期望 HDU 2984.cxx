#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 1e6
#define eps 1e-7
using namespace std;
double b;
int a;
double fun(double p,int x)
{
	return p+(x-p)/(1+pow(x-a,b));//函数表达式经过求导应该是单峰函数
}
double solve(double p)
{
	int m,mm,l,r;
	double x,y;
	l=a,r=inf;
	while(l<r-1)//三分查找每次的最大值
	{
		
		m=(l+r)>>1;
		mm=(m+r)>>1;
		x=fun(p,m);
		y=fun(p,mm);
		if(x>y-eps) r=mm;
		else l=m;
		
	}
	return max(fun(p,r),fun(p,l));
}
int main()
{
	int n,ca=1;
	double ans;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d%lf",&a,&b);
		ans=a;
		for(int i=2;i<=n;i++)
		{
			ans=solve(ans);		//递推求出每次的最大获利
		}
		printf("Case %d: %.2f\n",ca++,ans);
	}
	return 0;
}
