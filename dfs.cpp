#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
using namespace std;

struct graph{
	int v;
	list <int> *adj;
};

int dfsutil(struct graph *g,int x,bool visited[])
{
	visited[x]=true;
	cout<<x<<' ';
	list<int>::iterator itr;
	for(itr=g->adj[x].begin();itr!=g->adj[x].end();itr++)
	{
		if(!visited[*itr])
		{
			dfsutil(g,*itr,visited);
		}
	}
	return 0;
}

int dfs(struct graph* g,int x)
{
	bool *visited=new bool[g->v];
	memset(visited,false,sizeof(visited));
	dfsutil(g,x,visited);
}

int main()
{
	int e,i,x,y,j;
	struct graph *g=new graph;
	cout<<"vertices??"<<endl;
	cin>>g->v;
	g->adj=new list<int>[g->v];
	cout<<"edges??"<<endl;
	cin>>e;
	cout<<"paired edges??"<<endl;
	rep(i,0,e)
	{
		cin>>x>>y;
		g->adj[x].pb(y);
		//g->adj[y].pb(x);
	}
	cout<<"starting vertex??"<<endl;
	cin>>x;
	dfs(g,x);
	return 0;
}
