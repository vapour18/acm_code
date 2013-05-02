/*
很好的想法题
题意：一个人要按顺序参加n个活动，每个活动有价值vi，在每个活动的
收益为vi*cost，cost表示他在这个活动上花费的精力，可以为0.
他在初始状态有e的精力，且每参加完一个活动可以获得r的精力（无论投入多少精力），
r都一样。并且e是他的精力上限。求最多可以获得多少收益。
做法：从每个活动要投入多少精力，且vi越大的活动投入的精力必须尽量大作为突破口。
对于第一个活动，能投入的最多精力是e，对于剩余的，能用的精力在初始条件下为r（上一次活动获得的，但可能留给下次用）
所以对于任意一个活动，如果发现它比前面的活动收益多，就增加它的时间，直到加满或者前面的收益比它大为止。
所得的值就是到目前为止，这个活动应该投入的最合理尽力。由数学归纳法可知其正确性。
*/
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
int v[maxn],cost[maxn];
int e,r,n;
long long solve()
{
    cost[1]=e;
    r = min(r,e);
    for(int i = 2; i <= n; i++)
    {
        cost[i] = r;
        for(int j = i-1; j>0;j--)
        {
            if(v[j]>=v[i]) break;
            if(cost[i]+cost[j]<=e)
            {
                cost[i]+=cost[j];
                cost[j] = 0;
            }
            else
            {
                cost[j]-=e-cost[i];
                cost[i]=e;
            }
        }
    }
    long long ret=0;
    for(int i = 1; i <= n;i++)
        ret+=(long long)v[i]*cost[i];
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas;ca++)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i = 1; i <= n; i++)
            scanf("%d",&v[i]);
        cout<<"Case #"<<ca<<": "<<solve()<<"\n";
    }
    return 0;
}

