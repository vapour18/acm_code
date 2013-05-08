//贪心,对于所有的数字,只能全部加一或者某个乘以2,求最少经过几次,可以使得所有数字变成0
//减一的最大步数为最大的数字!
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;
int main()
{
	int n,a,m=0,ans[maxn]={0},an=0,sum=0;
	pair<int,int> num[maxn];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a>m)	m=a;
		num[i]=make_pair(a,i);
	}
	
	for(int i=1;i<=n;i++)
	{
		while(num[i].first*2<=m)//先*2
		{
			num[i].first*=2;
			if(sum<=1000) ans[an++]=i;
			sum++;
		}
	}
	sort(num+1,num+1+n);
	int p=0,x;
	for(int i=1;i<n;i++)
	{
		if(num[i].first<num[n].first)
		{
			sum++;
			x=num[i].first-p-(num[n].first-num[i].first);//考察每个点还要乘几次减几次
			sum+=x;
			if(sum<=1000)	ans[an++]-=x;
			if(sum<=1000)	ans[an++]=num[i].second;
		}
		else break;
		p=num[i].first-(num[n].first-num[i].first);
	}
	x=num[n].first-p;
	sum+=x;
	if(sum<=1000)	ans[an++]-=x;
	printf("%d\n",sum);
	if(sum<=1000)
	{
		for(int i=0;i<an;i++)
			if(ans[i]>0)
				printf("science mission to the planet %d\n",ans[i]);
			else
				while(ans[i]<0)
					printf("flying mission\n"),ans[i]++;
	}
}



