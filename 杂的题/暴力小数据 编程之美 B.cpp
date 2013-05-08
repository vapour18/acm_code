#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 800005;
const int inf = 1111111111;
char a[maxn],b[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    for(int ca = 1; ca <= cas; ca++)
    {
        scanf("%s%s",a,b);
        int la,lb,ans=inf;
        la = strlen(a);
        lb = strlen(b);
        for(int i = 0; i+lb<=la; i++)
        {
            int tmp = 0;
            for(int j = 0; j < lb; j++)
            {
                if(a[i+j]!=b[j]) tmp++;
            }
           // cout<<tmp<<endl;
            ans = min(ans,tmp);
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}


