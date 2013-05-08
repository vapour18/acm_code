//用后缀数组求不同子串的个数，题目没说是大写字母，坑爹啊==
//利用所有后缀的前缀可以构成所有子串，所以每增加一个后缀，增加的子串个数为后缀长度减去和前面重复重复的个数，所以可以利用height解决
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 2005;
const int inf = 1111111111;
int sa[maxn],rank[maxn],height[maxn],wa[maxn],wb[maxn],wv[maxn],sum[maxn];
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
int solve(int n)
{
    int ret = n-sa[1];
    for(int i = 2; i <= n; i++)
        ret+=n-sa[i]-height[i];
    return ret;
}
int main()
{
   // freopen("in.txt","r",stdin);
    int cas,n,num[maxn];
    char str[maxn];
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",str);
        for(int i = 0; str[i];i++)
            num[i] = str[i];
        n = strlen(str);
        num[n] = 0;
        da(num,n+1,300);
        calheight(num,n);
        printf("%d\n",solve(n));
    }
    return 0;
}


