#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)

int i,x,y;

using namespace std;

struct node{
	int vn;
	struct node* next;
};

struct headPointer{
	struct node *head;
};
struct graph{
	int v,e;
	struct headPointer a[10];
};

struct graph *assignVertex()
{
	struct graph *g;
	g=(struct graph*)malloc(sizeof(struct graph));
	cin>>g->v>>g->e;
	rep(i,0,g->v)
	{
		struct node *h;
		h=(struct node*)malloc(sizeof(struct node));
		h->vn=i;
		h->next=h;
		g->a[i].head=h;
	}
	return g;
}

struct graph* getValue(struct graph *g)
{
	rep(i,0,g->e)
	{
		cin>>x>>y;
		struct node *temp;
		temp=g->a[x].head;
		while(temp->next!=g->a[x].head)
		temp=temp->next;
		struct node *new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->vn=y;
		temp->next=new_node;
		new_node->next=g->a[x].head;
	}
	return g;
}

int display(struct graph *g)
{
	rep(i,0,g->v)
	{
		struct node *temp;
		temp=g->a[i].head;
		do{
			cout<<temp->vn<<"  ";
			temp=temp->next;
		}while(temp!=g->a[i].head);
		cout<<endl;
	}
	return 0;
}

int main()
{
	struct graph *g;
	//g=(struct graph*)malloc(sizeof(struct graph));
	//cin>>g->v>>g->e;
	g=assignVertex();
	display(g);
	g=getValue(g);
	display(g);
	return 0;
}
