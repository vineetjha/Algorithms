#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<utility>
#include<queue>
#include<map>
#include<iterator>
#define ll long long
#define ull unsigned long long
#define e 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
#define sll(a) scanf("%I64d",&a)
#define sllh(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a);
#define si(a) scanf("%d",&a)
#define pll(a) printf("%I64d\n",a)
#define pllh(a) printf("%lld\n",a)
#define pl(a) printf("%ld\n",a);
#define pi(a) printf("%d\n",a)
using namespace std;
ll n,i;
ll prd=1;
ll pow(ll a, ll b, ll MOD) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
ll modInverse(ll a, ll m) {
    return pow(a,m-2,m);
}
int main()
{
	cin>>n;
	for(i=n;i>n-6;i--)
	{
		prd*=i;
		if(prd>e)
		prd%=e;
	}
	rep(i,1,7)
	{
		prd=(prd*modInverse(i,e))%e;
	}
	cout<<prd;
	return 0;
	
}
