#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
//priority_queue<int> xxx 大根堆
//priority_queue<int, vector<int>, greater<int>> xxxx 小根堆
int main()
{
	int n,m,a[1005];
	priority_queue<int> q;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		q.push(a[i]);
	}
	sort(a,a+m);
	int amax=0,amin=0,num=n;
	while(num--)
	{
		int u=q.top();q.pop();
		amax+=u;
		if(--u) q.push(u);
	}
	num=n;
	for(int i=0;i<m&&num>0;)
	{
		if(a[i]) 
		{
			amin+=a[i];
			a[i]--,num--;
		}
		else i++;
	}
	printf("%d %d\n",amax,amin);
	return 0;
	
}