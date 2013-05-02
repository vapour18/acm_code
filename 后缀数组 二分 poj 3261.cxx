//求重复k次的最长子串
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
const int maxn = 1000010;

int sa[maxn],rank[maxn],height[maxn];
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];
int cmp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int *r,int n,int m)
{
	int i , j, p,*x = wa,*y = wb;
	memset(wd,0,sizeof(wd));
	for(i = 0; i < n; i++) 	wd[x[i] = r[i]]++;
	for(i = 1; i < m; i++) 	wd[i]+=wd[i-1];
	for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
	for(j = 1,p = 1; p < n; j*=2, m = p)
	{
		for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++)
			if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		memset(wd,0,sizeof(wd));
		for(i = 0; i < n; i++) 	wd[wv[i]]++;
		for(i = 1; i < m; i++) 	wd[i]+=wd[i-1];
		for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
		swap(x,y);
		for(p = 1,x[sa[0]] = 0,i = 1; i < n; i++)
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j)?p-1:p++;
	}
	return;
}
void calheight(int *r,int n)
{
	int k = 0,j;
	for(int i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for(int i = 0; i < n; height[rank[i++]] = k)
		for(k?k--:0,j = sa[rank[i]-1];r[i+k] == r[j+k];k++);
	return;
}

int solve(int n,int t)
{
	int l,r,m,flag,ans = 0,cnt;
	l = 1, r = n;
	while(l <= r)
	{
		m = (l + r)/2;
		//cout<<m<<endl;
		flag = 0, cnt = 0;
		for(int i = 2; i <= n&&!flag; i++)
		{
			if(height[i] >= m) cnt++;
			else cnt = 0;
			//cout<<"cnt "<<cnt<<endl;
			if(cnt >= t){flag = 1;break;}
		}
		if(flag) l = m+1,ans = m;
		else r = m-1;
	}
	return ans;
}
int main()
{
	int n,k,num[maxn];
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d",&num[i]);
		num[i]++;
	}
	num[n] = 0;//在末尾添一个,保证rank从1开始
	da(num,n+1,maxn);
	calheight(num,n);
	printf("%d\n",solve(n,k-1));
	return 0;
}






