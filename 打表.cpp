
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 500;
struct Node
{
        char num[505];
        void init()
        {
                memset(num,0,sizeof(num));
        }
        void cpy(char ch,char str[])
        {
                num[0]=ch;
                for(int i = 0; str[i];i++)
                        num[i+1]=str[i];
                num[strlen(str)+1]='\0';
        }
};
vector<Node> s[505];

void mult(char a[],char b[])
{
        int l,sum,c[1005]={0};
        l = strlen(a)+strlen(b);
        for(int i = strlen(b)-1; i>=0 ;i--)
        {
                for(int j = strlen(a)-1,k=i+j+1;j>=0;j--,k--)
                {
                        sum=(b[i]-'0')*(a[j]-'0')+c[k];
                        c[k]=sum%10;
                        c[k-1]+=sum/10;
                }
        }
        int jj=0;
        for(int i = c[0]?0:1;i<l;i++)
                a[jj++]=(c[i]+'0');
        a[jj]='\0';
}

bool check(char str[])
{
        char res[1005];
        //for(int i = 0; str[i];i++)
             //   res[i]=str[i];
        strcpy(res,str);
        res[strlen(str)]=0;
        mult(res,res);
        int len = strlen(res);
        bool flag = 1;
        for(int i = len-1,j=strlen(str)-1; j>=0&&i>=0&&flag;i--,j--)
        {
                if(res[i]!=str[j]) flag = 0;
        }
        return flag;
}
void dabiao()
{
    for(int i = 0; i <=501;i++) s[i].clear();
    Node tmp;
    char str[5],ch;
    str[0]='\0';
    tmp.cpy('0',str);s[1].push_back(tmp);
    tmp.cpy('1',str);s[1].push_back(tmp);
    tmp.cpy('5',str);s[1].push_back(tmp);
    tmp.cpy('6',str);s[1].push_back(tmp);
    for(int i = 1; i <maxn; i++)
    {
        for(int j = 0; j < s[i].size();j++)
        {
            for(int k = 0; k <= 9; k++)
            {
                tmp.cpy(k+'0',s[i][j].num);
                if(strlen(tmp.num)>=4&&tmp.num[0]=='0'&&tmp.num[1]=='0'&&tmp.num[2]=='0'&&tmp.num[3]=='0')
                    continue;
                //if(tmp.num[0]=='0'){s[i+1].push_back(tmp);continue;}
               if(check(tmp.num)) {s[i+1].push_back(tmp);}
            }
        }
    }
    for(int i = 1; i <=maxn; i++)
        for(int j = 0; j < s[i].size();j++)
        {
            if(s[i][j].num[0]!='0')
                printf("%s\n",s[i][j].num);
        }
}
int main()
{
        freopen("out1.txt","w",stdout);
        dabiao();
        return 0;
}
