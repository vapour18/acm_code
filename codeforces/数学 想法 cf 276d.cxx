//���⣺��[l,r]�����������������������ֵ
//˼·��l��rת����2���ƴӸ�λ��ʼ�ȣ�ֱ������li = 0�� ri = 1�����ֹͣ�����ʾ�������ֵΪ��1<<(i+1) -1��
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