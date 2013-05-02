#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fib[20],sg[1005];
int solve(int x)
{
	int tmp;
	bool num[25]={0};
	for(int i=1;fib[i]<=x;i++)
	{
		tmp=x-fib[i];
		if(sg[tmp]==-1)
			sg[tmp]=solve(tmp);
		num[sg[tmp]]=1;
	}
	for(int i=0;;i++)
		if(num[i]==0)
			return i;
}
int main()
{
	int n,m,p;
	fib[1]=1,fib[2]=2;
	for(int i=3;i<=16;i++)
		fib[i]=fib[i-1]+fib[i-2];
	memset(sg,-1,sizeof(sg));
	while(scanf("%d%d%d",&m,&n,&p)&&(n+m+p))
	{
		int ans=solve(m)^solve(n)^solve(p);
		if(ans)	printf("Fibo\n");
		else	printf("Nacci\n");
	}
	return 0;
}
