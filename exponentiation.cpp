#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
using namespace std;

ll x,n,res=1,ans;

ll Exponentiation(ll x,ll n)
{
	res=1;
	while(n)
	{
		if(n%2)
		{
			res*=x;
			res%=e;
		}
		x*=x;
		x%=e;
		n/=2;
	}
	return res%e;
}

int main()
{
	cin>>x>>n;
	/*while(n)
	{
		if(n%2)
		res*=x;
		x*=x;
		n/=2;
	}*/
	ans=Exponentiation(x,n);
	cout<<ans%e;
	return 0;
}
