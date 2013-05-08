//性质：0，2，4，6，...2*n 当n为偶数时，这些数mod (n+1)会出现n+1个不同的数字
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
int g[1005][1005];
int main()
{
   // freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n--;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = (i+j)%n+1;

        for(int i = 0; i < n; i++)
            g[i][n] = g[n][i] = g[i][i],g[i][i] = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
                printf("%d ",g[i][j]);
            printf("\n");
        }
    }
    return 0;
}
