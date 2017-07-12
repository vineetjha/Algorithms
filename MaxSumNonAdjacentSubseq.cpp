#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define MAX 1000006
#define INF 1e8
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MM(a,x) memset(a,x,sizeof(a))
#define boost ios::sync_with_stdio(false) 
using namespace std;

int n,a[MAX];

int main()
{
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	int incl = a[0];
	int excl = 0;
	int incl_new;
	for(int i=1;i<n;i++)
	{
		incl_new = max(excl+a[i],incl);
		excl = incl;
		incl = incl_new;
	}
	cout<<incl<<endl;
	return 0;
}
