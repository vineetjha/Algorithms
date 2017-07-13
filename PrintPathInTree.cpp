#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MM(a,x) memset(a,x,sizeof(a))
#define boost ios::sync_with_stdio(false) 
using namespace std;

int sum;

struct node{
	int data;
	struct node *lptr,*rptr;
} *root;

struct node *addnode(struct node *root,struct node *new_node)
{
	if(root == NULL)
	return new_node;
	if(root->data < new_node->data)
	root->rptr = addnode(root->rptr,new_node);
	else
	root->lptr = addnode(root->lptr,new_node);
	return root;
}

int getNode(int x)
{
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->lptr = new_node->rptr = NULL;
	new_node->data = x;
	if(root == NULL)
	{
		root = new_node;
	}
	else
	{
		addnode(root,new_node);
	}
}

int Print(int path[],int *len)
{
	int xx = 0;
	rep(i,0,*len)
	{
		xx+=path[i];
	}
	if(xx == sum)
	return 1;
	//cout<<path[i]<<" ";
	//cout<<endl;
	return 0;
}

int printInorder(struct node *temp,int path[],int len)
{
	if(temp == NULL)
	return 0;
	path[len++] = temp->data;
	if(temp->lptr == NULL && temp->rptr == NULL)
	{
		if(Print(path,&len))
		cout<<"yes"<<endl;
	}
	else
	{
		printInorder(temp->lptr,path,len);
		printInorder(temp->rptr,path,len);
	}
}

int main()
{
	int x,path[1101];
	root = NULL;
	while(1)
	{
		cin>>x;
		if(x == 0)
		break;
		getNode(x);
	}
	cin>>sum;
	printInorder(root,path,0);
	return 0;
}
