#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 100005;
int g[30],text[maxn];
int main()
{
	int n,len,x;
	char str[maxn];
	bool flag ;
	scanf("%d",&n);
	while(n--)
	{
		flag = 1;
		scanf("%s",str);
		for(int i = 0; str[i]; i++)
			g[str[i] - 'a'] = i;
		scanf("%s",str);
		for(int i = 0; str[i]; i++)
			text[i] = str[i] - 'a';
		len = strlen(str);
		x = (len + 1)/2;
		while(flag)
		{
			flag = 0;
			for(int i = 0, j = x; i < x,j < len; i++,j++)
			{
				if(g[text[i]] != text[j])
				{
					flag = 1;
					x+=1;
					break;
				}
			}
		}
		for(int i = 0; i < x; i++) printf("%c",text[i]+'a');
		for(int i = 0; i < x; i++) printf("%c",g[text[i]]+'a');
		printf("\n");
	}
	return 0;
}