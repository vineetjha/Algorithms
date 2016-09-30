#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
using namespace std;

map < int , int > m;
int n,i,x;
int main()
{
	cin>>n;
	rep(i,0,n)
	{
		cin>>x;
		m.insert(pair <int,int > (i,x));
	}
	m.insert(pair <int,int> (-1,10));
	map <int ,int > :: iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	cout<<itr->first<<"  "<<itr->second<<endl;
	return 0;
}













