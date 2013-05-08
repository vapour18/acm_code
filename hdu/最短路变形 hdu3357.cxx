#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=305;
int n,m,g[maxn][maxn],ans;
void change(int u,int v)
{
    for(int i=1;i<=n;i++)
        if(g[i][u]) g[i][v]=1;
    for(int i=1;i<=n;i++)
    {
        if(g[v][i])
        {
            g[u][i]=1;
            for(int j=1;j<=n;j++)
                if(g[j][v]) g[j][i]=1;
        }
    }
    return;
}
int main()
{
    int u,v,ca=1;

    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        memset(g,0,sizeof(g));
        ans=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            if(g[v][u]||u==v)    ans++;
            else if(g[u][v]==0)    g[u][v]=1,change(u,v);
        }
        printf("%d. %d\n",ca++,ans);
    }
    return 0;
}