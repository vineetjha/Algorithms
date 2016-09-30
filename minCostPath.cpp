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

ll cost[1003][1003],n,m,t[1003][1003];

int main()
{
	ll i,j;
	cin>>n>>m;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			cin>>cost[i][j];
			t[i][j]=0;
		}
	}
	t[0][0]=cost[0][0];
	rep(i,1,n)
	{
		t[i][0]=t[i-1][0]+cost[i][0];
	}
	rep(i,1,m)
	{
		t[0][i]=t[0][i-1]+cost[0][i];
	}
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			t[i][j]=cost[i][j]+min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]));
		}
	}
	rep(i,0,n)
	{
		rep(j,0,m)
		cout<<t[i][j]<<" ";
		cout<<endl;
	}
	cout<<t[n-1][m-1]<<endl;
	return 0;
}
