//用double会掉精度！！！！
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 2111111111;

long long r,t;
bool check(int k) {
    double tmp = (double)(2 * r + 2 * k - 1) * k;
    if (tmp > 9e18) return false;//防止用double掉精度！！！说明铁定大于t
    return (2 * r + 2 * k - 1) * k <= t;
}
int main()
{
   freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	long long ans;
	double ret;
	int left,right;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		ans = 0;
		cin>>r>>t;
		left = 1; right = inf;
		while(left<=right)
		{
			int m = (left+right)/2;
			if(check(m)) left = m+1,ans = m;
			else right = m-1;
		}
		cout<<"Case #"<<ca<<": ";
		cout<<left-1<<"\n";
	}

    return 0;
}


