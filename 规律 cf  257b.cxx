#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m,a,b;
	a=b=0;
	scanf("%d%d",&n,&m);
	if(n>m)	swap(n,m);
	a=n-1;
	if(m-n) a+=(m-n);
	b=n;
	printf("%d %d\n",a,b);
	return 0;
}
