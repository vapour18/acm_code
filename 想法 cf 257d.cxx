#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 100005;
int main()
{
    int sum=0,n,a[maxn];
    bool ans[maxn];
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(int i = 0;i < n ; i++)
        scanf("%d",&a[i]);
    sum = a[n-1];
    ans[n-1] = 1;
    for(int i = n-2; i >= 0 ;i--)
    {
        if(sum > 0) sum-=a[i],ans[i] = 0;
        else sum += a[i],ans[i] = 1;
    }
    bool t = 0;
    //cout<<sum<<endl;
    if(sum < 0) t = 1;
    for(int i = 0; i < n; i++)
        if(t == 1)
            if(ans[i]==1) printf("-");
            else printf("+");
        else
            if(ans[i]==1) printf("+");
            else printf("-");
    printf("\n");
    return 0;
}