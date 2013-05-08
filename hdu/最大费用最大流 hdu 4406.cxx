#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 105
#define maxm 1000005
const int inf=10000;
//把每一分拆为一条边！！
int n,m,k;
double p[50],d[50];
struct Edge{
    int u,v,cap,next;
    double cost;
}edge[maxn*maxn*45];
int head[maxn],en;
double ans,tot;
int s,t;
int pre[maxn];
double dis[maxn];
bool vis[maxn];
int wei[30],mark[30];
int pp;

void addedge(int u,int v,int cap,double cost)
{
    edge[en].u = u, edge[en].v = v;
    edge[en].cap = cap, edge[en].cost = cost;
    edge[en].next = head[u];
    head[u] = en++;
    swap(u,v);
    edge[en].u = u, edge[en].v = v;
    edge[en].cap = 0, edge[en].cost = -cost;
    edge[en].next = head[u];
    head[u] = en++;
}
void mcmf()
{
    int f = 0,v;
    double c = 0;
    queue<int> q;
    int pre[maxn];
    double dist[maxn];
    while(1)
    {
        bool vis[maxn] = {0};
        memset(pre,-1,sizeof(pre));
        for(int i = 0; i <= t; i++)
            dist[i] = (i==s?0:-1);
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
        if(dist[t] < 0) break;
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
     if (c<tot)
        printf("0.000000\n");
     else
         printf("%.6f\n",(c-tot+ans)/pp);
}
double f(double x,double w)
{
    return (4.0 - 3*(100 - x)*(100 - x)/1600.0)*w;
}
int main()
{
    int i,j;
    for (i=60;i<=100;i++)
        p[i-60]=4-3.0*(100-i)*(100-i)/1600;
    for (i=1;i<=40;i++)
        d[i]=p[i]-p[i-1];
    while (scanf("%d %d %d",&n,&k,&m)!=-1)
    {
          if (n==0&&m==0&&k==0) break;
          pp=0;
          for (i=1;i<=m;i++)
          {
              scanf("%d",&wei[i]);
              pp+=wei[i];
          }
          en=0;
          memset(head,-1,sizeof(head));
          for (i=1;i<=m;i++)
              scanf("%d",&mark[i]);
          s=0;
          t=n+m+1;
          for (i=1;i<=n;i++)
              addedge(s,i,k,0);
          for (i=1;i<=n;i++)
              for (j=1;j<=m;j++)
              {
                  int tmp;
                  scanf("%d",&tmp);
                  if (tmp)
                     addedge(i,j+n,k,0);
              }
          ans=0;
          tot=0;
          for (i=1;i<=m;i++)
          {
              int tmp;
              if (mark[i]<60)
              {
                 addedge(i+n,t,60-mark[i],inf);
                 tmp=61;
                 ans+=wei[i];
                 tot+=(60-mark[i])*inf;
              }
              else
              {
                  tmp=mark[i]+1;
                  ans+=p[mark[i]-60]*wei[i];
              }
              for (j=tmp;j<=100;j++)
			  {
				  double g = f(j,wei[i]) - f(j-1,wei[i]);
				 //adde(i+n,t,1,g);
                  addedge(i+n,t,1,wei[i]*d[j-60]);
			  }
          }
          mcmf();
    }
    return 0;
}