#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1e9+7
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

int d,cnt=0;
vector<int> v;

struct node{
	int data;
	struct node *l,*r;
};

struct Q {
	int data;
	struct Q *next;
};

struct node *getNode()
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->l=new_node->r=NULL;
	return new_node;
}

struct Q *getQueue()
{
	struct Q *new_node;
	new_node=(struct Q*)malloc(sizeof(struct Q));
	new_node->next=NULL;
	return new_node;
}

struct node *insertNode(struct node *root,int d)
{
	if(root==NULL)
	{
		struct node *new_node;
		new_node=getNode();
		new_node->data=d;
		return new_node;
	}
	if(d<=root->data)
	root->l=insertNode(root->l,d);
	else
	root->r=insertNode(root->r,d);
	return root;
}

struct node *search(struct node *root,int data)
{
	if(root==NULL)
	return NULL;
	if(root->data==data)
	return root;
	if(root->data<data)
	search(root->r,data);
	else
	search(root->l,data);
}

int printLevelOrder(struct node *root)
{
	struct Q *head,*new_node;
	struct node *new_root;
	head=getQueue();
	head->data=root->data;
	while(head!=NULL)
	{
		//cout<<head->data<<" ";
		new_node=head;
		while(new_node->next!=NULL)
		new_node=new_node->next;
		new_root=search(root,head->data);
		if(new_root)
		{
			struct Q *new_node1,*new_node2;
			new_node1=getQueue();
			new_node2=getQueue();
			if(new_root->l)
			{
				new_node1->data=new_root->l->data;
				new_node->next=new_node1;
			}
			if(new_root->r)
			{
				new_node2->data=new_root->r->data;
				if(new_root->l)
				new_node1->next=new_node2;
				else
				new_node->next=new_node2;
			}
		}
		head=head->next;
	}
	return 0;
}

int printLevelOrderReverse(struct node *root)
{
	struct Q *head,*new_node;
	struct node *new_root;
	head=getQueue();
	head->data=root->data;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		v.pb(head->data);
		new_node=head;
		while(new_node->next!=NULL)
		new_node=new_node->next;
		new_root=search(root,head->data);
		if(new_root)
		{
			struct Q *new_node1,*new_node2;
			new_node1=getQueue();
			new_node2=getQueue();
			if(new_root->r)
			{
				new_node1->data=new_root->r->data;
				new_node->next=new_node1;
			}
			if(new_root->l)
			{
				new_node2->data=new_root->l->data;
				if(new_root->r)
				new_node1->next=new_node2;
				else
				new_node->next=new_node2;
			}
		}
		head=head->next;
	}
	return 0;
}

int PrintInOrder(struct node *root)
{
	if(root==NULL)
	return 0;
	PrintInOrder(root->l);
	cout<<root->data<<" ";
	PrintInOrder(root->r);
}

int size(struct node *root)
{
	if(root==NULL)
	return 0;
	return (size(root->l)+1+size(root->r));
}

int height(struct node *root)
{
	if(root==NULL)
	return 0;
	return (1+max(height(root->l),height(root->r)));
}

int fullNodes(struct node *root)
{
	if(root==NULL)
	return 0;
	fullNodes(root->l);
	if(root->l&&root->r)
	cnt++;
	fullNodes(root->r);
}

int printPath(int pathLen,int p[])
{
	int i;
	for(i=0;i<pathLen;i++)
	cout<<p[i]<<" ";
	cout<<endl;
	return 0;
}

int Path(struct node *root,int pathLen,int p[])
{
	if(root==NULL)
	return 0;
	p[pathLen]=root->data;
	pathLen++;
	if(root->l==NULL&&root->r==NULL)
	printPath(pathLen,p);
	else
	{
		Path(root->l,pathLen,p);
		Path(root->r,pathLen,p);
	}
}

int main()
{
	int i,p[100];
	ios::sync_with_stdio(false);
	struct node *root;
	root=NULL;
	while(1)
	{
		cin>>d;
		if(!d)
		break;
		root=insertNode(root,d);
	}
	Path(root,0,p);
	//fullNodes(root);
	//cout<<cnt<<endl;
	//cout<<height(root)<<endl;
	//v.clear();
	//printLevelOrderReverse(root);
	//cout<<endl;
	//for(i=v.size()-1;i>=0;i--)
	//cout<<v[i]<<" ";
	//cout<<size(root)<<endl;
	return 0;
}
