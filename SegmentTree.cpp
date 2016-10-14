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

double a[MAX],segTree[2*MAX],lazy[2*MAX];
ll n;

ll build(ll low,ll high,ll pos)
{
	if(high == low)
	{
		segTree[pos]=a[low];
		return 0;
	}
	ll mid=(high+low)/2;
	build(low,mid,2*pos+1);
	build(mid+1,high,2*pos+2);
	segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}

double query(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
	if(qlow<=low && qhigh>=high)
	return segTree[pos];
	if(qlow>high || qhigh<low)
	return INF;
	ll mid=(low+high)/2;
	return (query(qlow,qhigh,low,mid,2*pos+1)+query(qlow,qhigh,mid+1,high,2*pos+2));
}

ll update(ll qlow,ll qhigh,ll low,ll high,ll pos,ll d)
{
	if(low>high)
	return 0;
	//updating previous updates
	if(lazy[pos]!=0)
	{
		segTree[pos]+=lazy[pos];
		if(low!=high)//pushing down updates
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(qlow>high || qhigh<low)
	return 0;
	if(qlow<=low && qhigh>=high)
	{
		segTree[pos]+=d;
		if(low!=high)
		{
			lazy[2*pos+1]+=d;
			lazy[2*pos+2]+=d;
		}
		return 0;
	}
	ll mid = (low+high)/2;
	update(qlow,qhigh,low,mid,2*pos+1,d);
	update(qlow,qhigh,mid+1,high,2*pos+2,d);
	segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}

int main()
{
	ll i,t,l,r,tt;
	double d;
	cin>>n;
	rep(i,0,n)
	{
		cin>>a[i];
		//a[i]=log10(a[i]);
	}
	build(0,n-1,0);
	rep(i,0,2*n-1)
	cout<<segTree[i]<<"  ";
	cout<<endl;
	cin>>t;
	while(t--)
	{
		cin>>tt;
		cin>>l>>r;
		switch(tt)
		{
			case 0:
				cin>>d;
				//d=log10(d);
				update(l-1,r-1,0,n-1,0,d);
				rep(i,0,2*n-1)
				cout<<segTree[i]<<" ";
				cout<<endl;
				break;
			case 1:
				cout<<query(l-1,r-1,0,n-1,0)<<endl;
				break;
		}
	}
	return 0;
}
