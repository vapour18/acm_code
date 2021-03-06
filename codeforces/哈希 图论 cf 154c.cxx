//求与其它点关系都相同的点对共几对,巧妙的利用哈希(负溢出没关系,只要和不相等就好),利用和相等就代表祥林关系一样
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005;
long long h[maxn],key[maxn],k2[maxn];
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	h[1]=1;
	for(int i=2;i<=n;i++) h[i]=h[i-1]*3;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		key[x]+=h[y];
		key[y]+=h[x];
	}
	for(int i=1;i<=n;i++) k2[i]=key[i]+h[i];
	long long ans=0;
	sort(key+1,key+1+n);//不相连的
	long long now=key[1],cnt=0;
	
	for(int i=2;i<=n;i++)
	{
		if(key[i]==now)	cnt++,ans+=cnt;
		else cnt=0,now=key[i];
	}
	
	sort(k2+1,k2+1+n);//相连的
	now=k2[1],cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(k2[i]==now)	cnt++,ans+=cnt;
		else cnt=0,now=k2[i];
	}
	printf("%lld\n",ans);
	return 0;
}

