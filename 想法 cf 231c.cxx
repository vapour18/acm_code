//题意:对数列进行小于等于k次的加一操作,找出出现次数最大的且数值最小的数
/*solution:对每个数枚举,a[i]表示当前的数,j表示左端能到达的位置,j必然会随着i的增大非递减变化,
利用前缀和求出i到j之和,比较其与(i-j)*a[i]+k的大小关系,调整j的位置*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 100005;
int n,a[maxn],k;
long long sum;
int main()
{
	int pos,len;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	pos=0,len=1;
	for(int i=0,j=0;i<n;i++)
	{
		sum+=a[i];
		while((i-j+1LL)*a[i]>sum+k) sum-=a[j++];//注意要强制类型转化,否则要爆int
		if(i-j+1>len)
		{
			len=i-j+1;
			pos=i;
		}
	}
	printf("%d %d\n",len,a[pos]);
	return 0;
}