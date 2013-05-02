#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 500005;
const int inf = 1111111111;
int n;
int c[maxn],a[maxn];
int lowbit(int x)
{
    return x&(-x);
}
bool cmp(const int a,const int b)
{
    return a>b;
}
void update(int x)
{
    while(x<=n)
    {
        c[x]+=1;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ret = 0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int num[maxn];
    while(scanf("%d",&n)&&n)
    {
        for(int i = 0; i<n;i++)
        {
            scanf("%d",&a[i]);
            num[i]=a[i];
        }
        sort(num,num+n);
        memset(c,0,sizeof(c));
        long long ans= 0;
        for(int i = 0; i < n; i++)
        {
            int u = lower_bound(num,num+n,a[i])-num+1;
            ans+=i-query(u);
            update(u);
        }
        cout<<ans<<endl;
    }
    return 0;
}


