/*题意：给出一个数组表示每个节点的权值，另一个表示节点的颜色，定义两个节点的距离：
若颜色相同，距离为无穷，否则，为两点之间的权值最小值。给出两种操作：1.翻转节点颜色。2.求所有区间的距离小于k的节点对数。k为常数
思路：将数组根据是否小于k划分成多个区间，若小于k则此数相当于区间边界，其所属区间标号加一。
记录每个区间中1和0的个数，以及整段的0，1个数，初始化的时候求出以每个点为右端点的所有距离小于k的点对之和。之后进行维护就可以
*/
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
long long ans;
int col[maxn],val[maxn],id,x[maxn],cnt[2],s[maxn][2];
int main()
{
    //freopen("in.txt","r",stdin);
    int ca;
    int n,m,k,u,v;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1; i <= n; i++)
            scanf("%d",&val[i]);
        for(int i = 1; i <= n;i++)
            scanf("%d",&col[i]);
        ans = id = 0;
        cnt[0] = cnt[1] = 0;
        memset(s,0,sizeof(s));
        for(int i = 1; i <= n; i++)
        {
            if(val[i]<k||(i>1&&val[i-1]<k)) ++id;
            x[i]=id;
            cnt[col[i]]++;
            s[id][col[i]]++;
            ans+=cnt[!col[i]]-s[id][!col[i]];
        }
        for(int i = 1; i<= m;i++)
        {
            scanf("%d",&u);
            if(u==1)
                cout<<ans<<"\n";
            else
            {
                scanf("%d",&v);
                ans-=cnt[!col[v]]-s[x[v]][!col[v]];//将以它为端点的所有去掉
                cnt[col[v]]--,cnt[!col[v]]++;
                s[x[v]][col[v]]--,s[x[v]][!col[v]]++;
                col[v]^=1;
                ans+=cnt[!col[v]]-s[x[v]][!col[v]];//除了这段以外的!col[v]的个数
            }
        }
    }
    return 0;
}


