//三分法求最值
//三分法适用与单峰函数
#include<cstdio>
#include<cmath>
#include<algorithm>
#define pi 3.141592653
#define eps 1e-8
using namespace std;
double s,h;
double fun(double r)
{
	double x;
	if(r==0)	return 0;
	x=(s-pi*r*r)/(pi*r);
	if(x-r<eps)	return 0;
	h=sqrt(x*x-r*r);
	return pi*r*r*h/3;
}
int main()
{
	double left,right,lm,rm;
	while(scanf("%lf",&s)!=EOF)
	{
		left=0,right=sqrt(s/pi/2);
		while(right-left>eps)
		{
			lm=(2*left+right)/3;
			rm=(2*right+left)/3;
			if(fun(lm)>fun(rm))	right=rm;
			else left=lm;		
		}
		printf("%.2f\n%.2f\n%.2f\n",fun(left),h,left);
	}
}




