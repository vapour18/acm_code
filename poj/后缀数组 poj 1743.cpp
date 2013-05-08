#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 20005;
int sa[maxn],height[maxn],sum[maxn],wv[maxn],wa[maxn],wb[maxn],rank[maxn];
int cmp(int r[],int a, int b, int len)
{
	return r[a]==r[b]&&r[a+len]==r[b+len];
}
void da(int r[],int n,int m)
{
	int i,j,p,*x = wa,*y = wb;
	memset(sum,0,sizeof(sum));
	for(i = 0; i < n; i++) sum[x[i]=r[i]]++;
	for(i = 1; i < m; i++) sum[i]+=sum[i-1];
	for(i = n-1; i >=0; i--) sa[--sum[x[i]]] = i;
	for(j = 1,p = 1;p < n; j*=2,m = p)
	{
		for(p=0,i=n-j;i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++)
			if(sa[i]>=j) y[p++] = sa[i]-j;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		memset(sum,0,sizeof(sum));
		for(i = 0; i < n; i++) sum[wv[i]]++;
		for(i = 1; i < m; i++) sum[i]+=sum[i-1];
		for(i = n-1; i>=0; i--) sa[--sum[wv[i]]] = y[i];
		swap(x,y);
		for(p = 1,x[sa[0]]=0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
	return;
}
void calheight(int r[],int n)
{
	int k = 0,j;
	for(int i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for(int i = 0; i < n; height[rank[i++]] = k)
		for(k?k--:0,j = sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int solve(int n)
{
	int l=4,r = n/2,ret=0,low,high;
	bool flag;
	while(l<=r)
	{
		int m = (l+r)/2;
		flag = 0, low = high = sa[1];
		for(int i = 2; i < n&&!flag; i++)
		{
			if(height[i]<m) low = high = sa[i];
			else
			{
				low = min(low,sa[i]);
				high = max(high,sa[i]);
				if(high - low > m) {flag = 1;break;}
			}
		}
		if(flag) l = m+1,ret = m;
		else r = m-1;
	}
	if(ret < 4) return 0;
	return ret+1;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,num[maxn];
	while(scanf("%d",&n)&&n)
	{
		for(int i = 0; i < n; i++)
			scanf("%d",&num[i]);
		for(int i = 0; i < n-1; i++)
			num[i] = num[i] - num[i+1] + 100;
		num[n-1] = 0;
		da(num,n,200);
		calheight(num,n-1);
		printf("%d\n",solve(n));
	}
	return 0;
}
