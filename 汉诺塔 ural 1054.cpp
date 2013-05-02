#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int disk[35],ans;
bool flag;
//递归求到达某种状态时经过的步数，再递归子状态
void solve(int n,int from,int temp,int to)
{
	if(!flag)	return;
	if(n==0)	return;
	if(disk[n]==from)
		solve(n-1,from,to,temp);
	else if(disk[n]==to)
	{
		ans+=(1<<(n-1));
		solve(n-1,temp,from,to);
	}
	else//当前最大的盘子在中间柱子上必然无解！
	{
		flag=0;
		ans=-1;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	ans=0;
	flag=1;
	for(int i=1;i<=n;i++)	scanf("%d",&disk[i]);
	solve(n,1,3,2);
	printf("%d\n",ans);
	return 0;
}