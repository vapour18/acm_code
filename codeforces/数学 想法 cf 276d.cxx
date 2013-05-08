//题意：求[l,r]区间中任意两个数异或的最大值
//思路：l和r转化成2进制从高位开始比，直到出现li = 0， ri = 1的情况停止，则表示异或的最大值为（1<<(i+1) -1）
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	long long l,r;
	cin>>l>>r;
	if(l == r) {cout<<"0\n";return 0;}
	for(int i = 62; i >=0; i--)
	{
		if((l & (1LL << i)) ^ (r & (1LL << i)))
		{
			long long ans = ((1LL << (i + 1)) -1);
			cout<<ans<<endl;
			return 0;
		}
	}
}