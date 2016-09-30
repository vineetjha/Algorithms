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

ll n,col[MAX],src,ans,ff;
list<ll> *adj;

ll dfsutil(ll s,bool visited[])
{
	//cout<<"vineet"<<endl;
	visited[s]=true;
	list<ll>::iterator i;
	stack<ll> ss;
	ss.push(s);
	while(!ss.empty())
	{
		ll x=ss.top();
		//cout<<x<<' ';
		ss.pop();
		for(i=adj[x].begin();i!=adj[x].end();i++)
		{
			if(!visited[*i])
			{
				if(col[src]==col[*i]&&!ff)
				{
					ans=*i;
					ff=1;
				}
				ss.push(*i);
				visited[*i]=1;
			}
		}
	}
	return 0;
}

int dfs(ll s)
{
	//cout<<"vineet"<<endl;
	bool visited[n];
	memset(visited,false,sizeof(visited));
	src=s;
	ans=-1;
	ff=0;
	//MM(visited,false);
	dfsutil(s,visited);
	cout<<ans<<" ";
}

int main()
{
	ll c,i,x,y;
	cin>>n;
	adj=new list<ll>[n+1];
	cin>>c;
	rep(i,1,n)
	{
		cin>>x;
		adj[i+1].pb(x);
		//adj[y].pb(x);
	}
	rep(i,1,n+1)
	cin>>col[i];
	/*rep(i,1,n+1)
	{
		cout<<i<<' ';
		list<ll>::iterator itr;
		for(itr=adj[i].begin();itr!=adj[i].end();itr++)
		{
			cout<<*itr<<' ';
		}
		cout<<endl;
	}*/
	//cout<<"vineet"<<endl;
	rep(i,1,n+1)
	dfs(i);
	return 0;
}
