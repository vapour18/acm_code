//求出现次数大于k次的最长子串，可重叠
//利用height分块，然后二分答案
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxm = 1000010;
const int maxn = 20005;
const int inf = 1111111111;
int num[maxn],sa[maxn],sum[maxm],rank[maxn],wv[maxn],wa[maxn],wb[maxn],height[maxn];
bool cmp(int r[],int a,int b,int len)
{
    return r[a]==r[b]&&r[a+len]==r[b+len];
}
void da(int r[],int n,int m)
{
    int *x = wa,*y = wb,i,j,k,p;
    memset(sum,0,sizeof(sum));
    for(i = 0; i < n; i++) sum[x[i]=r[i]]++;
    for(i = 1; i < m; i++) sum[i]+=sum[i-1];
    for(i = n-1; i >=0; i--) sa[--sum[x[i]]] = i;
    for(i = 0,j = 1,p=1; p < n; j*=2,m=p)
    {
        for(i = n-j,p=0; i < n; i++) y[p++]=i;
        for(i = 0; i < n; i++)
            if(sa[i]>=j) y[p++] = sa[i] - j;
        memset(sum,0,sizeof(sum));
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < n; i++) sum[wv[i]]++;
        for(i = 1; i < m; i++) sum[i]+=sum[i-1];
        for(i = n-1; i >=0; i--) sa[--sum[wv[i]]] = y[i];
        swap(x,y);
        for(i=1,x[sa[0]]=0,p=1; i < n; i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
}
void calheight(int r[], int n)
{
    int j,k=0;
    for(int i = 1; i <= n; i++)
        rank[sa[i]] = i;
    for(int i = 0; i < n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int solve(int n,int k)
{
    int l=0,r = n,cnt,ans = 0;
    while(l<=r)
    {
        int m = (l+r)/2;
        cnt = 0;
        for(int i = 2; i <= n&&cnt<k; i++)
        {
            if(height[i]<m) cnt = 0;
            else cnt++;
        }
        if(cnt==k) l = m+1, ans = m;
        else r = m-1;
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&num[i]),++num[i];
        num[n] = 0;
        da(num,n+1,maxm);
        calheight(num,n);

        printf("%d\n",solve(n,k-1));
    }
    return 0;
}


