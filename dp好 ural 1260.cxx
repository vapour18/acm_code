/*��2��λ�÷�2ʱ��dp[n-1]�֣���2��λ�÷�3����3��λ�÷�2����4��λ��ֻ�ܷ�4����dp[n-3]�֣�
��2��λ�÷�3����3��λ�÷�5��13578642����1�֣���2��λ�÷�3����3��λ�ò��ܷ�4��*/
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
