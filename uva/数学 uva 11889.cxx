//题意：c为a和b的最小公倍数，已知a和c，求最小的b
//lcm（a,b）= a*b/gcd(a,b);，所以如果b存在，则c/a表示b的独有部分，此部分与a不互质，应该让a除以该最大公约数，b乘上这个数，知道互质
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 100005;
long long a[maxn];
int gcd(int a,int b)
{
	int c;
	while(a%b)
	{
		c = a%b;
		a = b, b = c;
	}
	return b;
}
int main()
{
	int n,a,c,b,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&c);
		if(c%a)
		{
			cout<<"NO SOLUTION\n";
			continue;
		}
		b = c/a;
		x = gcd(b,a);
		while(x != 1)
		{
			b *= x;
			a/=x;
			x = gcd(a,b);
		}
		cout<<b<<endl;
	}
}
