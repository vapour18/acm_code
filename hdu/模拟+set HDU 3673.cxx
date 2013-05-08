#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<algorithm>
#define maxn 1<<20
using namespace std;
struct Node{
	int id,cnt,t;
	bool operator < (const Node &a) const
	{
		if(cnt!=a.cnt)	return a.cnt<cnt;//数量按升序
		return t<a.t;//数量相同按时间排序
	}
}tmp;
int n,m;
set<Node> myset;
pair<int,int> p[maxn];
int main()
{
	int a,ans,ca=1;
	while(scanf("%d%d",&m,&n)&&(m||n))
	{
		ans=0;
		myset.clear();
		memset(p,-1,sizeof(p));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(p[a].first==-1)//a未出现过
			{
				p[a]=make_pair(i,1);
				if((int)myset.size()==m)//包满了
				{
					p[myset.begin()->id].first=-1;
					myset.erase(myset.begin());
					ans++;
				}
				tmp.t=i,tmp.id=a,tmp.cnt=1;
				myset.insert(tmp);
			}
			else
			{
				tmp.id=a,tmp.t=p[a].first,tmp.cnt=p[a].second;
				myset.erase(tmp);//擦除
				p[a].second++;
				tmp.cnt=p[a].second;
				myset.insert(tmp);
			}
		}
		printf("Case %d: %d\n",ca++,ans);
	}
	return 0;
}



