#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
char word[10005][55],str[55];
int len;
bool del(int x)
{
  int cnt=0;
	int l=strlen(word[x]);
	if(l!=len-1)	return 0;
	for(int i=0,j=0;i<len;i++,j++)
	{
		if(str[i]!=word[x][j])
		{
			cnt++;
			if(cnt>1)	return 0;
			j--;
		}
	}
	return 1;
}
bool rep(int x)
{
	int cnt=0;
	int l=strlen(word[x]);
	if(l!=len)	return 0;
	for(int i=0,j=0;i<len;i++,j++)
	{
		if(str[i]!=word[x][j])
		{
			cnt++;
			if(cnt>1)	return 0;
		}
	}
	return 1;
}
bool ins(int x)
{
	int cnt=0;
	int l=strlen(word[x]);
	if(l!=len+1)	return 0;
	for(int i=0,j=0;i<len;i++,j++)
	{
		if(str[i]!=word[x][j])
		{
			cnt++;
			if(cnt>1)	return 0;
			i--;
		}
	}
	return 1;
}
int main()
{
	map<string,bool> mp;
	int n=0;
	while(scanf("%s",word[n]))
	{
		if(word[n][0]=='#')
			break;
		mp[word[n++]]=1;
	}
	while(scanf("%s",str))
	{
		if(str[0]=='#')
			break;
		if(mp[str])
		{
			printf("%s is correct\n",str);
			continue;			
		}
		len=strlen(str);
		printf("%s:",str);
		for(int i=0;i<n;i++)
		{
			if(del(i)||rep(i)||ins(i))
				printf(" %s",word[i]);
		}
		printf("\n");
	}
}
