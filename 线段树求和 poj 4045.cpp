//线段树，找出区间[s,t],长度为k的连续子区间的最大值
//可以把长度为k的一段当作线段树上的一个点，sum[i]用于记录num[i]到num[i+k-1]之和，当num[i]改变时，要更新[i-k+1,i];
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn = 250005;
const int inf = 1111111111;
int sum[maxn<<2],col[maxn<<2],num[maxn],a[maxn],n,m,k;
void pushup(int rt)
{
    sum[rt] = max(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    col[rt] = 0;
    if(l==r)
    {
        sum[rt] = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt)
{
    if(col[rt])
    {
        sum[rt<<1]+=col[rt],sum[rt<<1|1]+=col[rt];
        col[rt<<1] += col[rt];col[rt<<1|1]+=col[rt];
        col[rt] = 0;
    }
}
void update(int L,int R,int val,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        col[rt]+=val;
        sum[rt]+=val;
        return;
    }
    pushdown(rt);
    int m = (l+r)>>1;
    if(L<=m) update(L,R,val,lson);
    if(R>m) update(L,R,val,rson);
    pushup(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if(L<=l&&R>=r) return sum[rt];
    pushdown(rt);
    int m = (l+r)>>1;
    int ret = -inf;
    if(L<=m) ret = max(ret,query(L,R,lson));
    if(R>m) ret = max(ret,query(L,R,rson));
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int ca,p,x,y;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1; i <= n; i++)
            scanf("%d",&num[i]);
        memset(a,0,sizeof(a));
        for(int i = 1; i <= k; i++)
            a[1]+=num[i];
        for(int i = 2; i+k-1<=n; i++)
            a[i]=a[i-1]+num[i+k-1]-num[i-1];
        n = n-k+1;
        build(1,n,1);
        while(m--)
        {
            scanf("%d%d%d",&p,&x,&y);
            if(p==0)
            {
                int tmp = max(1,x-k+1);
                update(tmp,x,y-num[x],1,n,1);
                num[x] = y;
            }
            else if(p==1)
            {
                int tmp = max(1,x-k+1);
                update(tmp,x,num[y]-num[x],1,n,1);
                tmp = max(1,y-k+1);
                update(tmp,y,num[x]-num[y],1,n,1);
                swap(num[x],num[y]);
            }
            else if(p==2)
            {
                printf("%d\n",query(x,y-k+1,1,n,1));
            }
        }
    }
    return 0;
}


