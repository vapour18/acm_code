//给出度判断是否能构成图,Havel定理
//用贪心和类似拓扑排序的逆过程,主要ｉ在于代码的实现
//排序,然后选出最大的和剩下的较小的连,度分别减一
//判断无解有两个地方，若某次选出的Vi的度比剩下的顶点还多，则无解；若某次Vj的度减成了负数，则无
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t,num[1005],n,sum;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		flag=1;
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]),sum+=num[i];
		if(sum%2)
		{
			printf("no\n");
			continue;
		}
		for(int i=n-1;i;i--)
		{
			sort(num,num+i+1);
			for(int j=i-1;j>=0&&num[i]>0&&num[j]>0;j--)
				num[i]--,num[j]--;
			if(num[i]>0)
			{
				flag=0;
				break;
			}
		}
		if(flag)	printf("yes\n");
		else printf("no\n");
	}
}
