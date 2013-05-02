/*第2个位置放2时有dp[n-1]种；第2个位置放3，第3个位置放2，第4个位置只能放4，有dp[n-3]种；
第2个位置放3，第3个位置放5，13578642，有1种；第2个位置放3，第3个位置不能放4。*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn = 1005;
int dp[maxn];
int main()
{
	dp[1] = 1, dp[2] = 1, dp[3] = 2;
	for(int i = 4; i <= 60; i++)
		dp[i] = dp[i-1]+dp[i-3]+1;
	int n;
	scanf("%d",&n);
	printf("%d\n",dp[n]);
	return 0;
}
