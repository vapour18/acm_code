#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
int sum[maxn];
bool ok(int a)
{
    int x[15],xn=0;
    while(a)
    {
        x[xn++] = a%10;
        a/=10;
    }
    int l = 0, r = xn - 1;
    bool flag= 1;
    while(l <= r)
    {
        if(x[l]!=x[r]){flag = 0;break;}
        l++,r--;
    }
    return flag;
}
void init()
{
    int a,b=1;
    memset(sum,0,sizeof(sum));
    for(int i = 1; i < maxn; i++)
    {
        if(i!=b*b){sum[i] = sum[i-1];continue;}
        b++;
        while(!ok(b)) b++;
        if(ok(i)) sum[i] = sum[i-1]+1;
        else sum[i] = sum[i-1];
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int cas,a,b;
    scanf("%d",&cas);
    for(int ca = 1; ca <= cas; ca++)
    {
        printf("Case #%d: ",ca);
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[b] - sum[a-1]);
    }
    return 0;
}

