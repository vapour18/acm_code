#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 110005
using namespace std;
char s1[maxn],str[maxn*2];
int p[maxn*2];
int n;
void manacher()
{
	int mx=0,id;
	for(int i=1;i<=n;i++)
	{
		if(mx>i)
			p[i]=min(p[2*id-i],mx-i);
		else	p[i]=1;
		while(str[i+p[i]]==str[i-p[i]])
			p[i]++;
		if(p[i]+i>mx)
		{
			mx=p[i]+i;
			id=i;
		}
	}
}
int main()
{
	int len;
	while(scanf("%s",s1)!=EOF)
	{
		len=strlen(s1);
		n=len*2+1;
		str[0]='+';
		for(int i=0;i<=len;i++)
		{
			str[2*i+1]='#';
			str[2*i+2]=s1[i];
		}
		manacher();
		int ans=1;
		for(int i=1;i<n;i++)
		{
			if(p[i]>ans)
				ans=p[i];
		}
		printf("%d\n",ans-1);
	}
}