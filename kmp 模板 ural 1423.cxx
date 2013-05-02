#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
char mstr[250005*2],text[250005*2];
int nnext[250005],n,len;
void findnext()
{
	nnext[1]=0;
	for(int j=0,i=2;mstr[i];i++)
	{
		if(j>0&&mstr[i]!=mstr[j+1])	j=nnext[j];
		if(mstr[j+1]==mstr[i])	j++;
		nnext[i]=j;
	}
}
int kmp()
{
	int j=0;
	findnext();
	for(int i=1;i<=n;i++)
	{
		while(j>0&&mstr[j+1]!=text[i])	j=nnext[j];
		if(mstr[j+1]==text[i])	j++;
		if(j==len)	return n/2-(i-len);
	}
	return -1;
}

int main()
{
	scanf("%d%s%s",&n,text+1,mstr+1);
	len=strlen(mstr+1);
	for(int i=n+1,j=1;j<=n;i++,j++)
		text[i]=text[j];
	n*=2;

	text[n+1]='\0';
	//printf("%s\n",text+1);
	int ans=kmp();
	if(ans==-1)	printf("-1\n");
	else if(ans==n/2)	printf("0\n");
	else printf("%d\n",ans);
	return 0;
}
