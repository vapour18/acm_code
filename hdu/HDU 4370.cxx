//0,1规划模型要想到图论
//转化为最短路
/*题的关键在于如何看出这个模型的本质。

3个条件明显在刻画未知数之间的关系，从图论的角度思考问题，容易得到下面3个结论：

1.X12+X13+...X1n=1 于是1号节点的出度为1

2..X1n+X2n+...Xn-1n=1 于是n号节点的入度为1

3.∑Xki =∑Xij 于是2~n-1号节点的入度必须等于出度

于是3个条件等价于一条从1号节点到n号节点的路径，故Xij=1表示需要经过边(i,j)，代价为Cij。Xij=0表示不经过边(i,j)。注意到Cij非负且题目要求总代价最小，因此最优答案的路径一定可以对应一条简单路径。

最终，我们直接读入边权的邻接矩阵，跑一次1到n的最短路即可，记最短路为path。

以上情况设为A

非常非常非常非常非常非常非常非常抱歉，简单路径只是充分条件，但不必要。（对造成困扰的队伍深表歉意）

漏了如下的情况B：

从1出发，走一个环（至少经过1个点，即不能是自环），回到1；从n出发，走一个环（同理），回到n。

容易验证，这是符合题目条件的。且A || B为该题要求的充要条件。

由于边权非负，于是两个环对应着两个简单环。

因此我们可以从1出发，找一个最小花费环，记代价为c1,再从n出发，找一个最小花费环，记代价为c2。（只需在最短路算法更新权值时多加一条记录即可：if(i==S) cir=min(cir,dis[u]+g[u][i])）

故最终答案为min(path,c1+c2)*/
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 305
#define inf 100000000 
using namespace std;
int map[maxn][maxn];
int n;
int dis[maxn],x;
void spfa(int s)
{
	queue<int> q;
	x=inf;
	bool vis[maxn]={0};
	for(int i=0;i<=n;i++)	dis[i]=inf;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int v=1;v<=n;v++)
		{
			if(v==s&&u!=v)	x=min(x,dis[u]+map[u][v]);//要排除自环!
			
			if(dis[v]>dis[u]+map[u][v])
			{
				dis[v]=dis[u]+map[u][v];
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	int ans,c;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
		spfa(1);
		ans=dis[n],c=x,x=inf;
		spfa(n);
		c+=x;
		ans=min(ans,c);
		printf("%d\n",ans);
	}
}
