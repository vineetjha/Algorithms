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

ll n,a[MAX],s;

ll SubsetSum()
{
	ll i,j;
	bool mat[n][s+1];
	for(i=0;i<s+1;i++)
	{
		if(i==a[0])
		mat[0][i]=true;
		else
		mat[0][i]=false;
	}
	for(i=0;i<n;i++)
	mat[i][0]=true;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=s;j++)
		{
			if(j<a[i])
			mat[i][j]=mat[i-1][j];
			else
			{
				mat[i][j]=mat[i-1][j-a[i]];
			}
		}
	}
	cout<<mat[n-1][s]<<endl;
	return 0;
}

int main()
{
	ll i;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	sort(a,a+n);
	cin>>s;
	SubsetSum();
	return 0;
}
