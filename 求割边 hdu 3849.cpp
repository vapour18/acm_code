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
struct Edge{
    int v,u,next;
}edge[maxn*85];
int head[maxn],dfn[maxn],low[maxn],en,id,num,cnt;
int n,m;
bool is[maxn*85];
map<string,int> mp;
string name[maxn];
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
    edge[en].u = u,edge[en].v = v;
    edge[en].next = head[u];
    head[u] = en++;
}
void tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++num;
    for(int i = head[u]; i !=-1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>dfn[u])
            {
                if(!is[i]) cnt++;
                if(i%2) is[i^1] = 1;
                else is[i] = 1;
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int ca,u,v;
    char x[35],y[35];
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0; i < m;i++)
        {
            //cin>>x>>y;
            scanf("%s%s",x,y);
            if(mp.find(x)==mp.end()) mp[x] = ++id,name[id]=x;
            if(mp.find(y)==mp.end()) mp[y] = ++id,name[id]=y;
            u = mp[x],v = mp[y];
            addedge(u,v);
            addedge(v,u);
        }
       // cout<<"67\n";
       int scc=0;
       for(int i = 1; i <= n; i++)
       {
           if(!dfn[i])
            tarjan(1,-1),scc++;
       }
       if(scc>1) printf("0\n");
       else{
        cout<<cnt<<endl;
        for(int i = 0; i < en; i++)
        {
            if(is[i])
            {
                u = edge[i].u,v = edge[i].v;
                cout<<name[u]<<" "<<name[v]<<"\n";
            }
        }
       }
    }
    return 0;
}
