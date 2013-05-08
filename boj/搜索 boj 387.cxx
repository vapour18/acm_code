#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
char g[15][15];
int nx[]={0,0,1,-1},ny[]={1,-1,0,0};

int check(int a,int b)
{
	int sum,tmp;
	int x = a, y = b;
	sum = 0,tmp = 0;
	while(y+1<10&&g[x][y+1]==g[a][b])
	{
		y+=1;
		tmp++;
	}
	x = a, y = b;
	while(y-1>=0&&g[x][y-1]==g[a][b])
	{
		y-=1;
		tmp++;
	}
	if(tmp>=4) sum+=tmp;

	x = a, y = b,tmp=0;
	while(x+1<10&&g[x+1][y]==g[a][b])
	{
		x+=1;
		tmp++;
	}
	x = a,y = b;
	while(x-1>=0&&g[x-1][y]==g[a][b])
	{
		x-=1;
		tmp++;
	}
	if(tmp>=4) sum+=tmp;

	x = a, y = b,tmp=0;
	while (x+1<10&&y+1<10&&g[x+1][y+1]==g[a][b])
	{
		x+=1,y+=1;
		tmp++;
	}
	x = a,y = b;
	while (x-1>=0&&y-1>=0&&g[x-1][y-1]==g[a][b])
	{
		x-=1,y-=1;
		tmp++;
	}
	if(tmp>=4) sum+=tmp;

	x = a, y = b,tmp=0;
	while (x+1<10&&y-1>=0&&g[x+1][y-1]==g[a][b])
	{
		x+=1,y-=1;
		tmp++;
	}
	x = a,y = b;
	while (x-1>=0&&y+1<10&&g[x-1][y+1]==g[a][b])
	{
		x-=1,y+=1;
		tmp++;
	}
	if(tmp>=4) sum+=tmp;
	return sum>=4? sum+1:0;
}
int bfs(int a,int b)
{
	int x,y,ret = 0,dx,dy;
	bool vis[15][15];
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	vis[a][b]=1;
	while(!q.empty())
	{
		x = q.front().first, y = q.front().second;
		q.pop();
		swap(g[x][y],g[a][b]);
		ret = max(ret,check(x,y));
		swap(g[x][y],g[a][b]);
		for(int k = 0; k < 4; k++)
		{
			dx=x+nx[k],dy = y+ny[k];
			if(dx>=0&&dx<10&&dy>=0&&dy<10&&g[dx][dy]=='.'&&!vis[dx][dy])
			{
				q.push(make_pair(dx,dy));
				vis[dx][dy]=1;
			}
			//cout<<ans<<endl;
		}
	}
	return ret;
}
int main()
{
	int ca = 1,x,y,ans;
	bool flag ;
	while(scanf("%s",g[0])!=EOF)
	{
		ans = 0;
		flag = 0;
		for(int i = 1; i < 10; i++)
			scanf("%s",g[i]);
		for(int i = 0; i < 10&&!flag; i++)
		{
			for(int j = 0; j < 10&&!flag; j++)
			{
				if(g[i][j]=='.') continue;
				else if(check(i,j)>=5)
				{
					flag = 1;
				}
			}
		}
		if(flag)
		{
			if(ca==1)
				printf("Case #%d: Waiting!\n\n",ca++);
			else
				printf("\nCase #%d: Waiting!\n",ca++);
		}
		else
		{
			for(int i = 0; i < 10; i++)
			{
				for(int j = 0; j < 10; j++)
				{
					if(g[i][j]=='.') continue;
					ans=max(ans,bfs(i,j));
				}
			}
			if(ca==1)
				printf("Case #%d: %d\n",ca++,ans);
			else
				printf("\nCase #%d: %d\n",ca++,ans);
		}
	}
	return 0;
}