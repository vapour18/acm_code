//问一个节点的子树是否有能力值比它高，若有，选出忠诚度最高的。用线段树维护
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 50005
using namespace std;
struct Edge{
	int v,next;
}edge[maxn];
struct sean{
	int abi,loy,id;
	bool operator <(const sean &a) const
	{
		return abi>a.abi;//按能力从大到小排序
	}
}staff[maxn];
int mloy[maxn<<2],ri[maxn],le[maxn],head[maxn];
int en,sn;
void addedge(int u,int v)
{
	edge[en].v=v;
	edge[en].next=head[u];
	head[u]=en++;
}
void dfs(int u)
{
	le[u]=sn++;//生成时间戳，左边生成，所以线段树按左边
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		dfs(edge[i].v);
	}
	ri[u]=sn;
}
void pushup(int rt)
{
	mloy[rt]=max(mloy[rt<<1],mloy[rt<<1|1]);
}
void update(int p,int w,int l,int r,int rt)
{
	if(l==r)
	{
		mloy[rt]=w;
		return;
	}	
	int m=(l+r)>>1;
	if(m>=p)	update(p,w,lson);
	else update(p,w,rson);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L>R)	return -1;
	if(L<=l&&r<=R)		return mloy[rt];
	int m=(l+r)>>1; 
	int ret=-1;
	if(L<=m)	ret=max(ret,query(L,R,lson));
	if(R>m)	ret=max(ret,query(L,R,rson));
	return ret;
}

int main()
{
	int t,n,m,tmp,u;
	int ans[maxn];
	map<int,int> mp;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{
		memset(head,-1,sizeof(head));
		memset(mloy,-1,sizeof(mloy));
		en=sn=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&u,&staff[i].loy,&staff[i].abi);
			staff[i].id=i;
			addedge(u,i);
			mp[staff[i].loy]=i;
		}
		dfs(0);//制作时间戳，将树转化为序列
		sort(staff+1,staff+n);
		int j;
		for(int i=1;i<n;)
		{
			for(j=i;staff[i].abi==staff[j].abi&&j<n;j++)
			{
				int id=staff[j].id;
				tmp=query(le[id]+1,ri[id]-1,0,sn,1);
				if(tmp==-1)	ans[id]=-1;
				else ans[id]=mp[tmp];
				
			}
			for(j=i;staff[i].abi==staff[j].abi&&j<n;j++)
			{
				int id=staff[j].id;
				update(le[id],staff[j].loy,0,sn,1);//左边才是对应的时间戳!!!
				//update(ri[id],staff[j].loy,0,sn,1); 不能这样!右边有共用部分
			}
			i=j;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&u);
			printf("%d\n",ans[u]);
		}
	}
	return 0;
}








