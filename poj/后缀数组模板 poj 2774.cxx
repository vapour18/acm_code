//后缀数组求最长公共前缀.注意,两个串合并成一个之间加一个未出现过的字符,防止匹配过头
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
const int maxn = 200050;
using namespace std;

int sa[maxn],rank[maxn],height[maxn];
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];
int cmp(int *r,int a,int b,int len)
{
	return r[a] == r[b] && r[a+len] == r[b+len];
}
void da(int *r,int n,int m)//基数排序
{
	int i,j,p,*x = wa, *y = wb;
	memset(wd,0,sizeof(wd));
	for(i = 0; i < n; i++)	wd[x[i]=r[i]]++;//统计每个字符的个数
	for(i = 1; i < m; i++) wd[i]+=wd[i-1];//计算前缀和,给为字符标号做准备
	for(i = n - 1; i>=0;i--) sa[--wd[x[i]]] = i;//长度为1时的排序,从n-1开始是为了保证排序的稳定性
	for(j = 1, p = 1; p < n; j*=2,m = p)
	{
		for(p = 0, i = n - j; i < n; i++) y[p++] = i;//y代表第二关键字的排序,借助了上一次排序的结果
		//到位置在第n-j至n的元素的第二关键字都为0，因此如果按第二关键字排序，必然这些元素都是排在前面的。
		for(i = 0; i < n; i++)
			if(sa[i] >= j) y[p++] = sa[i] - j;//找到以此为第二关键字对应的串的位置
		for(i = 0; i < n; i++)	wv[i] = x[y[i]];//x数组可以认为是上一次排序的rank
		memset(wd,0,sizeof(wd));//对第一关键字排序
		for(i = 0; i < n; i++)	wd[wv[i]]++;
		for(i = 1; i < m; i++) wd[i]+=wd[i-1];
		for(i = n - 1; i>=0;i--) sa[--wd[wv[i]]] = y[i];
		swap(x,y);//用y保留rank的值,节约空间
		for(p = 1,x[sa[0]] = 0, i = 1; i < n; i ++)//去重,更新rank,也就是x
			x[sa[i]] = cmp(y,sa[i - 1],sa[i],j)? p - 1:p++;
        //sa[i]表示排名为i的字符串的开头的位置，y[sa[i]]是上次排序该字符串的rank，如果第一关键字和第二关键字都一样，说明重了
	}
	return;
}
void calheight(int *r,int n)
{
    //height[i]=suffix(sa[i-1])与suffix(sa[i])的最长公共前缀，即rank相邻的两个后缀的最长公共前缀
    //height有性质height[rank[i]]>=height[rank[i-1]] -1
	int k = 0,j;
	for(int i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for(int i = 0; i < n; height[rank[i++]] = k)
		for(k?k--:0,j = sa[rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}
int main()
{
	char str[maxn];
	int num[maxn],l1,n;
	scanf("%s",str);
	l1 = strlen(str);
	for(int i = 0; str[i]; i++)
		num[i] = str[i] - 'a' +2;
	num[l1] = 1;
	n = l1;
	scanf("%s",str);
	for(int i = 0;str[i];i++) num[++n] = str[i] - 'a' +2;
	da(num,n+1,30);
	calheight(num,n);
	int ans = 0;
	for(int i = 2; i <= n; i++)
		if((sa[i]<l1&&sa[i-1]>l1)||(sa[i]>l1&&sa[i-1]<l1))
			ans = max(ans,height[i]);
	printf("%d\n",ans);
	return 0;
}
