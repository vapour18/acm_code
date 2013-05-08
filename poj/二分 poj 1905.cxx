#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 1000010;
const double pi = acos(-1.0);
const double eps = 1e-8;
int main()
{
	double l,c,n,ll;
	double left,right,mid;
	while(scanf("%lf%lf%lf",&l,&n,&c)&&l>=0)
	{
		if(l == 0||n == 0||c == 0){printf("0.000\n");continue;}
		ll = (1+n*c)*l;
		//cout<<ll<<endl;
		left = 0,right = pi/2.0;
		mid = (left + right)/2.0;
		while(fabs(ll*sin(mid)-mid*l) >= eps)
		{
			if(ll*sin(mid)-mid*l > eps) left = mid + eps;
			else right = mid - eps;
			mid = (left + right)/2.0;
		}
		double r = ll/mid/2.0;
		
		printf("%.3f\n",r - r*cos(mid));
	}
	return 0;
}
