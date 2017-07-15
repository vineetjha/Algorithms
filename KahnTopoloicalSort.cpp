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
vector<int> v[MAX];

int kahn()
{
	int id[n+1];
	memset(id,0,sizeof(id));
	rep(i,1,n+1)
	{
		for(int j=0;j<v[i].size();i++)
		{
			id[v[i][j]]++;
		}
	}
	vector<int> q,top;
	rep(i,1,n+1)
	{
		if(id[i] == 0)
		{
			q.push_back(i);
			cout<<i<<endl;
		}
	}
	int cnt = 0;
	while(!q.empty())
	{
		int x = q[0];
		top.push_back(x);
		q.erase(q.begin());
		for(int i=0;i<v[x].size();i++)
		{
			if(--id[v[x][i]] == 0)
			q.push_back(v[x][i]);
		}
		cnt++;
	}
	if(cnt == n)
	{
		cout<<"yes"<<endl;
		rep(i,0,top.size())
		cout<<top[i]<<" ";
		cout<<endl;
	}
	else
	cout<<"no"<<endl;
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
	kahn();
	return 0;
}
