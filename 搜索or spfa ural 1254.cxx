#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<cmath>
#define inf 1111111111
using namespace std;
char map[85][85];
int n,m;
double g[85][85];
bool vis[85][85];
int dx[]={0,0,-1,1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
double bfs(int sx,int sy,int tx,int ty)
{
	int x,y,xx,yy;
	queue<pair<int,int> > q;
	pair<int,int> tmp,fro;
	tmp.first=sx,tmp.second=sy;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			g[i][j]=inf;
	g[sx][sy]=0;
	q.push(tmp);
	while(!q.empty())
	{
		fro=q.front(),q.pop();
		x=fro.first,y=fro.second;
		vis[x][y]=0;
		for(int i=0;i<8;i++)
		{
			xx=x+dx[i],yy=y+dy[i];
			if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&map[xx][yy]=='.')
			{
				bool flag=0;
				if(i<4&&g[xx][yy]>g[x][y]+1)
					g[xx][yy]=g[x][y]+1,flag=1;
				else
					if(g[xx][yy]>g[x][y]+sqrt(2.0))
						g[xx][yy]=g[x][y]+sqrt(2.0),flag=1;
				tmp.first=xx,tmp.second=yy;
				if(!vis[xx][yy]&&flag)
				{
					vis[xx][yy]=1;
					q.push(tmp);
				}
			}
		}
	}
	if(g[tx][ty]!=inf)return g[tx][ty];
	return -1;
}

int main()
{
	int p,sx,sy,x,y;
	double v,sum=0,tmp;
	scanf("%d%d%d%lf",&m,&n,&p,&v);
	for(int i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	scanf("%d%d",&sy,&sx);
	for(int i=0;i<p;i++)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&y,&x);
		tmp=bfs(sx,sy,x,y);
		if(tmp!=-1)
		sum+=tmp,sx=x,sy=y;
	}
	
	printf("%.2f\n",sum/v);
	return 0;
}
