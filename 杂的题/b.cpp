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

struct node
{
    int v,u,next;
}e[10005*85];
int head[maxn],dfn[maxn],low[maxn],en,id,num,cnt;
int n,m;
bool is[200005];
map<string,int> mp;
char name[maxn][20];

void init()
{
    en = num = id = 0;
    cnt =0;
    memset(dfn,0,sizeof(head));
    memset(is,0,sizeof(is));
    memset(head,-1,sizeof(head));
    mp.clear();
}

void addedge(int u,int v)
{
    e[en].u = u,e[en].v = v;
    e[en].next = head[u];
    head[u] = en++;
}

void tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++num;
    for(int i = head[u]; i !=-1; i = e[i].next)
    {
        int v = e[i].v;
        if(v==fa) continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>dfn[u])
            {
                if(!is[i]) cnt++;
                is[i] = 1;
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int ca,u,v;
    char x[20],y[20];
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0; i < m;i++)
        {
            scanf("%s %s", x, y);
            if(mp.find(x)==mp.end()) mp[x] = ++id,memcpy(name[id], x, sizeof(x));
            if(mp.find(y)==mp.end()) mp[y] = ++id,memcpy(name[id], y, sizeof(y));
            u = mp[x],v = mp[y];
            addedge(u,v);
            addedge(v,u);
        }
        int scc=0;
        for(int i = 1; i <= n; i++)
        {
            if(!dfn[i])
                tarjan(1,-1),scc++;
        }
        if(scc>1) printf("0\n");
        else{
            printf("%d\n", cnt);
            for(int i = 0; i < en; i++)
            {
                if(is[i])
                {
                    int tmp=i/2*2;
                    u = e[tmp].u,v = e[tmp].v;
                    printf("%s %s\n", name[u], name[v]);
                }
            }
        }
    }
    return 0;
}
