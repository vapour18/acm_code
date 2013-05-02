//POJ 1039
//��һ�����ߣ�����ֱ��Ϊ1���۹ܣ������������롣
//����Ҫ���ֱ�߱�ȻҪ����һ���ϵ��һ���µ㣬����һ���������Զ�����Ѿ����
//�����߶κ�ֱ�ߵĽ���
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-8
using namespace std;
struct Line{
	double a,b,c;
}l1,l2;
struct Point{
	double x,y;
}up[25],down[25];
int n;
bool through;
double ans;
double mult(Point sp,Point ep ,Point op)
{
	return (sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y);
}
Line getline(Point a,Point b)
{
	Line tmp;
	tmp.a=a.y-b.y;
	tmp.b=a.x-b.x;
	tmp.c=a.x*b.y-a.y*b.x;
	return tmp;
}
bool fun(Point a,Point b,int m)
{
	int i,flag;
	for(i=0;i<n-1;i++)
	{
		if(mult(b,up[i],a)<-eps||mult(b,up[i+1],a)<-eps)
		{
			flag=1;
			break;
		}
		if(mult(b,down[i],a)>eps||mult(b,down[i+1],a)>eps)
		{
			flag=2;
			break;
		}
	}
	if(i==n-1)	return 1;
	if(i<m)	return 0;
	l1=getline(a,b);
	if(flag==1)
		l2=getline(up[i],up[i+1]);
	else
		l2=getline(down[i],down[i+1]);
	ans=max(ans,(l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b));
	return 0;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		through=0;
		ans=-1e20;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&up[i].x,&up[i].y);
			down[i]=up[i];
			down[i].y--;
		}
		if(n<=2)	through=1;
		for(int i=0;i<n&&!through;i++)
		{
			for(int j=i+1;j<n&&!through;j++)
			{
				through=fun(up[i],down[j],j);
				if(through)	break;
				through=fun(down[i],up[j],j);
				if(through)	break;
			}
		}
		if(through) printf("Through all the pipe.\n");
        else printf("%.2f\n", ans);
	}
}