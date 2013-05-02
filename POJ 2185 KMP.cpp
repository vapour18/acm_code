//poj 2185
//�ҳ���С�Ŀ��Ը��Ǵ�����С����
//�ҳ������к������е�ѭ���ڵ���С��������Ȼ����ˣ�������С����
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
int lcm(int a,int b)//����С�������ķ���
{
	int m=a*b,t;
	while(a%b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return m/b;//��������С���������������������Լ��
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