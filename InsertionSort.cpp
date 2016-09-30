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

ll n,a[MAX];

int main()
{
	ll i,j;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	for(i=1;i<n;i++)
	{
		j=i-1;
		ll temp=a[i];
		while(a[j+1]<a[j] && j>=0)
		{
			ll temp1=a[j];
			a[j]=a[j+1];
			a[j+1]=temp1;
			j--;
		}
	}
	rep(i,0,n)
	cout<<a[i]<<' ';
	return 0;
}
