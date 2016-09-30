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

struct graph* getGraph(struct graph* g)
{
	int v;
	cout<<"enter no. of vertices"<<endl;
	cin>>v;
	g->v=v;
	g->adj=new list<int>[v];
	return g;
}

struct graph* addEdges(struct graph* g,int x,int y)
{
	g->adj[x].pb(y);
	//g->adj[y].pb(x);
	return g;
}

int bfs(struct graph *g,int s)
{
	int i;
	bool visited[g->v];
	rep(i,0,g->v)
	visited[i]=0;
	list<int> queue;
	visited[s]=true;
	queue.pb(s);
	list<int>::iterator itr;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(itr=g->adj[s].begin();itr!=g->adj[s].end();itr++)
		{
			if(!visited[*itr])
			{
				queue.pb(*itr);
				visited[*itr]=true;
			}
		}
	}
	return 0;
}

int main()
{
	int i,e,x,y,j,s;
	struct graph *g=new graph;;
	//g=(struct graph*)malloc(sizeof(struct graph));
	g=getGraph(g);
	//cout<<g->v<<endl;
	cout<<"enter edges"<<endl;
	cin>>e;
	rep(i,0,e)
	{
		cin>>x>>y;
		g=addEdges(g,x,y);
	}
	cout<<"enter starting node for the search"<<endl;
	cin>>s;
	bfs(g,s);
	return 0;
}
