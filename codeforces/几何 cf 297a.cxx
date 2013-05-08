//学习如何确定每条直线的位置！！
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if((a == 0&&b == 0)||(a == 1&& b == 0)) printf("0\n");
		else if((a >= b && a + b > 1)) printf("%d\n",4*(a - 1)+1);
		else if((b >= a && a + b< 0)) printf("%d\n",4*(-a - 1)+3);
		else if(a < b) printf("%d\n",4*(b - 1)+2);
		else printf("%d\n",4*-b);
	}
	return 0;
}