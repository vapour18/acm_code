#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 111111111;
int en,head[maxn],ind[maxn],ans;
struct Edge{
	int v,next,w;
}edge[maxn*15];
void addedge(int u,int v,int w)
{
	edge[en].v = v;edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
void init()
{
	en = 0;
	ans = inf;
	memset(head,-1,sizeof(head));
	memset(ind,0,sizeof(ind));
}
int dfs(int u,int fa)
{
    int d1,d2,tmp;
    d1 = d2 = inf;
    for(int i = head[u];i!=-1; i = edge[i].next)
    {
        int v = edge[i].v,w = edge[i].w;
        if(v==fa) continue;
        tmp = dfs(v,u);
        if(tmp+w<d1) d2 = d1,d1 = tmp+w;
        else if(tmp+w<d2) d2 = tmp+w;
    }
    ans = min(ans,d1+d2);
    return d1==inf?0:d1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int u,v,w,n;
    while(scanf("%d",&n)&&n)
    {
        init();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
            ind[u]++,ind[v]++;
        }
        if(n==2) {printf("%d\n",w);continue;}
        for(int i = 1; i <= n; i++)
            if(ind[i]>1)
            {
                dfs(i,-1);
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}

