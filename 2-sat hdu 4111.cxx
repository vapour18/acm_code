#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=21005;
struct Edge{
    int v,next;
}edge[1000005];
int head[maxn],low[maxn],dfn[maxn],id[maxn];
int en,n,m,num,scc;
bool vis[maxn];
stack<int>    sta;
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void tarjan(int v)
{
	low[v]=dfn[v]=++num;
	sta.push(v);
	vis[v]=1;
	for(int i=head[v];i!=-1;i=edge[i].next)
	{
		int x=edge[i].v;
		if(!dfn[x])
		{
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else if(vis[x])
			low[v]=min(low[v],dfn[x]);
	}
	if(low[v]==dfn[v])
	{
		scc++;
		int x;
		do{
			x=sta.top(),sta.pop();
			vis[x]=0;
			id[x]=scc;
		}while(x!=v);
	}
}
void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    while(!sta.empty())    sta.pop();
    num=0,en=0,scc=1;
}
bool solve()
{
    bool flag=1;
    for(int i=1;i<=2*n;i++)
        if(!dfn[i])    tarjan(i);
    for(int i=1;i<=n;i++)
        if(id[i]==id[i+n])
        {
            flag=0;
            break;
        }
    return flag;
}
int main()
{
    int cas,bob;
    int way[5],u,v,op;
    bool flag;
    pair<int,int>    alice[maxn];
    way[1]=2,way[2]=3,way[3]=1;
    scanf("%d",&cas);
    for(int ca=1;ca<=cas;ca++)
    {
        init();
        flag=1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&bob);
            alice[i]=make_pair(bob,way[bob]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&op);
            if(op==0)
            {
                if((alice[u].first==alice[v].first&&alice[u].second==alice[v].second))
                    addedge(u,v),addedge(v,u);
                else if(alice[u].first==alice[v].second&&alice[u].second==alice[v].first)
                    addedge(u,v+n),addedge(v+n,u);
                else
                {
                    if(alice[u].first==alice[v].first)
                        addedge(u,v);
                    else if(alice[u].first==alice[v].second)
                        addedge(u,v+n);
                    else  addedge(u,u+n);
					
                    if(alice[u].second==alice[v].second)
						addedge(u+n,v+n);
					else if(alice[u].second==alice[v].first)
						addedge(u+n,v);
                    else
                        addedge(u+n,u);
                    if(alice[v].first==alice[u].first)
                        addedge(v,u);
                    else if(alice[v].first==alice[u].second)
                        addedge(v,u+n);
                    else addedge(v,v+n);
                    if(alice[v].second==alice[u].second)
                        addedge(v+n,u+n);
                    else if(alice[v].second==alice[u].first)
                        addedge(v+n,u);
                    else   addedge(v+n,v);                     
                }

            }
            else
            {
                if((alice[u].first==alice[v].first&&alice[u].second==alice[v].second))
                    addedge(u,v+n),addedge(v+n,u);
                else if(alice[u].first==alice[v].second&&alice[u].second==alice[v].first)
                    addedge(u,v),addedge(v,u+n);
                else
                {
                    if(alice[u].first==alice[v].first)
                        addedge(u,v+n), addedge(v+n,u);					
                    else if(alice[u].first==alice[v].second)
                        addedge(u,v);
					if(alice[u].second==alice[v].second)
						addedge(u+n,v);
					else if(alice[u].second==alice[v].first)
						addedge(u+n,v+n);
                    if(alice[u].second==alice[v].second)
                        addedge(v+n,u), addedge(u,v+n);
                    else if(alice[u].second==alice[v].first)
                        addedge(v+n,u+n),addedge(u+n,v+n);
					if(alice[v].second==alice[u].second)
                        addedge(v+n,u);
                    else if(alice[v].second==alice[u].first)
                        addedge(v+n,u+n);
                }
            
            }
        }
        printf("Case #%d: ",ca);
        if(solve())    printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
