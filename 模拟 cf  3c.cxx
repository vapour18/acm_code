#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char g[5][5];
bool gao(char ch)
{
	for(int i = 0;i < 3; i++)
		if(g[i][0] == ch&&g[i][1]==ch&&g[i][2]==ch) return 1;
	for(int i = 0;i < 3; i++)
		if(g[0][i] == ch&&g[1][i]==ch&&g[2][i]==ch) return 1;
	if(g[0][0] == ch&&g[1][1] == ch&&g[2][2] == ch)	return 1;
	if(g[0][2]==ch&&g[1][1]==ch&&g[2][0]==ch) return 1;
	return 0;
}
int main()
{
	int cnta,cntb;
	cnta=cntb=0;
	scanf("%s%s%s",g[0],g[1],g[2]);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(g[i][j] == 'X') cnta++;
			else if(g[i][j] =='0') cntb++;
		}
	bool a = gao('X');
	bool b = gao('0');
	//cout<<cnta<<cntb<<endl;
	if(!a&&!b)
	{
		//cout<<"***\n";
		if(cnta+cntb==9&&cnta-cntb==1) printf("draw\n");
		else if(cnta+cntb<9&&cnta==cntb) printf("first\n");
		else if(cnta+cntb<9&&cnta-1==cntb) printf("second\n");
		else printf("illegal\n");
	}
	else if(a==1&&b==0)
	{
		if(cnta-cntb==1) printf(" the first player won\n");
		else printf("illegal\n");
	}
	else if(a==0&&b==1)
	{
		if(cnta==cntb) printf("the second player won\n");
		else printf("illegal\n");
	}
	else printf("illegal\n");
	return 0;
}