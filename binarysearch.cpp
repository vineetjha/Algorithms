#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
using namespace std;

ll n,a[MAX],q,x;

ll bsearch(ll x,ll first,ll last)
{
	if(first>last)
	return -1;
	ll mid=(first+last)/2;
	if(a[mid]==x)
	return mid+1;
	if(a[mid]>x)
	bsearch(x,first,mid-1);
	else
	bsearch(x,mid+1,last);
}

int main()
{
	ll i,t;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	sort(a,a+n);
	cin>>q;
	while(q--)
	{
		cin>>x;
		t=bsearch(x,0,n-1);
		if(t==-1)
		cout<<"Not Found"<<endl;
		else
		cout<<t<<endl;
	}
	return 0;
}
