#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100010;
const long long inf = 1111111111111;
struct Edge{
    int v,next;
}edge[maxn*4];
int head[maxn],en,cnt[maxn],n;
long long len[maxn];
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void init()
{
    memset(head,-1,sizeof(head));
    en = 0;
}
void dfs1(int u, int fa)
{
    cnt[u] = 1;len[u] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        cnt[u]+=cnt[v];
        len[u]+=(len[v]+cnt[v]);
    }
}
void dfs2(int u,int fa)
{
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa) continue;
        len[v]=n-cnt[v]*2+len[u];
        dfs2(v,u);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int ca,u,v,I,R;
    scanf("%d",&ca);
    while(ca--)
    {
        init();
        scanf("%d%d%d",&n,&I,&R);
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        long long ans = inf;
        for(int i = 1; i <= n; i++)
            ans = min(ans,len[i]);
        printf("%lld\n",ans*I*I*R);
        bool flag = 0;
        for(int i = 1; i <= n; i++)
            if(len[i]==ans)
            {
                if(flag) printf(" %d",i);
                else printf("%d",i),flag = 1;
            }
        printf("\n\n");
    }
    return 0;
}


