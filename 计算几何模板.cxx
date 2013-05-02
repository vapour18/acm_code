#include<cmath>

const double eps = 1e-8;

struct Point{       //  点的表示。
    double x, y;
};
struct Line{        //  直线的表示。
    double a, b, c;
};
struct Segment{     //  线段的表示。
    Point a, b;
};
struct Triangle{    //  三角形的表示。
    Point a, b, c;
};
struct Rectangle{   //  矩形的表示。
    Point a, b, c, d;
};
struct Polygon{     //  多边形的表示。
    int n;
    Point p[Max];
};
struct Circle{      //  圆的表示。
    double r;
    Point center;
};

//两点间的距离：
double mydis(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

/*则判断PP1与PP2的点积结果的符号，用u·v表示。通用公式：|u||v|cos<u,v>。
„ 若PP1•PP2 < 0，则P在P1P2内部
„ 若PP1•PP2 > 0，则P在P1P2外部
„ 若PP1•PP2 = 0，则P与P1或P2重合
*/
// 由两点求边的方程，运用(x2-x1)(y-y1) = (y2-y1)(x-x1)。
Line getLine(Point p1, Point p2){
    Line tmp;
    tmp.a = p1.y - p2.y;
    tmp.b = p2.x - p1.x;
    tmp.c = p1.x*p2.y - p2.x*p1.y;
    return tmp;
}

//判断两直线是否平行。
bool parallel(Line l1, Line l2){
   return abs(l1.a*l2.b - l2.a*l1.b) < eps;
}

//判断两直线是否重合。
bool lineEqual(Line l1, Line l2){
    if(!parallel(l1, l2)) return false;
    return abs(l1.a*l2.c - l2.a*l1.c) < eps && abs(l1.b*l2.c - l2.b*l1.c) < eps;
}

//求两相交直线的交点。
Point getIntersect(Line l1, Line l2){
    Point tmp;
    tmp.x = (l1.b*l2.c - l2.b*l1.c) / (l1.a*l2.b - l2.a*l1.b);
    tmp.y = (l1.c*l2.a - l2.c*l1.a) / (l1.a*l2.b - l2.a*l1.b);
    return tmp;
}

//知道直线上两点p1p2，判断直线与线段是否相交，含顶点。
/*若 P × Q > 0 , 则P在Q的顺时针方向。
　　若 P × Q < 0 , 则P在Q的逆时针方向。
　　若 P × Q = 0 , 则P与Q共线，但可能同向也可能反向。*/
double mult(Point sp, Point ep, Point op){//计算叉积,P × Q = x1*y2 - x2*y1
    return (sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y);
}

bool isIntersected(Point p1, Point p2, Point s, Point e){
    if(mult(p1, p2, s)*mult(p1, p2, e) > eps) return false;
    return true;
}

//判断两线段是否相交，含顶点。
double mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y);
}

bool isIntersected(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        mult(s2, e2, s1) * mult(s2, e2, e1) <= 0 &&
        mult(s1, e1, s2) * mult(s1, e1, e2) <= 0)
        return true;
    return false;
}

//判断两线段是否相交，不含顶点。
int dblcmp(double r){
    if(fabs(r) < eps) return 0;
    return r > 0 ? 1 : -1;
}

double dot(double x1, double y1, double x2, double y2){//叉积
    return x1*y2 - x2*y1;
}

double cross(Point a, Point b, Point c){
    return dot(b.x-a.x, b.y-a.y, c.x-a.x, ca.y-a.y);
}

bool isIntersected(Point a, Point b, Point c, Point d){
    return (dblcmp(cross(a,b,c))^dblcmp(cross(a,b,d))) == -2
      && (dblcmp(cross(c,d,a))^dblcmp(cross(c,d,b))) == -2;
}

//求两条不重复相交线段的交点。
Point getInter(Point s1, Point e1, Point s2, Point e2){
    Point tmp = s1;
    double t = ((s1.x-s2.x)*(s2.y-e2.y) - (s1.y-s2.y)*(s2.x-e2.x))
            /((s1.x-e1.x)*(s2.y-e2.y) - (s1.y-e1.y)*(s2.x-e2.x));
    tmp.x += (e1.x-s1.x) * t;
    tmp.y += (e1.y-s1.y) * t;
    return tmp;
}

//1求凸包：1.求之前判断是否够3个顶点，2.求之后判断是否为一条直线：top < 3，3.求后记得用res[]？
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
//求多边形面积，凹凸都可以，p[]必为按照逆时针方向存储。
double area(int n, Point p[]) {
    double s;
    if (n < 3) return 0;
    s = p[0].y * (p[n-1].x-p[1].x);
    for (int i = 1;i < n;i ++)
        s += p[i].y *( p[i-1].x-p[(i+1)%n].x);
    return s/2;
}
