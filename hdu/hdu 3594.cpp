//据说是仙人掌图什么的，用tarjan就可以。
/*
题意：判断一个图是否只有一个强连通分量，若有，是不是每条边都只属于一个环
思路：感觉类似于求割边，相当于保证每条边都是割边，所以用tarjan搞搞
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
const int maxn = 30005;
const int inf = 1111111111;
struct Edge{
    int v,next;
}edge[maxn*55];
int head[maxn],dfn[maxn],low[maxn],en,num,scc;
bool vis[maxn],flag;
stack<int> sta;
void init()
{
    en = num = scc = 0;
    flag = 1;
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    while(!sta.empty()) sta.pop();
}
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void tarjan(int u)
{
    if(!flag) return;
    dfn[u] = low[u] = ++num;
    int cnt = 0;
    sta.push(u);
    vis[u] = 1;
    for(int i = head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[v]<dfn[u]) cnt++;
            if(cnt==2) flag = 0;
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v])
        {
            low[u] = min(low[u],dfn[v]);
            cnt++;
            if(cnt==2) flag = 0;
            if(dfn[v]!=low[v]){flag = 0;break;};
        }
    }
    if(low[u]==dfn[u])
    {
        scc++;
        int x;
        do{
            x = sta.top();
            sta.pop();
            vis[x]=0;
        }while(x!=u);
    }
    if(scc>1) flag = 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int ca,n,u,v;
    scanf("%d",&ca);
    while(ca--)
    {
        init();
        scanf("%d",&n);
        while(scanf("%d%d",&u,&v)&&(u+v))
        {
            addedge(u,v);
        }
        tarjan(0);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
