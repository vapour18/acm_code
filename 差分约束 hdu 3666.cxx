/*题意：给你一个N*M的矩阵，求两列数a1,a2,a3...an 和 b1,b2.....bm使得对矩阵中的每个数进行下面的操作之后的值在[L,U]之间，操作为：a[i] * m[i][j] / b[j]。 
思路：差分约束。由题意可知，对于矩阵中的每个元素要满足的条件是：L <= a[i] * m[i][j] / b[j] <= U ，这样我们就可以得到下面的两个式子：L*b[j] <= a[i]  * m[i][j]  和 a[i] * m[i][j]  <= U*b[j] ，因为差分约束中dis[]前面没有系数，为了把系数取消掉，我们可以用对式子两遍取对数，就可以得到：
 log(b[j]) - log( a[i] ) <= log( m[i][j] / L) ，同理可以得到两个式子，最后用spfa判负环就可以得出答案了。*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const int maxn = 3005;
const int inf = 111111111;
struct Edge{
	int v,next;
	double w;
}edge[maxn*maxn*3];
int n,m,head[maxn],en;
double x,y;
void addedge(int u,int v,double w)
{
	edge[en].v = v;
	edge[en].w = w;
	edge[en].next = head[u];
	head[u] = en++;
}
bool spfa(int s)
{
	queue<int> q;
	bool vis[maxn] = {0};
	double dist[maxn];
	int cnt[maxn] = {0};
	for(int i = 0; i <=n; i++) dist[i] = inf;
	dist[s] = 0;
	cnt[s]++;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = head[u]; i!= -1;i = edge[i].next)
		{
			int v = edge[i].v;
			if(dist[v] > dist[u] + edge[i].w)
			{
				dist[v] = dist[u] + edge[i].w;
				if(!vis[v]) 
				{
					vis[v] = 1,cnt[v]++;
					if(cnt[v] > sqrt(n*1.0))//这里只需要判断每个元素是否进队sqrt(n)次就可以了,某个奇怪的结论
						return 0;
					q.push(v);
				}
			}
		}
	}
	return 1;
}
int main()
{
	double w;
	while(scanf("%d%d%lf%lf",&n,&m,&x,&y)!=EOF)
	{
		x = log(x), y = log(y);
		memset(head,-1,sizeof(head));
		en = 0;
		for(int i = 1; i <=n; i++)
			for(int j = 1; j <= m; j++)
			{
				scanf("%lf",&w);
				w = log(w);
				addedge(i,j+n,w-x);
				addedge(j+n,i,y-w);
			}
		n = n+m;
		if(spfa(1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}









