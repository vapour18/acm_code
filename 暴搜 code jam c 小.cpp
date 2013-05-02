#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
int r,n,m,q,b[6];
bool check(int dep,int x,int p)
{
    if(dep==3)
    {
       return p==x;
    }
    return check(dep+1,x,p*b[dep])||check(dep+1,x,p);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,a[105][15];
    srand(time(NULL));
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
    {
        scanf("%d%d%d%d",&r,&n,&m,&q);
        printf("Case #%d:\n",ca);
        for(int i = 1; i <=r; i++)
            for(int j = 1;j <= q; j++)
                scanf("%d",&a[i][j]);
        bool flag = 1;
        for(int x = 1; x<=r;x++)
        {
                flag = 1;
                for(int i = 2; i <= m&&flag;i++)
                    for(int j = 2; j <=m&&flag;j++)
                        for(int k = 2; k <=m&&flag;k++)
                        {
                            int u;
                            for(u= 1;u<=q;u++)
                            {
                                b[0]=i,b[1]=j,b[2]=k;
                                if(!check(0,a[x][u],1))
                                {
                                    break;
                                }
                            }
                            if(u>q)
                            {
                                printf("%d%d%d\n",i,j,k);
                                flag= 0;
                            }
                        }
        }
    }

    return 0;

}


