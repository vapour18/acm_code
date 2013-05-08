/*���⣺��n�����֣���˳��ѡ���������֣�ʹ�����ڵ���������������
˼·��������dp��˼�룬���ڵ�i+1�������ҳ��������ÿ�������Ӻͼ�¼�������ӵ����ֵ����dp[num[i+1]��ÿ��������]=max(dp[0~cnt]��ÿ��������)+1��
���Կ�����Ԥ�����ÿ������������
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100005;
int prim[maxn],dp[maxn],have[maxn][15],cnt��p[maxn];
//�����ֽ�ģ��
void init()
{
	for(int i=2;i<maxn;i++)
	{
		if(!prim[i])
		{
			++have[i][0];
			p[++cnt]=i;//��¼��������������
			have[i][have[i][0]]=cnt;
			for(int j=2;i*j<maxn;j++)
			{
				int tmp=i*j;
				prim[tmp]=1;
				have[tmp][++have[tmp][0]]=cnt;
			}
		}
	}
}

int main()
{
	int ca,n,a,tmp;
	scanf("%d",&ca);
	init();
	while(ca--)
	{
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			tmp=0;
			for(int j=1;j<=have[a][0];j++)
				tmp=max(tmp,dp[have[a][j]]);
			tmp+=1;
			for(int j=1;j<=have[a][0];j++)
				dp[have[a][j]]=tmp;
		}
		int ans=1;
		for(int i=1;i<=cnt;i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
