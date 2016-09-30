#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
using namespace std;

int t,n,m,k,a[MAX];
list<int> *adj;
int main()
{
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n*m+1)
		cin>>a[i];
		adj=new list<int>[n*m+1];
		rep(i,1,n*m+1)
		{
			if(i%m==0&&i+m<=n*m)
			adj[i].push_back(i+m);
			else if(i>n*m-m&&i+1<=n*m)
			adj[i].push_back(i+1);
			else
			{
				if(i+1<=n*m)
				adj[i].push_back(i+1);
				if(i+m<=n*m)
				adj[i].push_back(i+m);
				if(i+m+1<=n*m)
				adj[i].push_back(i+m+1);
			}
		}
		rep(i,1,n*m+1)
		{
			cout<<i<<" ";
			list<int>::iterator itr;
			for(itr=adj[i].begin();itr!=adj[i].end();itr++)
			cout<<*itr<<" ";
			cout<<endl;
		}
	}
	return 0;
}
