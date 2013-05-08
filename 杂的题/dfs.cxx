#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
struct Btnode{
	char data;
	struct Btnode *lchild,*rchild;
	Btnode()
	{
		lchild=rchild=NULL;
	}
};

char str[maxn];
int pos;
void build(Btnode *&root)
{
	if(str[pos]=='\0')	return;
	root=new Btnode();
	if(str[pos]!='*')
	{
		root->data=str[pos];
		//cout<<root->data<<endl;
		pos++;
		build(root->lchild);
		build(root->rchild);
	}
	else
	{
		if(str[++pos]!='*')
		{
			build(root->rchild);
		}
		else pos++;
	}
}
void dfs(Btnode *root)
{
	cout<<root->data;
	if(root->lchild)
		dfs(root->lchild);
	//else cout<<"*";
	if(root->rchild)
		dfs(root->rchild);
	//else cout<<"*"; 
}
int main()
{
	Btnode *root;
	while(scanf("%s",str)!=EOF)
	{
		pos=0;
		build(root);
		cout<<"!!!!!!!success!!!!!!!\n";
		//cout<<root->data<<endl;
		dfs(root);//重新输出先序遍历顺序以证明其正确性
		cout<<endl;
	}
	return 0;
}
//测试数据==。
//abc**d**e**
//abc***d*e**
//abc
