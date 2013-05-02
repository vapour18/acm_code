//用n^2枚举加tire树也可以统计子串的个数！
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 2005;
int trie[maxn*maxn][26],cnt;
int main()
{
	int m;
	char str[maxn],alp[29];
	scanf("%s%s%d",str,alp,&m);
	cnt = 0;
	memset(trie,-1,sizeof(trie));
	for(int i = 0; i <strlen(str);i++)
	{
		int x = 0,pos = 0;
		for(int j = i; j< strlen(str);j++)
		{
			if(alp[str[j]-'a']=='0') x++;
			if(x>m) break;
			if(trie[pos][str[j]-'a'] == -1)
			{
				trie[pos][str[j]-'a'] = ++cnt;
				pos = cnt;
			}
			else pos = trie[pos][str[j]-'a'];
		}
	}
	printf("%d\n",cnt);
	return 0;
}
