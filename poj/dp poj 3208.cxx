//dp[i][j]��ʾ6��״̬Ϊ��λ״̬Ϊj������£���ʾ�� i λ�ж�����ȡ����tran[i][j]��ʾ״̬Ϊi��ĩβ���ӵ�����Ϊj��״̬��ת��
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
/*���� a[4][1] = 109����ʾ�ڵ� 4 λǰ�����һ�� 6 ����ȡ����
������ 6XXXX ʱһ���ж�����ȡ����
��ʱ���ֿ�������� 666XX �� 6X666��һ�� 10*10 + 9 = 109 ��ȡ����*/
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