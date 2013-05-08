//HDOJ 4345
//几个数的最小共倍数是这几个数的不同的质因子的乘积
//所以有几种最小共倍数只要找这些组合有质因数的个数有几种
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int num[1105],nn,m,n;
long long ans[1105][1105];
void isprim()//找素数
{
	bool p[1105];
	memset(p,1,sizeof(p));
	nn=0;
	for(int i=2;i<1105;i++)
	{
		if(p[i])
		{
			num[nn++]=i;
			for(int j=i*2;j<1105;j+=i)
				p[j]=0;
		}
	}
}
long long solve(int n,int x)//类似于完全背包
{
	if(ans[n][x]!=-1)	return ans[n][x];
	if(x>m)	return ans[n][x]=1;//边界,此时n若不为0,我们可以认为剩下的全是1
	ans[n][x]=solve(n,x+1);
	for(int i=num[x];i<=n;i=num[x]*i)//质因子num[x]出现多次
		ans[n][x]+=solve(n-i,x+1);
	return ans[n][x];
}

int main()
{
	isprim();
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			if(num[i]>n)
			{
				m=i-1;//m表示有几个质因子
				break;
			}
		}
		memset(ans,-1,sizeof(ans));
		cout<<solve(n,0)<<endl;
	}
}







