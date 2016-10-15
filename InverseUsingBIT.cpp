//program to count inversions using BITree
// simple theory is to travesrse the elements of array from n-1 to 0 and -
// 1. find the elements lesser than current element traversed using findSum in BIT
// 2. update the element thus traversed as 1 in BIT
// inv keep on counting sum from 1 and thus result is obtained.
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
#define boost ios::sync_with_stdio(false) 
using namespace std;

ll n,a[MAX],maxi;

ll getSum(ll x,ll inva[])
{
	ll idx=x,sum=0;
	while(idx>0)
	{
		sum+=inva[idx];
		idx-=(idx&(-1*idx));
	}
	return sum;
}

ll update(ll idx,ll *inva)
{
	while(idx<=maxi)
	{
		inva[idx]+=1;
		idx+=(idx&(-1*idx));
	}
	return 0;
}

ll getInverse()
{
	ll i;
	ll inv=0;
	maxi=0;
	rep(i,0,n)
	{
		if(maxi<a[i])
		maxi=a[i];
	}
	ll inva[maxi+1];
	memset(inva,0,sizeof(inva));
	for(i=n-1;i>=0;i--)
	{
		inv+=getSum(a[i]-1,inva);
		update(a[i],inva);
	}
	return inv;
}

int main()
{
	ll i;
	boost;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	cout<<getInverse()<<endl;
	return 0;
}
