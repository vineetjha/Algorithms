#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define rep(i,a,b) for(i=a;i<b;i++)
#define pb push_back
using namespace std;

ll n,p[MAX],i,j,k,t;
double prd;

int seive(long long n)
{
	bool a[n+1];
	for(i=0;i<n+1;i++)
	a[i]=true;
	for(i=2;i*i<=n;i++)
	{
		a[0]=false;
		a[1]=false;
		for(j=i*i;j<=n;j+=i)
		{
			a[j]=false;
		}
	}
	k=0;
	for(i=0;i<=n;i++)
	{
		if(a[i]==true)
		{
			p[k]=i;
			++k;
		}
	}
	return 0;
}

int main()
{
	cin>>t;
	seive(1e6);
	while(t--)
	{
	cin>>n;
	prd=n;
	rep(i,0,k)
	{
		if(p[i]>n)
		break;
		if(n%p[i]==0)
		{
			prd*=(1-(1.00/p[i]));
			//cout<<prd<<" "<<p[i]<<endl;
		}
	}
	cout<<prd<<endl;
}
	return 0;
}
