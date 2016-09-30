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

ll merge(ll l,ll m,ll r)
{
	ll i,j;
	ll a1[m-l+1],a2[r-m];
	for(i=0;i<m-l+1;i++)
	a1[i]=a[l+i];
	for(i=0;i<r-m;i++)
	a2[i]=a[m+1+i];
	ll n1=m-l+1,n2=r-m,k=l;
	i=0,j=0;
	while(i<n1 && j<n2)
	{
		if(a1[i]<a2[j])
		{
			a[k]=a1[i];
			k++,i++;
		}
		else
		{
			a[k]=a2[j];
			k++,j++;
		}
	}
	while(i<n1)
	{
		a[k]=a1[i];
		k++,i++;
	}
	while(j<n2)
	{
		a[k]=a2[j];
		k++,j++;
	}
	return 0;
}

ll mergeSort(ll l,ll r)
{
	if(l<r)
	{
		ll m=(l+r)/2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		merge(l,m,r);
	}
	return 0;
}

int main()
{
	ll i;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	mergeSort(0,n-1);
	rep(i,0,n)
	cout<<a[i]<<' ';
	return 0;
}
