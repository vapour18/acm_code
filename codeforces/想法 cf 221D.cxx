//题意:求[l,r]区间内出现x次的x有几个
//可以采用恰当的枚举,用离线做法
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
const int maxn = 100005;
using namespace std;
int cnt[maxn],sum[maxn],a[maxn],l[maxn],r[maxn],ans[maxn];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<=n) cnt[a[i]]++;
		}
		for(int i = 0; i < m; i++)
			scanf("%d%d",&l[i],&r[i]);
		for(int i = 1; i <= n; i++)//枚举每个可能出现i次的i
		{
			if(cnt[i] < i) continue;
			sum[0] = 0;
			for(int j = 0; j < n;j ++)//小dp,表示到j为止,i出现的次数
				sum[j+1] = sum[j] + (a[j] == i);
			for(int j = 0; j < m; j++)//在该区间内恰好出现i次
				if(sum[l[j]-1] + i ==sum[r[j]])	ans[j]++;
		}
		for(int i = 0; i < m; i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<iostream>
const int maxn = 100005;
using namespace std;
int cnt[maxn],sum[maxn],a[maxn],l[maxn],r[maxn],ans[maxn];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<=n) cnt[a[i]]++;
		}
		for(int i = 0; i < m; i++)
			scanf("%d%d",&l[i],&r[i]);
		for(int i = 1; i <= n; i++)//枚举每个可能出现i次的i
		{
			if(cnt[i] < i) continue;
			sum[0] = 0;
			for(int j = 0; j < n;j ++)//小dp,表示到j为止,i出现的次数
				sum[j+1] = sum[j] + (a[j] == i);
			for(int j = 0; j < m; j++)//在该区间内恰好出现i次
				if(sum[l[j]-1] + i ==sum[r[j]])	ans[j]++;
		}
		for(int i = 0; i < m; i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}