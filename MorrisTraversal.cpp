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

int printInorder(struct node *temp)
{
	if(temp == NULL)
	return 0;
	printInorder(temp->lptr);
	cout<<temp->data<<" ";
	printInorder(temp->rptr);
}

struct node *Morris()
{
	struct node *curr,*pre;
	curr = root;
	while(curr != NULL)
	{
		if(curr->lptr == NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->rptr;
		}
		else
		{
			pre = curr->lptr;
			while(pre->rptr != NULL && pre->rptr != curr)
			pre = curr->rptr;
			if(pre->rptr == NULL)
			{
				pre->rptr = curr;
				curr = curr->lptr;
			}
			else
			{
				pre->rptr = NULL;
				cout<<curr->data<<" ";
				curr = curr->rptr;
			}
		}
	}
}

int main()
{
	int x;
	root = NULL;
	while(1)
	{
		cin>>x;
		if(x == 0)
		break;
		getNode(x);
	}

	Morris();
	return 0;
}
