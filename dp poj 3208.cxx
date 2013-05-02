//dp[i][j]表示6的状态为高位状态为j的情况下，表示低 i 位有多少种取法，tran[i][j]表示状态为i，末尾增加的数字为j的状态的转移
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int tran[4][10];
long long dp[12][4];
void init()
{
	memset(tran,0,sizeof(tran));
	for(int i = 0; i < 10; i++ )
		tran[3][i] = 3;
	tran[0][6] = 1, tran[1][6] = 2, tran[2][6] = 3;
	dp[0][3] = 1;
	for(int i = 1; i < 12; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 10; k++)
				dp[i][j]+=dp[i-1][tran[j][k]];
/*比如 a[4][1] = 109，表示在低 4 位前面出现一个 6 的总取法，
即出现 6XXXX 时一共有多少种取法，
此时两种可能情况是 666XX 和 6X666，一共 10*10 + 9 = 109 种取法。*/
}
int main()
{
	int ca,n,x,st;
	long long cnt;
	scanf("%d",&ca);
	init();
	while(ca--)
	{
		scanf("%d",&n);
		for(x = 0; x < 12; x++)
			if(dp[x][0] >= n) break;
		st = 0;
		for(;x;x--)
		{
			cnt = 0;
			for(int j = 0; j < 10; j++)
			{
				cnt += dp[x -1][tran[st][j]];
				if(cnt >= n)
				{
					printf("%d",j);
					n -= (cnt - dp[x -1][tran[st][j]]);
					st = tran[st][j];
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}