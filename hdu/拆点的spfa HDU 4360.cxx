//把一个点拆成4个点，因为每个点可能由L，O，V，E，4种情况转移而来
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
long long inf=99999999;

using namespace std;
struct EDGE{
    int v,w,next,tp;
}edge[1400*1400*2];
struct Q{
    int id,u;
}tmp;
int head[1400],en,n,m;
int num[3400][4];
long long dist[3400][4];
void addedge(int u,int v,int w,int tp)
{
    edge[en].v=v,edge[en].w=w,edge[en].tp=tp;
    edge[en].next=head[u];
    head[u]=en++;
    swap(u,v);
    edge[en].v=v,edge[en].w=w,edge[en].tp=tp;
    edge[en].next=head[u];
    head[u]=en++;
}
void spfa()
{
    queue<Q> q;
    bool vis[3400][4];
    int u,v,id,tp;
    for(int i=0;i<=n;i++)
        for(int j=0;j<4;j++)
            dist[i][j]=inf,num[i][j]=0,vis[i][j]=0;
    tmp.id=3,tmp.u=1;
    dist[1][3]=0;
    vis[1][3]=1;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        u=tmp.u;
        id=tmp.id;
        vis[u][id]=0;
        for(int e=head[u];e!=-1;e=edge[e].next)
        {
            v=edge[e].v;
            tp=edge[e].tp;
            if((id+1)%4==tp&&(dist[v][tp]>dist[u][id]+edge[e].w||dist[v][tp]==0))
            {
                dist[v][tp]=dist[u][id]+edge[e].w;
                num[v][tp]=num[u][id];
                if(tp==3)    num[v][tp]++;
                if(!vis[v][tp])
                {
                    tmp.id=tp,tmp.u=v;
                    q.push(tmp);
                    vis[v][tp]=1;
                }
            }
            else if((dist[v][tp]==dist[u][id]+edge[e].w||dist[v][tp]==0)&&(id+1)%4==tp&&num[v][tp]<=num[u][id])
            {
                num[v][tp]=num[u][id];
                if(tp==3)    num[v][tp]++;
                if(!vis[v][tp])
                {
                    tmp.id=tp,tmp.u=v;
                    q.push(tmp);
                    vis[v][tp]=1;
                }
            }
        }
    }
    return ;
}
int main()
{
    int cas;
    int u,v,w,tp;
    char str[3];
    inf*=inf;
    scanf("%d",&cas);
    for(int ca=1;ca<=cas;ca++)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%s",&u,&v,&w,str);
            if(str[0]=='L')        tp=0;
            else if(str[0]=='O')        tp=1;
            else if(str[0]=='V')        tp=2;
            else     tp=3;
            addedge(u,v,w,tp);
            
        }
        printf("Case %d: ",ca);
        spfa();
        if(num[n][3]== 0||dist[n][3]==inf)  
            printf("Binbin you disappoint Sangsang again, damn it!\n");  
        else  
            printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",dist[n][3],num[n][3]);
    }
}
