#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
char g[6][6],p[2];
int tp,xxx;
bool judge(char ch)
{
    bool flag = 1;
    for(int i = 0; i < 4; i++)
        if(g[i][i]!=ch) flag=0;
    if(!flag)
    {
        flag = 1;
        for(int i = 0; i < 4; i++)
            if(g[i][3-i]!=ch) flag = 0;
    }
    for(int i = 0; i < 4&&!flag; i++)
    {
        if(g[i][0]==ch&&g[i][1]==ch&&g[i][2]==ch&&g[i][3]==ch) flag = 1;
        if(g[0][i]==ch&&g[1][i]==ch&&g[2][i]==ch&&g[3][i]==ch) flag = 1;
    }
    return flag;
}
bool dfs(int u,int cnt)
{
    if(judge(p[u^1])) return tp==(u^1);
    if(cnt==16) return tp==2;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(g[i][j]!='.') continue;
            g[i][j]=p[u];
            bool re = dfs(u^1,cnt+1);
            g[i][j]='.';
            if(re^u) return (!u);
        }
    return u;
}
int main()
{
   // freopen("in.txt","r",stdin);
    int ca,a,b;
    char op[10];
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%s",op);
        if(op[0]=='L') tp = 1;
        else if(op[0]=='W') tp = 0;
        else tp = 2;
        for(int i = 0; i < 4; i++)
            scanf("%s",g[i]);
        a=b=0;
        for(int i = 0; i < 4;i++)
            for(int j = 0; j < 4;j++)
            {
                if(g[i][j]=='x') a++;
                else if(g[i][j]=='o') b++;
            }

        if(a==b) xxx=0,p[0]='x',p[1]='o';
        else xxx=1,p[0]='o',p[1]='x';
        if(dfs(0,a+b)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


