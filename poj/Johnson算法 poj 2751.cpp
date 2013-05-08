//Johnson算法
//s1>=s2,s1升序排。s1<s2按s2升序排
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10005;
const int inf = 1111111111;
struct Node{
    int x,y;
}a[maxn],b[maxn];
bool cmp1(const Node&a,const Node&b)
{
    return a.x<b.x;
}
bool cmp2(const Node&a,const Node&b)
{
    return a.y>b.y;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,an,bn,u,v;
    int t1,t2,ans;
    while(scanf("%d",&n)&&n)
    {
        an = bn = 0;
        t1=t2=0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            if(u<=v)
                a[an].x = u,a[an++].y=v;
            else b[bn].x = u,b[bn++].y=v;
        }
        sort(a,a+an,cmp1);
        sort(b,b+bn,cmp2);
        for(int i = 0; i < an; i++)
        {
            if(t1+a[i].x<=t2)
                t1+=a[i].x,t2+=a[i].y;
            else
            {
                t1+=a[i].x;
                t2=t1+a[i].y;
            }
        }
        for(int i = 0; i < bn; i++)
        {
            if(t1+b[i].x<=t2)
                t1+=b[i].x,t2+=b[i].y;
            else
            {
                t1+=b[i].x;
                t2=t1+b[i].y;
            }
        }
        printf("%d\n",t2);
    }
    return 0;
}


