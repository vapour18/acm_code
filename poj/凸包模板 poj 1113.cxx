//题意：国王想建一个周长最短的城墙，使墙的任意一点到城堡的距离都 > L。求这面墙的周长。
//求凸包，城墙的周长为凸包周长叫上半径为l的圆的周长。因为所求城墙是一个与凸包距离为r的圆角多边形
//接下来就是模板
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1005;
const double eps = 1e-8;
const double pi = acos(-1.0);
struct Point{
	double x,y;
}stack[maxn],point[maxn];
int top,n,m;
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
void graham_can()
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

int main()
{
	double ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%lf%lf",&point[i].x,&point[i].y);
		ans = 0;
		graham_can();
		for(int i = 1; i < top; i++)
			ans+=dis(stack[i],stack[i+1]);
		ans += dis(stack[top],stack[1]);
		//cout<<ans<<endl;
		ans+=2*pi*m;
		printf("%.0f\n",ans);
	}
	return 0;
}
