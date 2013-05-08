#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define max 5005
int sum[max*4];
void build(int l,int r,int rt)
{
    sum[rt]=0;
    if(l==r)    return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
int query(int L,int R,int l,int r,int rt)
{
     if(L<=l&&r<= R)
        return sum[rt];
     int m=(l+r)>>1;
     int ret=0;
     if(L<=m)
        ret+=query(L,R,lson);
     if(R>m)
        ret+=query(L,R,rson);
    return ret;
}
void update(int n,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]++;
        return;
    }
    int m=(l+r)>>1;
    if(n<=m)
        update(n,lson);
    else
        update(n,rson);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int main()
{
    int n,a[max],sum=0,ans;
    while(scanf("%d",&n)!=EOF)
    {
        build(0,n-1,1);
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=query(a[i],n-1,0,n-1,1);
            update(a[i],0,n-1,1);
        }
        ans=sum;
        for(int i=0;i<n-1;i++)
        {
            sum += n - a[i] - a[i] - 1;
            ans = min(ans , sum);
        }
        printf("%d\n",ans);
    }
}
