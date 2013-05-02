//ｃａｏ,变量名重了,数组开小了!!!
//ｃａｏ!!!!这么简单的最大流啊!!!ｃａｏ!!
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define maxn 205
const int  inf = 0x7f7f7f7f;  

using namespace std;      
int head[500],en,n,s,t;
int gap[500],h[500];
bool vis[500];
int child[500][120],num[500];
struct ED{
	int v,next,w;
}edge[500000];
inline void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
}
int dfs(int pos ,int cost)
{
	if(pos==t)
		return cost;
	int minh=n-1,lv=cost,d;
	for(int j=head[pos];j!=-1;j=edge[j].next)
	{
		int v=edge[j].v,w=edge[j].w;
		if(w>0)
		{
			if(h[v]+1==h[pos])
			{
				d=min(lv,w);
				d=dfs(v,d);
				edge[j].w-=d;
				edge[j^1].w+=d;
				lv-=d;
				if(h[s]>=n)
					return cost-lv;
				if(lv==0)
					break;
			}
			if(h[v]<minh)
				minh=h[v];
		}
	}
	if(lv==cost)
	{
		gap[h[pos]]--;
		if(gap[h[pos]]==0)
			h[s]=n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int st,int ed)
{
	
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[st]<n)
		ret+=dfs(st,inf);
	return ret;
}

int main()
{
	
	int a,b,c,x,idn,p;
	map<int,int> mp;
	while(scanf("%d",&n)!=EOF)
	{
		memset(head,-1,sizeof(head));
		idn=en=s=0;
		p=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addedge(s,i,c);			
			for(int j=0;j<a;j++)
			{
				scanf("%d",&x);
				if(mp.find(x)==mp.end())	mp[x]=++idn;
				child[i][j]=mp[x]+n;
				num[i]++;
				addedge(i,mp[x]+n,1);
			}
		}
		scanf("%d",&p);
		addedge(s,p,inf);
		for(int i=0;i<num[i];i++)
			addedge(p,child[p][i],inf);
		t=n+idn+1;
		for(int i=1;i<=idn;i++)
			addedge(i+n,t,1);	
		n=t+1;
		printf("%d\n",sap(s,t));
		mp.clear();
	}
	return 0;
}
