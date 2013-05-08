#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int nnext[75010],pos[75010],len;
char mst[75010],text[75010];
void findnnext()
{
	nnext[1]=0;
	for(int j=0,i=2;mst[i];i++)
	{
		while(j>0&&mst[j+1]!=mst[i])	j=nnext[j];
		if (mst[j+1]==mst[i])	j++;
		nnext[i]=j;
	}
}
bool kmp()
{
	int j=0;
	findnnext();
	for(int i=1;i<=len;i++)
	{
		while(j>0&&mst[j+1]!=text[i])	j=nnext[j];
		if(j==0&&mst[j+1]!=text[i])	return 1;
		if(mst[j+1]==text[i])
		{
			pos[i]=++j;
		}
	}
	return 0;
}
int main()
{
	scanf("%s%s",mst+1,text+1);
	len=strlen(text+1);
	if(kmp())	printf("Yes\n");
	else
	{
		printf("No\n");
		for(int i=len;i>1;i--)
		{
			if(pos[i]==1)	continue;
			if(pos[i-1]!=pos[i]-1)
				pos[i-1]=pos[i]-1;
		}
		printf("%c",text[1]);
		for(int i=2;i<=len;i++)
		{
			if(pos[i]==1)	printf(" ");
			printf("%c",text[i]);
		}
		printf("\n");
	}
	return 0;
}




