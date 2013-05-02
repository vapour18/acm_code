//求最长不重叠的重复字串
//二分答案
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int maxn = 100005;
using namespace std;

int sa[maxn],rank[maxn],height[maxn];
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];
int cmp(int *r,int a,int b,int c)
{
	return r[a] == r[b] && r[a+c] == r[b+c];
}
void da(int *r,int n,int m)
{
	int i,j,p,*x = wa, *y = wb;
	memset(wd,0,sizeof(wd));
	for(i = 0; i < n; i++)	wd[x[i]=r[i]]++;
	for(i = 1; i < m; i++) wd[i]+=wd[i-1];
	for(i = n-1; i>=0; i--)	sa[--wd[x[i]]] = i;
	for(j = 1, p = 1; p < n; j*=2, m = p)
	{
		for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++)
			if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		memset(wd,0,sizeof(wd));
		for(i = 0; i < n; i++) wd[wv[i]]++;
		for(i = 1; i < m; i++) wd[i]+=wd[i-1];
		for(i = n-1; i>=0; i--)	sa[--wd[wv[i]]] = y[i];
		swap(x,y);
		for(p = 1,x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y,sa[i - 1],sa[i], j)? p-1:p++;
	}
	return;
}
void calheight(int *r,int n)
{
	int k = 0,j;
	for(int i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for(int i = 0; i < n; height[rank[i++]] = k)
	{
		for(k?k--:0,j = sa[rank[i]-1];r[i+k]==r[j+k];k++);
	}
	return;
}
int solve(int n)
{
	int ans = 0,l,r,m,low,high,flag;
	l = 4, r = n/2;
	while(l <= r)
	{
		m = (l+r)/2;
		flag = 0, low = high = sa[1];
		for(int i = 2; i < n &&!flag; i++)
		{
			if(height[i] < m) low = high = sa[i];//相当于是根据长度进行分组处理
			else
			{
				low = min(low,sa[i]);
				high = max(high,sa[i]);
				if(high - low > m){flag = 1;break;}//保证不重叠
			}
		}
		if(flag) l = m + 1,ans = m;
		else r = m - 1;
	}
	return ans < 4? 0:ans+1;
	
}
int main()
{
	int n,num[maxn];
	while(scanf("%d",&n)&&n)
	{
		for(int i = 0; i < n; i++)
			scanf("%d",&num[i]);
		if(n < 10) {printf("0\n");continue;}
		for(int i = 0 ; i < n-1; i++)
			num[i] = num[i] - num[i+1] + 100;//因为可以变调,所以满足x1-x2=y1-y2就可以了,即前后差值相同
		num[n - 1] = 0;
		da(num,n,200);
		
		calheight(num,n-1);
		printf("%d\n",solve(n));
	}
}






