#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 205;
const int inf = 1111111111;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,n,m,a[maxn][maxn],x[maxn],y[maxn];
    scanf("%d",&cas);
    for(int ca = 1; ca <= cas; ca++)
    {
        printf("Case #%d: ",ca);
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&a[i][j]);
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                x[i] = max(x[i],a[i][j]);
        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                y[j] = max(y[j],a[i][j]);
        bool flag = 1;
        for(int i = 0; i < n&&flag; i++)
            for(int j = 0; j < m&&flag; j++)
            {
                if(a[i][j]<x[i]&&a[i][j]<y[j]) flag = 0;
            }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


