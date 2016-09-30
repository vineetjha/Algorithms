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

ll n,a[MAX],p[MAX],w;
pair<ll,ll> pp[MAX];

ll maxProfit()
{
	ll m[n][w+1],i,j;
	for(i=0;i<n;i++)
	m[i][0]=0;
	for(i=0;i<=w;i++)
	{
		if(i<pp[0].F)
		m[0][i]=0;
		else
		m[0][i]=pp[0].S;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(j<pp[i].F)
			{
				m[i][j]=m[i-1][j];
			}
			else
			{
				m[i][j]=max(m[i-1][j],pp[i].S+m[i-1][j-pp[i].F]);
			}
		}
	}
	/*rep(i,0,n)
	{
		for(j=0;j<=w;j++)
		{
			cout<<m[i][j]<<"  ";
		}
		cout<<endl;
	}*/
	cout<<m[n-1][w];
	return 0;
}

int main()
{
	ll i;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	rep(i,0,n)
	{
		cin>>p[i];
		pp[i]=mp(a[i],p[i]);
	}
	cin>>w;
	sort(pp,pp+n);
	maxProfit();
	return 0;
}
