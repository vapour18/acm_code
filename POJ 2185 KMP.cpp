//poj 2185
//找出最小的可以覆盖大矩阵的小矩阵；
//找出所有行和所有列的循环节的最小公倍数，然后相乘，所求即最小矩阵
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
char a[10005][80];
int r,c,next[10005];
int rfindnext(int x)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<c)
	{
		if(j==-1||a[x][i]==a[x][j])
		{
			i++,j++;
			next[i]=j;
		}
		else	j=next[j];
	}
	return i-next[i];
}
int cfindnext(int x)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<r)
	{
		if(j==-1||a[i][x]==a[j][x])
		{
			i++,j++;
			next[i]=j;
		}
		else	j=next[j];
	}
	return i-next[i];
}
int lcm(int a,int b)//求最小公倍数的方法
{
	int m=a*b,t;
	while(a%b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return m/b;//两数的最小公倍数是两数积除以最大公约数
}
int main()
{
	int ansr=1,ansc=1;
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;i++)
		scanf("%s",a[i]);
	for(int i=0;i<r;i++)
	{
		ansr=lcm(ansr,rfindnext(i));
		if(ansr>c)
		{
			ansr=c;
			break;
		}
	}
	for(int i=0;i<c;i++)
	{
		ansc=lcm(ansc,cfindnext(i));
		if(ansc>r)
		{
			ansc=r;
			break;
		}
	}
	printf("%d\n",ansr*ansc);
}