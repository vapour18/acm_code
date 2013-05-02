#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 3000;
const int inf = 1111111111;
char a[maxn],b[maxn];
int main()
{
    int x,y;
    //freopen("in.txt","r",stdin);
    while(scanf("%s%s",a,b)!=EOF)
    {
        x=y=0;
        for(int i = 0; a[i];i++)
            if(a[i]=='1') x++;
        for(int i = 0; b[i];i++)
            if(b[i]=='1') y++;
        if(x%2) x++;
        if(x>=y) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

