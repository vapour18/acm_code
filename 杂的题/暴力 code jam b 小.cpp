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
int e,r,n,v[20],ans;
void dfs(int ex,int sum,int dep)
{
    if(dep==n)
    {
        ans = max(ans,sum);
        return;
    }
    for(int i = 0; i <= ex; i++)
    {
        int tmp = min(ex-i+r,e);
        //cout<<i<<" "<<dep<<endl;
        dfs(tmp,sum+i*v[dep],dep+1);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
    {
        ans = 0;
        scanf("%d%d%d",&e,&r,&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&v[i]);
        dfs(e,0,0);
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}


