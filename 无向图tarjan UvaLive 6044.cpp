#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
const int maxn = 10005;
const int inf = 1111111111;
struct Edge{
    int v,next;
}edge[maxn*55];
int head[maxn],dfn[maxn],low[maxn],en,num;
bool vis[maxn];
stack<int> sta;
void init()
{
    en = 0;
    num = 0;
    memset(head,-1,sizeof(head));
    memset(dfn,-1,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    while(!sta.empty()) sta.pop();
}
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void tarjan(int u,int fa)
{
    low[u] = dfn[u] = ++num;
    sta.push(u);
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa) continue;
        if(dfn[v]==-1)
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],dfn[v]);
    }
    int tmp = sta.top();
    if(dfn[u] == low[u])
    {
        int x;
        do{
           x = sta.top();sta.pop();
           if(tmp != u)vis[x] = 1;
        }while(x!=u);
    }
}
int find(int u)
{
    int ret = 0;
    queue<int> q;
    vis[u] = 1;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();q.pop();
        ret++;
        for(int i = head[u]; i != -1; i=edge[i].next)
        {
            int v = edge[i].v;
            if(!vis[v]) q.push(v),vis[v] = 1;
        }
    }
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    int ca,n,m,u,v;
    scanf("%d",&ca);
    for(int cas = 1; cas<=ca; cas++)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        for(int i = 1; i <= n; i++)
        {
            if(dfn[i]==-1) tarjan(i,-1);
        }
        int ans = 0;
        for(int i = 1;i <= n; i++)
        {
            int cnt;
            if(!vis[i])
            {
                cnt = find(i);
                ans+=cnt*(cnt-1)/2;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}


