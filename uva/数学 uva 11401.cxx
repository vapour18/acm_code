//给1到n做三角形的边，任取三条，问可以构成几个不同的三角形
//用递推
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1000005;
long long a[maxn];
void init()
{
	long long x,s;
	a[3] = 0;
	for(int i = 4; i < maxn ; i++)
	{
		x = i - 3;
		if(x%2==0)
			s = (2 + x)*x/4;
		else
			s = (x + 1)*(x + 1)/4;
		a[i] = a[i - 1] + s;
	}
}
int main()
{
	int n;
	init();
	while(scanf("%d",&n)&&(n>2))
		cout<<a[n]<<endl;
	return 0;
}