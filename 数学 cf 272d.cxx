//问两个坐标序列,x按非降序排列,有几种组合.
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 300005;
pair<int,int> num[maxn];
int n,m;
long long ans = 1;
int main()
{
	int a,b;
	cin>>n;
	for(int i = 0; i < n; i ++)
	{
		cin>>num[i].first;
		num[i].second = i + 1;
	}
	for(int i = 0,j = n; i < n; i ++, j++)
	{
		cin>>num[j].first;
		num[j].second = i + 1;
	}
	n*=2;
	scanf("%d",&m);
	sort(num,num+n);
	a = 1, b = 0;
	for(int i = 1; i <= n; i++)
	{
		if(num[i-1].first == num[i].first)
		{
			a++;
			if(num[i-1].second == num[i].second)	b++;
		}
		else
		{
			long long x = 1 ,tmp ;
			for(int i = 1; i <= a; i++)
			{
				 tmp = i;
				while(tmp%2==0&&b)
				{
					tmp/=2;//important,非常好的想法,因为完全相同的最多只有两个,很好的剪枝
					b--;
				}
				x=(tmp*x)%m;
			}
			ans = (ans*x)%m;
			a = 1;
		}
	}
	cout<<ans<<endl;
}