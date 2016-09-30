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

ll n,s[MAX],f[MAX];
pair<ll,ll> p[MAX];

int main()
{
	ll i;
	cin>>n;
	rep(i,0,n)
	{
		cin>>s[i];
	}
	rep(i,0,n)
	{
		cin>>f[i];
	}
	rep(i,0,n)
	{
		p[i]=mp(f[i],s[i]);
	}
	sort(p,p+n);
	cout<<0<<"  "<<p[0].S<<"  "<<p[0].F<<endl;
	ll c=0;
	for(i=1;i<n;i++)
	{
		if(p[c].F<p[i].S)
		{
			cout<<i<<"  "<<p[i].S<<"  "<<p[i].F<<endl;
			c=i;
		}
	}
	cout<<endl;
	return 0;
}
