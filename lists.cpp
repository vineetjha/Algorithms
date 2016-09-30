#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
using namespace std;

ll n,i,x,y;
list<int> *l;
int main()
{
	cin>>n;
	l=new list<int>[n];
	rep(i,0,n)
	{
		cin>>x>>y;
		l[x].pb(y);
	}
	list<int>::iterator itr;
	rep(i,0,n)
	{
		for(itr=l[i].begin();itr!=l[i].end();itr++)
		cout<<*itr<<" ";
		cout<<endl;
	}
	cout<<l[0][0];
	cout<<l->size()<<endl;
	return 0;
}
