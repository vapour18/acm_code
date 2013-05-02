//网络流
//拆点构图:把有人的点与源点相连,容量为1,能跳出的的点与汇点相连,容量为inf.
//有柱子的拆成两个,头连源点,尾连汇点,两点之间的容量为柱子高度
//能到达的点之间首尾连inf的边
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 25
#define inf 1e9

using namespace std;
int mpa[maxn][maxn],mpb[maxn][maxn],h[1010],gap[1010];
int n,d,total,head[1010],en,pill,s,t;
int x[]={0,0,-1,1,0,0,-1,-1,1,1,-2,2,0,0,-1,-1,-2,-2,-3,1,1,2,2,3,
          0,0,-1,-1,-2,-2,-3,-3,-4,1,1,2,2,3,3,4};
int y[]={1,-1,0,0,-2,2,-1,1,-1,1,0,0,-3,3,-2,2,-1,1,0,-2,2,-1,1,0,
          -4,4,-3,3,-2,2,-1,1,0,3,-3,2,-2,1,-1,0};
struct ED{
	int v,next,w;
}edge[100010];
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
	int tt,tmp,cnt[maxn][maxn],len;
	char str[50];
	scanf("%d",&tt);
	for(int ca=1;ca<=tt;ca++)
	{
		memset(head,-1,sizeof(head));
		memset(cnt,0,sizeof(cnt));
		memset(mpb,0,sizeof(mpb));
		memset(mpa,0,sizeof(mpa));
		scanf("%d%d",&n,&d);
		pill=total=en=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			for(int j=0;str[j];j++)
			{
				tmp=str[j]-'0';
				if(tmp)	cnt[i][j]=++pill,mpa[i][j]=tmp;
			}
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			for(int j=0;str[j];j++)
			{
				if(str[j]=='L')
					mpb[i][j]=1,total++;
			}
		}
		len=strlen(str);
		s=0,t=pill*2+1;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<len;j++)
			{
				if(mpa[i][j])
				{
					addedge(cnt[i][j],cnt[i][j]+pill,mpa[i][j]);
					if(mpb[i][j])	addedge(s,cnt[i][j],1);
					if(i<d||n-i-1<d||j<d||len-1-j<d)
						addedge(cnt[i][j]+pill,t,inf);			
				}
			}
		}
		
		int ed;
		if(d==1)	ed=3;
		else if(d==2)	ed=11;
		else if(d==3)	ed=23;
		else ed=39;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<len;j++)
			{
				if(mpa[i][j])
				{
					for(int k=0;k<=ed;k++)
					{
						int xx=i+x[k];
						int yy=j+y[k];
						if(xx>=0&&xx<n&&yy>=0&&yy<len&&mpa[xx][yy])
							addedge(cnt[i][j]+pill,cnt[xx][yy],inf);
					}
				}
			}
		}
		n=t+1;
		int x=sap(s,t);
		
		int ans=total-x;
		printf("Case #%d: ",ca);
		if(ans==0)
			printf("no lizard was left behind.\n");
		else if(ans==1)
			printf("1 lizard was left behind.\n");
		else
			printf("%d lizards were left behind.\n",ans);
	}
}





