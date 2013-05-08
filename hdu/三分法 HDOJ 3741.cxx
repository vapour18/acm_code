//HDOJ 3714
//三分法,所有函数的最大值构成的新的函数是单峰函数
#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-9
#define maxn 10005
using namespace std;
double a[maxn],b[maxn],c[maxn]
int n;
double fun(double x)
{
	double ans=-1e10;
	double res;
	for(int i=0;i<n;i++)
	{
		res=a[i]*x*x+b[i]*x+c[i];
		ans=max(ans,res);
	}
	return ans;
}
int main()
{
	int t;
	double l,r,lm,rm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		l=0.0,r=1000.0;
		while(r-l>eps)
		{
			lm=(l*2+r)/3;
			rm=(l+r*2)/3;
			
			if(fun(lm)<fun(rm))	r=rm;
			else l=lm;
		}
		printf("%.4f\n",fun(l));
	}
	return 0;
}







