#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
int nnext[maxn],ans[maxn];
char mstr[maxn];
void findnext()
{
    nnext[1]=0;
    for(int i = 2, j = 0; mstr[i];i++)
    {
        if(j>0&&mstr[i]!=mstr[j+1]) j = nnext[j];
        if(mstr[j+1]==mstr[i]) j++;
        nnext[i] = j;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int cas;
    char str[maxn];
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas; ca++)
    {
        printf("Case #%d:",ca);
        memset(ans,0,sizeof(ans));
        scanf("%s",str);
        ans[1]=strlen(str);
        for(int i = 0; str[i]; i++)
        {
            strcpy(mstr+1,str+i);
            findnext();
            int len = strlen(mstr+1);
            for(int j = len ; j >0; j--)
            {
                int x = j - nnext[j];
                if(j%x) continue;
                int p = j/x;
                for(int k = 1;k<=p; k++)
                {
                    if(p%k==0) ans[k]=max(ans[k],j);
                    else ans[k]=max(ans[k],x*k);
                }
            }
        }
        for(int i = 1; i <= strlen(str);i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}


