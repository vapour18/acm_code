#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 500005;
const int inf = 1111111111;
typedef set<int>::iterator it;
struct Node{
    int a,b;
}node[maxn];
set<int> myset;
map<int,int> mymap;
long long y,z;
int in[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int cas,n,len,one;
    scanf("%d",&cas);
    for(int ca = 1; ca<= cas; ca++)
    {
        myset.clear();
        mymap.clear();
        scanf("%d",&n);
        y = 2,z = 1;
        node[0].a = 1,node[0].b= 0;
        node[n+1].a=1,node[n+1].b=1;
        mymap[0] = 0; mymap[maxn] = n+1;
        myset.insert(0),myset.insert(maxn);
        for(int i = 1; i <= n;i++)
        {
            scanf("%d",&in[i]);
            mymap[in[i]] = i;
        }
        for(int i = 1; i <= n; i++)
        {
            it up = myset.lower_bound(in[i]);
            it low = up;
            low--;
            myset.insert(in[i]);
            len = node[mymap[*low]].a;
            one = node[mymap[*low]].b+1;
            if(len < node[mymap[*up]].a)
            {
                len = node[mymap[*up]].a;
                one = node[mymap[*up]].b;
            }
            len++;
            node[in[i]].a = len;
            node[in[i]].b = one;
            y+=len;
            z+=one;
        }
        printf("Case #%d: %lld %lld\n",ca,y,z);
    }
    return 0;
}

