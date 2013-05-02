//光标移动可以有两种情况 1. 先正后反2.先反后正
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn = 1005;
int main()
{
	int ans,ca,pos,tmp,len;
	char str[maxn];
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%s",str);
		len = strlen(str);
		ans = 0;
		tmp = 1111111111;
		for(int i = 0; str[i]; i++)
			ans+=min(str[i]-'A','A'-str[i]+26);
		for(int i = 0; str[i]; i++)
		{
			for(pos = i+1; str[pos]&&str[pos]=='A';pos++);
			tmp= min(tmp,min(i*2+(len - pos),(len-pos)*2+i));
		}
		printf("%d\n",ans+tmp);
	}
	return 0;
}