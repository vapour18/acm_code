#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1000005;
int a[maxn];
int main()
{
	int n,x,u,ans,tmp;
	while(scanf("%d",&n)&&n)
	{
		//printf("%d\n",tmp);
		ans = 0;
		scanf("%d",&x);
		a[0] = x;
		for(int i = 1; i<n; i++)
		{
			scanf("%d",&a[i]);
			x^=a[i];
		}
		if(x == 0) printf("0\n");
		else
		{
			for(int i = 0; i<n; i++)
			{
				tmp = a[i]^x;
				//cout<<a[i]<<" "<<tmp<<endl;
				if(a[i] >=tmp) ans++;
			}
			printf("%d\n",ans);
		}
	}
}