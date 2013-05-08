//由必败点找必胜点
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 100005
using namespace std;
int sg[55][60005]; 
bool get_sg(int one,int sum)
{
	if(sg[one][sum]!=-1)	return sg[one][sum];
	if(sum==1)	return get_sg(one+1,0);
	sg[one][sum]=0;
	if(sum>=1&&!get_sg(one,sum-1))
		sg[one][sum]=1;
	else if(one>=1&&!get_sg(one-1,sum))
		sg[one][sum]=1;
	else if(one>=1&&sum>1&&!get_sg(one-1,sum+1))
		sg[one][sum]=1;
	else if(one>=2&&((sum==0&&!get_sg(one-2,sum+2))||(sum&&!get_sg(one-2,sum+3))))  
        sg[one][sum]=1;  
    return sg[one][sum]; 
}
int main()
{
	int cas,n,num,a,b;
	scanf("%d",&cas);
	memset(sg,-1,sizeof(sg));
	for(int ca=1;ca<=cas;ca++)
	{
		a=b=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num);
			if(num==1)	a++;
			else b+=num+1;
		}
		if(b)	b--;
		printf("Case #%d: ",ca);
		if(get_sg(a,b))	printf("Alice\n");
		else  printf("Bob\n");
	}
}
