#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10005;
const int inf = 1111111111;
int n,m,c[maxn];
int lowbit(int x)
{
    return x&(-x);
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
    int u,ans=-1,tmp,p;
    scanf("%d%d",&n,&m);
    //cout<<n<<m<<endl;
    for(int i = 0; i < m; i++)
    {
        memset(c,0,sizeof(c));
        tmp=0;
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&u);
            u=n-u+1;
            tmp+=query(u);
            update(u);
        }
        if(ans<tmp) ans = tmp,p = i+1;
    }
    printf("%d\n",p);
    return 0;
}


