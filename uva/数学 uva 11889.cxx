//���⣺cΪa��b����С����������֪a��c������С��b
//lcm��a,b��= a*b/gcd(a,b);���������b���ڣ���c/a��ʾb�Ķ��в��֣��˲�����a�����ʣ�Ӧ����a���Ը����Լ����b�����������֪������
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 100005;
long long a[maxn];
int gcd(int a,int b)
{
	int c;
	while(a%b)
	{
		c = a%b;
		a = b, b = c;
	}
	return b;
}
int main()
{
	int n,a,c,b,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&c);
		if(c%a)
		{
			cout<<"NO SOLUTION\n";
			continue;
		}
		b = c/a;
		x = gcd(b,a);
		while(x != 1)
		{
			b *= x;
			a/=x;
			x = gcd(a,b);
		}
		cout<<b<<endl;
	}
}
