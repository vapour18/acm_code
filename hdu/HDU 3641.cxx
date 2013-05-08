#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<iostream>
#define maxn 500000
using namespace std;
int f[maxn];
map<string,int> mp;
set<int> myset[maxn];
set<int> ::iterator it;
int find(int x)
{
	return f[x]==x? x:f[x]=find(f[x]);
}
int main()
{
	int n,m,p,day,ans;
	char str[20];
	string name,name2;
	
	while(cin>>n)
	{
		p=0;
		mp.clear();
		for(int i=0;i<=n;i++)	f[i]=i;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			if(str[0]=='a')
			{
				cin>>name>>m;
				mp[name]=++p;
				for(int j=0;j<m;j++)
				{
					cin>>day;
					myset[mp[name]].insert(day);				
				}
				
			}
			else if(str[0]=='s')
			{
				
				cin>>name>>name2;				
				int x,y;
				x=find(mp[name]),y=find(mp[name2]);
				if(x!=y){
					if(myset[x].size()<myset[y].size())
					{
						for(it=myset[x].begin();it!=myset[x].end();it++)
							myset[y].insert(*it);
						f[x]=y;
					}
					else
					{
						for(it=myset[y].begin();it!=myset[y].end();it++)
							myset[x].insert(*it);
						f[y]=x;
					}
			}
				
			}
			else
			{
				cin>>name;
				if(mp.find(name)==mp.end())	mp[name]=++p;
				int x=find(mp[name]);
				ans=myset[x].size();
				cout<<ans<<endl;
			}
		}
		for(int i=0;i<maxn;i++)
			myset[i].clear();
	}
	return 0;
}
