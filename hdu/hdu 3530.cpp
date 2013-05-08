//题意：给出数列，求最大差值>=m <=k的最大子串的长度
/*用两个单调队列。一个维护最大值，一个维护最小值，如果差值大于k则增加较小的head，
如果差值>=m则可以更新答案*/
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
int q1[maxn],q2[maxn],a[maxn],pos;
int head1,head2,tail1,tail2,n,m,k,ans;
int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        head1=head2=tail1=tail2=1;
        ans = pos = 0;
        for(int i = 1; i <= n; i++)
        {
            while(head1<tail1&&a[q1[tail1-1]]<=a[i])
                --tail1;
            q1[tail1++]=i;
            while(head2<tail2&&a[q2[tail2-1]]>=a[i])
                --tail2;
            q2[tail2++]=i;
            //cout<<tail1<<endl;
            while(a[q1[head1]]-a[q2[head2]]>k)
            {
                if(q1[head1]>q2[head2]) pos = q2[head2++];
                else pos = q1[head1++];
            }
            if(a[q1[head1]]-a[q2[head2]]>=m)
                ans = max(ans,i-pos);
        }
        cout<<ans<<endl;
    }
    return 0;
}
