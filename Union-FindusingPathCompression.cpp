#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define MM(a,x) memset(a,x,sizeof(a)) 
using namespace std;

ll n,m;
pair<int,int> p[MAX]; //p -> <parent,rank>

struct edge{
	int src;
	int des;
};

struct graph{
	int v,edges;
	struct edge *edge;
};

struct graph *createGraph()
{
	struct graph *g=(struct graph*)malloc(sizeof(struct graph));
	g->v=n;
	g->edges=m;
	g->edge=(struct edge*)malloc(m*sizeof(struct edge));
	return g;
}

int find(int x)
{
	if(p[x].F!=x)
	find(p[x].F);
	//cout<<p[x].F<<" ";
	return p[x].F;
}

int union_subset(int x,int y)
{
	int xroot=p[x].F;
	int yroot=p[y].F;
	int xrank=p[x].S;
	int yrank=p[y].S;
	if(xrank>yrank)
	{
		p[y].F=x;
	}
	if(xrank<yrank)
	{
		p[x].F=y;
	}
	if(xrank==yrank)
	{
		p[y].F=x;
		p[x].S++;
	}
	return 0;
}

bool isCyclic(struct graph *g)
{
	int v=g->v;
	int edges=g->edges;
	for(int i=0;i<edges;i++)
	{
		int x=find(g->edge[i].src);
		cout<<g->edge[i].src<<"  "<<x<<endl;
		int y=find(g->edge[i].des);
		cout<<g->edge[i].des<<"  "<<y<<endl;
		if(x==y)
		return 0;
		union_subset(x,y);
	}
	return 1;
}

int main()
{
	int i,x,y;
	cin>>n>>m;
	struct graph *g=createGraph();
	rep(i,0,m)
	{
		cin>>x>>y;
		g->edge[i].src=x;
		g->edge[i].des=y;
	}
	for(i=0;i<n;i++)
	{
		p[i]=mp(i,0);
	}
	if(isCyclic(g))
	cout<<"Graph have no cycle"<<endl;
	else
	cout<<"graph have cycle"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<p[i].F<<"  "<<p[i].S<<endl;
	}
	return 0;
}




