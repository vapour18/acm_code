//注意，点的编号不是从1开始！！
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
struct Edge{
    int v,next;
}edge[maxn*maxn*45];
int head[maxn],dfn[maxn],low[maxn],cut[maxn],num,en,son,s;
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void init()
{
    en = son = 0;
    num = 0;
    memset(cut,0,sizeof(cut));
    cut[s]--;
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
}
void tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++num;
    for(int i = head[u]; i!=-1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=dfn[u]) cut[u]++;
        }
        else low[u] = min(low[u],dfn[v]);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int u,v,ca=1;
    while(scanf("%d",&u)&&u)
    {
        s=u;
        init();
        while(u)
        {
            scanf("%d",&v);
            addedge(u,v);
            addedge(v,u);
            scanf("%d",&u);
        }
        tarjan(s,-1);
        bool flag = 1;
        //cout<<son<<endl;
        printf("Network #%d\n",ca++);

        for(int i = 1; i <= 1000; i++)
        {
            if(cut[i])
            {
                flag = 0;
                printf("  SPF node %d leaves %d subnets\n",i,cut[i]+1);
            }
        }
        if(flag)
            printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}


