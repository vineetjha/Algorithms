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

int n,q;
vector<int> v[1003],a[1003];

int build_tree(int idx,int l,int r)
{
	if(l == r)
	{
		v[idx] = a[l];
		rep(i,0,v[idx].size())
		cout<<v[idx][i]<<" ";
		cout<<endl;
	}
	else
	{
		int mid = (l+r)/2;
		build_tree(2*idx+1,l,mid);
		build_tree(2*idx+2,mid+1,r);
		merge(v[2*idx+1].begin(),v[2*idx+1].end(),v[2*idx+2].begin(),v[2*idx+2].end(),back_inserter(v[idx]));
	}
}

int query(int node,int start,int end,int l,int r,int x)
{
	if(l>end||start>r)
	return 0;
	if(l<=start&&r>=end)
	{
		return upper_bound(v[node].begin(),v[node].end(),x)-v[node].begin();
	}
	int p1,p2;
	int mid=(start+end)/2;
	p1=query(2*node+1,start,mid,l,r,x);
	p2=query(2*node+2,mid+1,end,l,r,x);
	return p1+p2;
}

int main()
{
	int x;
	boost;
	cin>>n;
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			cin>>x;
			a[i].pb(x);
		}
	}
	
	build_tree(0,0,n-1);
	
	rep(i,0,2*n-1)
	{
		cout<<i<<"  ";
		rep(j,0,v[i].size())
		cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r>>x;
		cout<<query(0,0,n-1,l,r,x)<<endl;
	}
	return 0;
}
