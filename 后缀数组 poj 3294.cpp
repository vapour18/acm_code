//后缀数组对于n个字符串，求出现次数超过n/2的最长公共子串，并输出。
//还是按原来的，分块，二分答案吧。
//注意的地方有：1.后缀数组要开足够大，因为字符串之间要加入分隔符 2.判断后缀穿是否出现在一个字符串中，用一个id记录就可以
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 102005;
const int inf = 1111111111;
int sa[maxn],rank[maxn],height[maxn],wa[maxn],wb[maxn],wv[maxn],sum[maxn];
int id[maxn];
vector<int> save;
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
void solve(int num[],int n,int k)
{
    int l = 1,r = 1000,m,cnt,len=0;
    bool vis[105],flag;
    save.clear();
    while(l<=r)
    {
        m = (l+r)/2;
        cnt = 0;
        flag = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 2; i < n; i++)
        {
            if(height[i]>=m)
            {
                vis[id[sa[i]]] = 1;
                vis[id[sa[i-1]]] = 1;
            }
            else
            {
                for(int j = 0; j < 100; j++) cnt+=vis[j];
                memset(vis,0,sizeof(vis));
                if(cnt<k) {cnt=0;continue;}
                len = m;
                cnt = 0;
                if(!flag) save.clear();
                flag = 1;
                save.push_back(sa[i-1]);
            }
        }
        if(flag) l = m + 1;
        else r = m-1;
    }
    if(save.size()==0) printf("?\n");
    else
    {
        for(int i = 0; i < save.size(); i++)
        {
            for(int j = save[i]; j<save[i]+len; j++)
                putchar(num[j]-1+'a');
            printf("\n");
        }
    }
    printf("\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,num[maxn],len,div;
    char str[maxn];
    while(scanf("%d",&n)&&n)
    {
        len = 0;
        div = 30;
        for(int i = 0; i < n; i++)
        {
            scanf("%s",str);
            for(int j = 0;str[j];j++)
            {
                id[len] = i;
                num[len++] = str[j]-'a'+1;
            }
            num[len++] = div++;
        }
        num[len] = 0;
        da(num,len+1,500);
        calheight(num,len);
        solve(num,len,n/2+1);
    }
    return 0;
}


