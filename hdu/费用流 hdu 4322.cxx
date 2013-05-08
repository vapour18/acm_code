#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int maxn = 1005;
const int inf = 111111111;
struct Edge{
    int u,v,cap,next,cost;
}edge[maxn*maxn];
int c = 0,f = 0,en,head[maxn],g[maxn][maxn];
void addedge(int u,int v,int cap,int cost)
{
    edge[en].u = u, edge[en].v = v, edge[en].cap = cap,edge[en].cost = cost;
    edge[en].next = head[u];
    head[u] = en++;
    swap(u,v);
    edge[en].u = u, edge[en].v = v, edge[en].cap = 0,edge[en].cost = -cost;
    edge[en].next = head[u];
    head[u] = en++;
}
void mcmf(int s,int t)
{
    int v;
    queue<int> q;
    int dist[maxn],pre[maxn];
    c = 0,f = 0;
    while(1)
    {
        bool vis[maxn] = {0};
        memset(pre,-1,sizeof(pre));
        for(int i = 0; i <= t; i++)
            dist[i] = (i==s?0:-inf);
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();q.pop();
            vis[u] = 0;
            for(int i = head[u]; i != -1; i = edge[i].next)
            {
                v = edge[i].v;
                if(edge[i].cap&&dist[v]<dist[u]+edge[i].cost)
                {
                    dist[v] = dist[u] + edge[i].cost;
                    pre[v] = i;
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        if(dist[t] == -inf) break;
        int a = inf;
        for(int i = pre[t]; i != -1; i = pre[edge[i].u])
            if(edge[i].cap < a) a = edge[i].cap;
        f+=a;
        for(int i = pre[t]; i != -1; i = pre[edge[i].u])
        {
            edge[i].cap-=a;
            edge[i^1].cap+=a;
        }
        c+=dist[t]*a;
    }
}
int main()
{
    int cas,n,m,b[maxn],k,like,s,t,sum;
    scanf("%d",&cas);
    for(int ca = 1; ca <= cas; ca++)
    {
        memset(head,-1,sizeof(head));
        en = sum = 0;        
        scanf("%d%d%d",&n,&m,&k);
        s = 0, t = n+m+1;
        for(int i = 1; i <= m; i ++)
            scanf("%d",&b[i]),sum+=b[i];
        for(int i = 1; i <= m; i++)
        {
            if(b[i]>=k) addedge(i+n,t,b[i]/k,k);  
            if(b[i]%k>1)addedge(i+n,t,1,b[i]%k);  
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&g[i][j]);
                if(g[i][j])
                {
                    addedge(j,i+n,1,0);
                }
            }
        }
        for(int i = 1; i <= n; i++)
            addedge(s,i,1,0);
        mcmf(s,t);
        printf("Case #%d: ",ca);
        if(sum - c <= n - f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}