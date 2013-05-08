/*
题意：给一个网格，给出每个点停留在原地的概率p0，向右的概率p1，向下的概率p2，每走一步要消耗2能量，求从(1,1)到(n,m)的能量的期望。
思路：和曾神一起yy，倒着做dp。dp[i][j]=(dp[i][j+1]*p1+dp[i+1][j]*p2+2)/(1-p0);
公式是这样推导的：分为两种情况。1.留在原地。根据几何概形的期望，在原地消耗的能量为1/(1-p0)。 2.走到下一个格子。本来是打算
正着推，但从两个方向进入每个格子的概率是不相关的，所以只能倒着推。从上一个格子来的能量的期望为
dp[i][j+1]*p1/(p1+p2)+dp[i+1][j]*p2(p1+p2)。所以dp[i][j]就是两部分相加
*/
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
double dp[maxn][maxn];
struct Node{
    double p0,p1,p2;
}node[maxn][maxn];
int n,m;
int main()
{
   freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m;j++)
                scanf("%lf%lf%lf",&node[i][j].p0,&node[i][j].p1,&node[i][j].p2);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m;j++) dp[i][j]=0;
        for(int i = n; i >0;i--)
            for(int j = m;j>0;j--)
            {
                if(i==n&&j==m) continue;
                if(node[i][j].p0==1) dp[i][j]=0;
                else dp[i][j] = (dp[i][j+1]*node[i][j].p1+dp[i+1][j]*node[i][j].p2+2)/(1-node[i][j].p0);
            }
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}


