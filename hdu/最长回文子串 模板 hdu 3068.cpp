#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 110005;
const int inf = 1111111111;
char s1[maxn],str[maxn*2];
int n,p[maxn*2];
void manacher()
{
    int mx=0,id;//id为当前能到达最远的p的下标，mx为当前能到达的最远的位置
    for(int i = 1; i <= n; i++)
    {
        if(mx > i) p[i] = min(p[2*id-i],mx-i);//2*id-i与i关于id对称
        else p[i]=1;
        while(str[i+p[i]]==str[i-p[i]]) p[i]++;
        if(p[i]+i>mx)
        {
            mx=p[i]+i;
            id = i;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int len;
    while(scanf("%s",s1)!=EOF)
    {
        len = strlen(s1);
        n = len*2+1;
        str[0]='+';
        for(int i = 0; i <= len; i++)
        {
            str[2*i+1]='#';
            str[2*i+2]=s1[i];
        }
        manacher();
        int ans = 1;
        for(int i = 1; i < n; i++)
            ans = max(p[i],ans);
        printf("%d\n",ans-1);
    }
    return 0;
}


