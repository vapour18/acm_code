//题意：求区间[i,j]有几个回文串
/*dp[i][j]表示该区间回文串的个数，
dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + f[i][j];
其中f[i][j]表示ij串是否是回文串。从长度为2枚举子串长度。要初始化f[i][i-1] = 1是因为长度为2的情况比较特殊*/
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 5005;
int dp[maxn][maxn];
bool f[maxn][maxn];
char str[maxn];
int main()
{
	int q,x,y;
	scanf("%s",str+1);
	int len = strlen(str+1);
	for(int i = 0; i <= len ;i++)
		dp[i][i] = f[i][i] = f[i][i-1] = 1;
	for(int k = 2; k <= len; k++)
		for(int i = 1, j = k; j<=len; i++, j++)
		{
			f[i][j] = f[i+1][j-1]&&(str[i]==str[j]);
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + f[i][j];
		}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",dp[x][y]);
	}
}