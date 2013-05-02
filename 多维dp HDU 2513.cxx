//切蛋糕，使切的周长最小且每块蛋糕上有且只有一个樱桃
//对横向和纵向分别做dp
//dp[i][j][x][y]以（i，j），（x，y）为对角线的矩形需要切的长度
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 35
#define inf 9999999
using namespace std;
int dp[maxn][maxn][maxn][maxn];
bool cake[maxn][maxn];
int cnt(int x1,int y1,int x2,int y2)//暴力记录这块蛋糕上的樱桃数
{
	int ans=0;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			if(cake[i][j])	ans++;
	return ans;
}

int main()
{
	
	int n,m,c,u,v,ca=1;
	while(scanf("%d%d%d",&n,&m,&c)!=EOF)
	{
		memset(cake,0,sizeof(cake));
		memset(dp,127,sizeof(dp));
		
		for(int i=0;i<c;i++)
		{
			scanf("%d%d",&u,&v);
			cake[u][v]=1;
		}
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				for(int i=1;i+x-1<=n;i++)
					for(int j=1;j+y-1<=m;j++)
					{
						int ii=i+x-1,jj=j+y-1;
						int s=cnt(i,j,ii,jj);
						if((i==ii&&j==jj)||s==0||s==1)//面积为0或者没有或者只有一个樱桃，只要切0
							dp[i][j][x][y]=0;
						else if(i==ii||j==jj)
							dp[i][j][x][y]=s-1;
						else//按行按列切割
						{
							for(int row=i;row<ii;row++)
								if(cnt(i,j,row,jj)>=1&&cnt(row+1,j,ii,jj)>=1)
									dp[i][j][x][y]=min(dp[i][j][x][y],dp[i][j][row-i+1][y]+dp[row+1][j][ii-row][y]+y);
							for(int col=j;col<jj;col++)
								if(cnt(i,j,ii,col)>=1&&cnt(i,col+1,ii,jj)>=1)
									dp[i][j][x][y]=min(dp[i][j][x][y],dp[i][j][x][col-j+1]+dp[i][col+1][x][jj-col]+x);
						}
					}
		printf("Case %d: %d\n",ca++,dp[1][1][n][m]);
	}
	return 0;
}
