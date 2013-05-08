//重点是区间相对顺序不变的合并
//已经对于中间区间为2^(len-1)中方式，两头的方式唯一
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
const int mod = 1000000007;
long long c[maxn][maxn],p[maxn];

void init()
{
    p[0] = 1;
    for(int i = 1; i < maxn; i++)
        p[i] = (p[i-1]*2)%mod;
    for(int i = 0; i < maxn; i++)
        c[i][0] = 1;
    for(int i = 1; i < maxn; i++)
        for(int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
}
int main()
{
    int n,m,a[maxn],len,x;
    long long ans;
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        len = 0;
        ans = 1;
        for(int i = 1; i <= m; i++) scanf("%d",&a[i]);
        a[0] = 0, a[++m] = n+1;
        sort(a,a+m+1);
        for(int i = 1; i <= m; i++)
        {
            x = a[i] - a[i-1] - 1;
            len += x;
            ans = (ans*c[len][x])%mod;//区间合并，相当于每段相对顺序不变插入
            if(i!=1&&i!=m&&x>0)
            {
                ans = (ans*p[x-1])%mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
