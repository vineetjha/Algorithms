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
const ll inf = 2000000000;
ll a[1000005];
ll lon;
    
void find(ll x) 
{  
	ll l = 1, r = lon;
    while (l <= r) {
    
        ll mid = (l + r) >> 1;
        if (a[mid] <= x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    a[++r] = x;
    if (r > lon) {
        lon=r;
    }
}
    
int main()
{
	ll n;
    scanf("%lld",&n);
    for (ll i = 0; i <= n; ++i) {
        a[i] = inf;
    }
    lon= 0; 
    for (ll i = 1; i <= n; ++i) {        
        ll x;    
        scanf("%lld",&x);
        if ((x -= i) >= 0) {
            find(x);
            //cout<<x<<' ';
        }
    }
    //cout<<endl;
    //for(ll i=0;i<n;i++)
    //cout<<a[i]<<' ';
    //cout<<endl;
    printf("%lld\n", n - lon);
    return 0;
    
    
}
