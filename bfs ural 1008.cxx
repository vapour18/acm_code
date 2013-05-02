#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=155;
bool g[maxn][maxn],vis[maxn][maxn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int map[205];
char op[]={'R','T','L','B'};
int n,cnt;
void bfs(int sx,int sy)
{
	int x,y,xx,yy;
	queue<pair<int,int> > q;
	pair<int,int> fro,tmp;
	q.push(make_pair(sx,sy));
	while(!q.empty())
	{
		fro=q.front();q.pop();
		x=fro.first,y=fro.second;
		vis[x][y]=1;
		for(int i=0;i<4;i++)
		{
			xx=x+dx[i],yy=y+dy[i];
			if(xx>=1&&xx<=15&&yy>=1&&yy<=15&&g[xx][yy]&&!vis[xx][yy])
			{
				q.push(make_pair(xx,yy));
				vis[xx][yy]=1;
				printf("%c",op[i]);
			}
					
		}
		cnt++;
		if(cnt<n)		printf(",\n");
		else printf(".\n");
	}
}
void solve(int sx,int sy)
{
	char str[155];
	int x,y,dir,an=0;
	queue<pair<int,int> > q;
	pair<int,int> fro,tmp,ans[155];
	ans[an++]=make_pair(sx,sy);
	q.push(make_pair(sx,sy));
	while(scanf("%s",str)!=EOF)
	{
		cnt++;	
		fro=q.front();q.pop();
		x=fro.first,y=fro.second;
		int len=strlen(str);
		for(int i=0;i<len-1;i++)
		{
			if(isalpha(str[i]))
			{
				dir=map[(int)str[i]];
				tmp.first=x+dx[dir],tmp.second=y+dy[dir];
				ans[an++]=make_pair(x+dx[dir],y+dy[dir]);
				q.push(tmp);
			}
		}

	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<an;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}
int main()
{
	int u,v;
	int x,y,tmp;
	char ch;
	x=y=5000;
	cnt=0;
	scanf("%d",&tmp);
	scanf("%c",&ch);
	map['R']=0,map['T']=1,map['L']=2,map['B']=3;
	if(ch!=' ')
	{
		n=tmp;
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			g[u][v]=1;
			if(x>u)	x=u,y=v;
			else if(x==u&&y>v)		y=v;
		}
		printf("%d %d\n",x,y);
		bfs(x,y);
	}
	else
	{
		x=tmp,scanf("%d",&y);
		solve(x,y);
	}
	return 0;
}
