#include<cstdio>
#include<cstring>
#include<stack>
#include<iostream>
using namespace std;
const int maxn=100005;
int nnext[maxn];
char mstr[maxn];
void findnext()
{
    nnext[1]=0;
    for(int j=0,i=2;mstr[i];i++)
    {
        if(j>0&&mstr[i]!=mstr[j+1]) j=nnext[j];
        if(mstr[j+1]==mstr[i]) j++;
        nnext[i]=j;
    }
}
int main()
{
    int n,len,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",mstr+1);
        findnext();
        len=strlen(mstr+1);
        x=len-nnext[len];
        if(x==len)    printf("%d\n",len);
        else if(len%x==0)    printf("0\n");
        else printf("%d\n",x-len%x);
    }
    return 0;
}
