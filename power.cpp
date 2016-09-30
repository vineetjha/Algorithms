#include<iostream>
#define ll long long
using namespace std;
ll pow(ll a,ll b);
int main()
{
	ll a,b,res;
	cin>>a>>b;
	res=pow(a,b);
	cout<<res;
	return 0;
}

ll pow(ll a,ll b)
{
	if(b==0)
	return 1;
	if(b==1)
	return a;
	cout<<a<<"  "<<b<<endl;
	ll t=pow(a,b/2);
	cout<<t<<endl;
	return t*t*pow(a,b%2);
}
