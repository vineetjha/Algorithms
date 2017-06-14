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

int n,lvl[MAX],fo[MAX],cur,E[MAX],parent[MAX],X[MAX];
bool vis[MAX];
vector<int> v[MAX];
pair<int,int> seg[MAX];

int dfs(int s,int p)
{
	if(p != -1)
	lvl[s] = lvl[p]+1;
	fo[s] = cur;
	E[cur++] = s;
	vis[s] = true;
	for(int i=0;i<v[s].size();i++)
	{
		if(!vis[v[s][i]])
		{
			dfs(v[s][i],s);
		}
	}
	if(p!=-1)
	E[cur++] = p;
	return 0;
}

int build_tree(int idx,int st,int en)
{
	if(st == en)
	{
		seg[idx].F = X[st];
		seg[idx].S = st;
	}
	else
	{
		int mid = (st+en)/2;
		build_tree(2*idx+1,st,mid);
		build_tree(2*idx+2,mid+1,en);
		seg[idx].F = min(seg[2*idx+1].F,seg[2*idx+2].F);
		seg[idx].S = seg[2*idx+1].F < seg[2*idx+2].F ? seg[2*idx+1].S : seg[2*idx+2].S;
	}
}

int query(int node,int start,int end,int l,int r)
{
	if(l>end||start>r)
	return MAX;
	if(l<=start&&r>=end)
	{
		return node;
	}
	int p1,p2;
	int mid=(start+end)/2;
	p1=query(2*node+1,start,mid,l,r);
	p2=query(2*node+2,mid+1,end,l,r);
	return seg[p1].F < seg[p2].F ? p1 : p2 ;
}

int main()
{
	boost;
	cin>>n;
	memset(vis,false,sizeof(vis));
	int x,y;
	rep(i,0,n-1)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	cur = 0;
	lvl[1] = 0;
	dfs(1,-1);

	for(int i=0;i<cur;i++)
	X[i] = lvl[E[i]];

	build_tree(0,0,cur-1);

	int q;
	cin>>q;
	seg[MAX].F = MAX;
	while(q--)
	{
		cin>>x>>y;
		if(fo[x]>fo[y])
		{
			int XX = query(0,0,cur-1,fo[y],fo[x]);
			cout<<E[seg[XX].S]<<endl;
		}
		else
		{
			int XX = query(0,0,cur-1,fo[x],fo[y]);
			cout<<E[seg[XX].S]<<endl;
		}
	}
	return 0;
}
