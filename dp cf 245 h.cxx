//���⣺������[i,j]�м������Ĵ�
/*dp[i][j]��ʾ��������Ĵ��ĸ�����
dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + f[i][j];
����f[i][j]��ʾij���Ƿ��ǻ��Ĵ����ӳ���Ϊ2ö���Ӵ����ȡ�Ҫ��ʼ��f[i][i-1] = 1����Ϊ����Ϊ2������Ƚ�����*/
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