//题意：对于一个字符串中长度为n（n为1到len）的子串，最多可以拼出多长的子串
//用kmp找每个后缀的前缀的循环节！
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1005;
const int inf = 1111111111;
int nnext[maxn],ans[maxn];
char mstr[maxn];
void findnext()
{
    int i=0, j=-1;
	nnext[0]=-1;
	int l=strlen(mstr);
	while (i<l)
	{
		if (j==-1||mstr[i]==mstr[j]) i++, j++, nnext[i]=j;
		else j=nnext[j];
	}
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    char str[maxn];
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas; ca++)
    {

        memset(ans,0,sizeof(ans));
        scanf("%s",str);
        ans[1]=strlen(str);
        for(int i = 0; str[i]; i++)
        {
            strcpy(mstr,str+i);
            findnext();
            int len = strlen(mstr);
            for(int j = len ; j >0; j--)
            {
                int x = j - nnext[j];
                if(j%x) continue;
                int p = j/x;
                for(int k = 1;k<=p; k++)
                {
                    if(p%k==0) ans[k]=max(ans[k],j);
                    else ans[k]=max(ans[k],x*k);
                }
            }
        }
        printf("Case #%d:",ca);
        for(int i = 1; i <= strlen(str);i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
