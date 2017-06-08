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
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define MM(a,x) memset(a,x,sizeof(a))
#define boost ios::sync_with_stdio(false) 
using namespace std;

int p[MAX],pp;

struct node{
	int data;
	struct node *lptr,*rptr;
};

struct node* tree(struct node *root,int x)
{
	if(root == NULL)
	{
		struct node *new_node;
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = x;
		new_node->lptr = new_node->rptr = NULL;
		root = new_node;
		p[root->data] = pp;
		return root;
	}
	else
	{
		if(root->data>x)
		{
			pp = root->data;
			root->lptr = tree(root->lptr,x);
		}
		else
		{
			pp = root->data;
			root->rptr = tree(root->rptr,x);
		}
		return root;
	}
}

int printTree(struct node *root)
{
	if(root == NULL)
	return 0;
	printTree(root->lptr);
	cout<<root->data<<"  "<<p[root->data]<<endl;
	printTree(root->rptr);
}

struct node *findLCA(struct node* root, int n1, int n2)
{
    if (root == NULL) return NULL;
	cout<<root->data<<endl;
    if (root->data == n1 || root->data == n2)
        return root;
 
    node *left_lca  = findLCA(root->lptr, n1, n2);
    node *right_lca = findLCA(root->rptr, n1, n2);

    if (left_lca && right_lca)  return root;
 
    return (left_lca != NULL)? left_lca: right_lca;
}

int main()
{
	int x;
	struct node *root;
	root = NULL;
	boost;
	while(1)
	{
		cin>>x;
		if(x==0)
		break;
		root = tree(root,x);
	}
	p[root->data] = -1;
	cout<<"LCA of : ";
	int y;
	cin>>x>>y;
	struct node *temp;
	temp = findLCA(root,x,y);
	cout<<temp->data<<endl;
	//printTree(root);
	return 0;
}
