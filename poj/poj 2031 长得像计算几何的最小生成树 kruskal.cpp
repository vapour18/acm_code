#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int N,K,ans;
struct node{
	int ti,di;
}trap[25005];
struct NODE{
	int ti,di;
	friend bool operator< (const NODE a,const NODE b){
		return b.ti>a.ti;//如果要掉血，那么用最长的时间换取1HP....大顶堆 

	}
};
bool cmp (node a,node b){
	if (a.di==b.di) return a.ti>b.ti;
	return a.di<b.di;
}
int solve(){
	priority_queue<NODE> q;
	int total_time=0;
	ans=0;
	for (int i=0;i < N; i++){
        	NODE temp;
			temp.ti=trap[i].ti;
			temp.di=trap[i].di;
		if (total_time + temp.ti<=temp.di){
			total_time+=temp.ti;
			q.push(temp);
		}
		else{
			total_time+=temp.ti;
			q.push(temp);
			while (total_time>trap[i].di){
				NODE green=q.top();
				q.pop();
				ans++;
				total_time-=green.ti;
				K--;
				if (K==0)
					return -1;
			}
		}
	}
	return ans;
}
int main(){
	while (scanf("%d%d",&N,&K)!=EOF){
		for (int i = 0; i <N; i++){
			scanf ("%d%d",&trap[i].ti,&trap[i].di);
		}
		sort (trap,trap+N,cmp);
		printf("%d\n",solve());
	}
}