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

int n,m;
vector<int> v[MAX],st;

int t_sort(bool vis[],int s)
{
	vis[s] = true;
	for(int i=0;i<v[s].size();i++)
	{
		if(!vis[v[s][i]])
		t_sort(vis,v[s][i]);
	}
	st.push_back(s);
}

int topological()
{
	bool vis[n+1];
	memset(vis,0,sizeof(vis));
	rep(i,0,n)
	{
		if(vis[i] == false)
		t_sort(vis,i);
	}
	for(int i=st.size()-1;i>=0;i--)
	cout<<st[i]<<" ";
	cout<<endl;
	return 0;
}

int main()
{
	int x,y;
	boost;
	cin>>n>>m;
	rep(i,0,m)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}
	topological();
	return 0;
}
