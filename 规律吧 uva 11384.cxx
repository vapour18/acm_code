#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		while(n)
		{
			n/=2;
			ans++;
		}
		printf("%d\n",ans);
	}
}
