#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
using namespace std;

pair <int ,int> p[1003];
int n,i,x;
int main()
{
	cin>>n;
	rep(i,0,n)
	{
		cin>>x;
		p[i]=make_pair(i,x);
	}
	rep(i,0,n)
	cout<<p[i].first<<"  "<<p[i].second<<endl;
	return 0;
}
