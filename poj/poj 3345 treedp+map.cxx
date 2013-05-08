#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#define maxn 205
using namespace std;
#define inf 1e9
typedef long long ll;
int n,m,k,cou;
char mmap[205][105];
int mon[205],head[205];
int dps[205][205];
struct point{
	int to;
	int next;
}leaf[40010];
void addedge(int a,int b){
	leaf[cou].to=b;
	leaf[cou].next=head[a];
	head[a]=cou++;
}
int dp(int u){
	int i,j,sum=0;
	if(u)sum=1;
	for(i=head[u];i!=-1;i=leaf[i].next){
		sum+=dp(leaf[i].to);
	}
	for(i=head[u];i!=-1;i=leaf[i].next){
		
		for(j=sum;j>=0;j--){                         
			for(k=0;k<=j;k++){
				dps[u][j]=min(dps[u][j-k]+dps[leaf[i].to][k],dps[u][j]);
			}
		}
	}
	dps[u][sum]=min(dps[u][sum],mon[u]);	
	return sum;
}
int main(){
	char in[5],tmp[105],flag[205];
	int i,j;
	while(scanf("%s",in)&&in[0]!='#'){
		sscanf(in,"%d",&n);
		scanf("%d",&m);
		k=0;
		cou=0;
		memset(head,-1,sizeof(head));
		memset(flag,0,sizeof(flag));
		map<string,int> co;
		int u=0;
		for(i=1;i<=n;i++){
			scanf("%s",tmp);
			if(co.find(tmp)==co.end()) co[tmp]=++u;
			scanf("%d",&mon[co[tmp]]);
			int pp=co[tmp];
			while(scanf("%c",&tmp[0]) && tmp[0]!='\n'){
				scanf("%s",tmp);
				if(co.find(tmp)==co.end()) co[tmp]=++u;
				flag[co[tmp]]=1;
				addedge(pp,co[tmp]);
			}	
		}
		for(i=1;i<=n;i++)
			if(!flag[i])
				addedge(0,i);   
		for(i=0;i<=n;i++){
			for(j=1;j<=n;j++)
				dps[i][j]=inf;
			dps[i][0]=0;
		}
		mon[0]=inf;
		dp(0);
		int ans=inf;
		for(i=m;i<=n;i++)          
			ans=min(ans,dps[0][i]);
		printf("%d\n",ans);
	}
	return 0;
}
