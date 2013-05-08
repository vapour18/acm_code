//坑爹啊！连queue都不行！常优啊，尼玛
//题意：给出s和t找出s到t的一条路径和该及路径上最大权值之和的最小值
//可以用spfa找出以每点为最大值点，所求s和t点的最小距离，即把两段拼起来
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

const int maxn = 1005;
const long long inf = 11111111111111;
using namespace std;
struct Edge{
    int v,w,next;
}edge[20000*5];
int head[maxn],en,val[maxn];
int n,m,qx,qu[20005],qv[20005];
long long dist[maxn],ans[maxn][maxn];
void addedge(int u,int v, int w)
{
    edge[en].v = v, edge[en].w = w;
    edge[en].next = head[u];
    head[u] = en++;
}
int q[20000*5];
void spfa(int s)
{
    bool vis[maxn] ={0};
    for(int i = 0; i <= n; i++) dist[i] = inf;
    dist[s] = 0;
    //queue<int> q;
   // q.push(s);
    int u,v,h,t;
    h = t = 1;
    q[1] = s;
    while(h<=t)
    {
        u=q[h++];
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if(val[v]>val[s])continue;
            if(dist[v]>dist[u]+edge[i].w)
            {
                dist[v]=dist[u]+edge[i].w;
                if(!vis[v]) q[++t]= v,vis[v] = 1;
            }
        }
    }
    for(int i = 1; i<=qx; i++)
        if(dist[qu[i]]<inf&&dist[qv[i]]<inf)
            ans[qu[i]][qv[i]] = min(ans[qu[i]][qv[i]],dist[qu[i]]+dist[qv[i]]+val[s]);
}
void init()
{
    en = 0;
    memset(head,-1,sizeof(head));
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            ans[i][j] = inf;
}
int main()
{
	//freopen("in.txt","r",stdin);

    int u,v,w;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        init();
        for(int i = 1; i <= n; i++)
            scanf("%d",&val[i]);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        scanf("%d",&qx);
        for(int i = 1; i <= qx; i++)
            scanf("%d%d",&qu[i],&qv[i]);
        for(int i = 1; i <= n; i++)
            spfa(i);
        for(int i = 1; i <= qx; i++)
        {
            if(ans[qu[i]][qv[i]]==inf) cout<<"-1\n";
            else cout<<ans[qu[i]][qv[i]]<<endl;
        }
        printf("\n");
    }

	return 0;
}
