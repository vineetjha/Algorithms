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
using namespace std;

int n;

int KSubset(int a[],int k,int pos,int ans[],int idx)
{
	if(pos>n)
	return 0;
	if(k==0)
	{
		int i;
		rep(i,0,idx)
		cout<<ans[i]<<" ";
		cout<<endl;
		return 0;
	}
	ans[idx]=a[pos];
	KSubset(a,k-1,pos+1,ans,idx+1);
	KSubset(a,k,pos+1,ans,idx);
}

int main()
{
	int k,i;
	int a[105];
	cin>>n>>k;
	if(k>n)
	return 0;
	int ans[k];
	rep(i,0,n)
	{
		cin>>a[i];
	}
	KSubset(a,k,0,ans,0);
	return 0;
}
