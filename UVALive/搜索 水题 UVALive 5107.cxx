#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char a[15],b[15],c[15];
int order[15],num,ans,zh[15];
bool flag[15],vis[15];
int make(char str[])
{
	int ret=0;
	int len=strlen(str);
	for(int i=0;str[i];i++)
	{
		if(zh[str[i]-'A']==0&&i==0&&len!=1)
			return -1;
		ret=ret*10+zh[str[i]-'A'];
	}
	return ret;
}
void solve()
{
	int x,y,z;
	x=make(a);
	y=make(b);
	z=make(c);
	if(x==-1||y==-1||z==-1)	return;
	if(x+y==z)	ans++;
	if(x-y==z)	ans++;
	if(x*y==z)	ans++;
	if(y!=0&&x%y==0&&x/y==z)	ans++;
}
void dfs(int dep)
{
	if(dep==num)
	{
		solve();
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(!vis[i])
		{
			zh[order[dep]]=i;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	}
	
}
void words(char str[])
{
	for(int i=0;str[i];i++)
	{
		if(!flag[str[i]-'A'])
			flag[str[i]-'A']=1;
	}
}
int main()
{
	int ca;
	scanf("%d",&ca);
	while(ca--)
	{
		memset(flag,0,sizeof(flag));
		memset(vis,0,sizeof(vis));
		scanf("%s%s%s",a,b,c);
		words(a),words(b),words(c);
		num=ans=0;
		for(int i=0;i<10;i++)
			if(flag[i])	order[num++]=i;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}