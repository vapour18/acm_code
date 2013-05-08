//题意:用完全图表示比赛情况,给出每个人的获胜场次,问最多有几个人可以打败所有获胜场次比他多的人
//用枚举人数加最大流,图分为两部分,一边为人,一边为比赛场次.如果此人一定要赢下这场比赛則连一条边,如果不是,則比赛的双方都连边
//源点连人,流量为获胜场次,比赛连汇点,流量为1,如果最大流为等于获胜的总场次則表示可行
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;
const int maxn = 105;
const int inf = 111111111;
struct Edge{
	int v,next,w;
}edge[maxn*maxn*15];

int head[maxn],en,gap[maxn],h[maxn],c[maxn][maxn];
int n,num[15];
void addedge(int u,int v,int w)
{
	edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
	swap(u,v);
	edge[en].v=v,edge[en].w=0;
	edge[en].next=head[u];
	head[u]=en++;
}
void build(int x)
{
	int g[15][15],s,t;
	s = 0, t = n+1;
	memset(g,0,sizeof(g));
	memset(head,-1,sizeof(head));
	en = 0;
	for(int i = n; i > n-x; i--)
	{
		for(int j = i+1; j<= n;j++)
			if(num[j] > num[i])
			{
				int th = c[i][j];
				addedge(i,th,1);
				g[i][j] = g[j][i] =1;
				//cout<<i<<"# "<<j<<endl;
			}
	}
	for(int i = 1; i <= n; i++ )
		for(int j = 1; j <= n; j++)
			if(!g[i][j]&&i!=j)	addedge(i,c[i][j],1);
	for(int i = 1; i <= n; i++)
		addedge(s,i,num[i]);
	for(int i = n+2;i <= c[n][n-1];i++)
		addedge(i,t,1);
}
int dfs(int s,int t,int pos,int n,int cost)
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
				d=dfs(s,t,v,n,d);
				edge[j].w-=d, edge[j^1].w+=d;
				lv-=d;
				if(h[s]>=n)	return cost-lv;
				if(lv==0)	break;
			}
			if(h[v]<minh)	minh=h[v];
		}
	}
	if(lv==cost)
	{
		gap[h[pos]]--;
		if(gap[h[pos]]==0)	h[s]=n;
		h[pos]=minh+1;
		gap[h[pos]]++;
	}
	return cost-lv;
}
int sap(int st,int ed,int n)
{
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));
	gap[0]=n;
	while(h[st]<n)
		ret+=dfs(st,ed,st,n,inf);
	return ret;
}
int solve()
{
	int i,s,t,sum = 0;
	for(int i = 1 ; i <= n; i++)	sum+=num[i];
	for(i = n; i >= 0 ;i--)
	{
		s = 0, t = n+1;
		build(i);
		if(sap(s,t,n+n*(n-1)/2+2) == sum)
			break;
	}
	return i;
}
int main()
{
	int ca,tmp;
	char str[1005];
	scanf("%d",&ca);
	getchar();
	while(ca--)
	{
		stringstream oss;
		gets(str);
		n = 0;
		oss<<str;
		while(oss>>tmp) num[++n] = tmp;
		int cnt = 1;
		for(int i =1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				c[i][j] = c[j][i] =n+1+cnt,cnt++;
		printf("%d\n",solve());
	}
	return 0;
}