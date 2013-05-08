//凸包加暴力枚举（枚举哪几棵被砍掉）
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 25;
const double eps = 1e-8;
const double pi = acos(-1.0);
struct Point{
	double x,y;
}stack[maxn],point[maxn];
struct Fence{
	double x,y;
	int v,l;
}fence[maxn];
int top,n,m,ans ,cut,tree[maxn],tn;
bool vis[maxn];
double lefts;
double dis(Point p1,Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
}
double mult(Point sp, Point ep, Point op)
{
	return (sp.x - op.x)*(ep.y-op.y) - (ep.x - op.x)*(sp.y - op.y);
}
bool cmp(Point p1, Point p2)//极角排序的比较函数
{
	double t = mult(p1,p2,point[0]);
	if(t == 0)	return dis(p1,point[0]) < dis(p2,point[0]);
	return t>0;
}
void graham_can(int n)
{
	for(int i = 1; i < n; i++)
	{
		if(point[i].y < point[0].y||((point[i].y == point[0].y)&&point[i].x < point[0].x))
			swap(point[i],point[0]);
	}
	sort(point + 1, point + n, cmp);
	stack[1] = point[0],stack[2] = point[1];
	top = 2;
	for(int i = 2 ; i < n; i++)
	{
		while(top >= 2 && mult(point[i],stack[top - 1],stack[top]) <= eps)
			top --;
		stack[++top] = point[i];
	}
}
void dfs(int u,int dep)
{
	if(dep == n)
	{
		int cnt = 0;
		double len = 0,val=0,slen = 0;
		for(int i = 0;i < n; i++)
		{
			if(vis[i]) 
			{				
				len += fence[i].l;
				val += fence[i].v;
			}
			else
				point[cnt].x = fence[i].x,point[cnt++].y = fence[i].y;
		}
		if(cnt<=1) 
		{
			if(cnt == 0) return;
			if(val < ans || (val == ans && cnt < cut))
			{
				tn = 0;
				cut = cnt, ans = val;
				lefts = len;
				for(int i = 0;i <n; i++)
					if(vis[i]) 				
						tree[tn++] = i;
				
			}
			return;
		}
		graham_can(cnt);
		for(int i = 1; i < top; i++)
		slen+=dis(stack[i],stack[i+1]);
		slen += dis(stack[top],stack[1]);
		//cout<<slen<<endl;
		if(slen > len) return;
		if(val < ans || (val == ans && cnt < cut))
		{
			cut = cnt, ans = val;
			lefts = len - slen;
			tn = 0;
			for(int i = 0;i < n; i++)
				if(vis[i]) 				
					tree[tn++] = i;
		}		
		return;
	}
	vis[u] = 1;dfs(u+1,dep+1);
	vis[u] = 0;dfs(u+1,dep+1);

}
int main()
{
	int ca = 1;
	while(scanf("%d",&n)&&n)
	{
		ans = 1111111111;
		lefts = 0;
		for(int i = 0; i < n; i++)
			scanf("%lf%lf%d%d",&fence[i].x,&fence[i].y,&fence[i].v,&fence[i].l);
		
		dfs(0,0);
		printf("Forest %d\nCut these trees:",ca++);
		for(int i = 0; i < tn; i++) printf(" %d",tree[i]+1);
		printf("\nExtra wood: %.2f\n\n",lefts);
	}
	return 0;
}