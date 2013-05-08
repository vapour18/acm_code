#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=60005;
const int inf=111111111;
int dp[maxn],w[maxn],m;
void init(int n)
{
	for(m=1;m*m<=n;m++)
	{
		w[m]=m*m;
		if(w[m]==0);
	}
	if(m*m>n)	m--;
}
int main()
{
	int n; 
	scanf("%d",&n);
	init(n);
	for(int i=0;i<=n;i++)
		dp[i]=inf;
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=w[i];j<=n;j++)
		{
			if(dp[j]==0)	cout<<j<<endl;
			dp[j]=min(dp[j],dp[j-w[i]]+1);
			//cout<<j<<endl;
		}
		
	}
	printf("%d\n",dp[n]);
	return 0;
}