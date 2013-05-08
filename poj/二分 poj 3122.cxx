#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
const double eps = 1e-6;
const double pi = acos(-1.0);//pi的精度要够！
using namespace std;
int main()
{
	//cout<<pi<<endl;
	int ca,n,f;
	double l,r,m,a[10005];
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d%d",&n,&f);
		l = r = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf",&a[i]);
			a[i] = pi*a[i]*a[i];
			r = max(r,a[i]);
		}
		f++;
		while(r - l > eps)
		{
			int cnt = 0;
			m = (l+r)/2.0;
			for(int i = 0; i < n; i++)
				cnt+=a[i]/m;
			//cout<<cnt<<" "<<m<<endl;
			if(cnt >= f) l = m+eps;
			else r = m-eps;
		}
		printf("%.4f\n",m);
	}
	return 0;
}
