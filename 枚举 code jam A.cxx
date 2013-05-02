#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 15;
const int inf = 1111111111;
char g[maxn][maxn];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,tp;
    scanf("%d",&cas);
    for(int ca = 1; ca <= cas; ca++)
    {
        tp = -1;
        for(int i = 0; i < 4; i++)
            scanf("%s",g[i]);
        for(int i = 0; i < 4; i++)
        {
            char tmp = g[i][0];
            if(tmp == '.') continue;
            bool flag = 1;
            for(int j = 1; j < 4; j++)
            {
                if(tmp == 'T') tmp = g[i][j];
                if(tmp == '.') {flag = 0;break;}
                if(g[i][j]!=tmp&&g[i][j]!='T')
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                tp = (tmp=='X');
                //cout<<tmp<<endl;
                break;
            }
        }
        for(int i = 0; i < 4&&tp == -1; i++)
        {
            char tmp = g[0][i];
            if(tmp == '.') continue;
            bool flag = 1;
            for(int j = 1; j < 4; j++)
            {
                if(tmp == 'T') tmp = g[j][i];
                if(tmp == '.'){flag = 0;break;}
                if(tmp != g[j][i]&&g[j][i]!='T')
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) tp = (tmp=='X');
            //cout<<"58\n";
        }
        char tmp = g[0][0];
        bool flag = 1;
        for(int i = 1; i < 4&&tp == -1; i++)
        {
            if(tmp =='T') tmp = g[i][i];
            if(tmp == '.') {flag = 0;break;}
            if(tmp != g[i][i]&&g[i][i]!='T'){flag = 0;break;}
        }
        if(flag&&tp == -1) tp = (tmp=='X');
        tmp = g[0][3];
        flag = 1;
        for(int i = 1; i < 4&&tp == -1; i++)
        {
            if(tmp == 'T') tmp = g[i][3-i];
            //cout<<tp<<endl;
            if(tmp == '.') {flag = 0;break;}
            if(tmp != g[i][3-i]&&g[i][3-i]!='T'){flag = 0;break;}
        }
        //cout<<flag<<endl;
        if(flag&&tp == -1) tp = (tmp=='X');
        printf("Case #%d: ",ca);
        if(tp == 1) printf("X won\n");
        else if(tp == 0) printf("O won\n");
        else if(tp == -1)
        {
            bool flag = 1;
            for(int i = 0; i < 4&&flag; i++)
                for(int j = 0; j < 4&&flag; j++)
                    if(g[i][j]=='.') flag = 0;
            if(flag==0) printf("Game has not completed\n");
            else printf("Draw\n");
        }
    }
    return 0;
}


